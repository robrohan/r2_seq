/*

Copyright (c) 2024, Dominic Szablewski - https://phoboslab.org
SPDX-License-Identifier: MIT

Based on Sonant, published under the Creative Commons Public License
(c) 2008-2009 Jake Taylor [ Ferris / Youth Uprising ]

*/

#include <stdint.h>

#define PL_SYNTH_SAMPLERATE 44100
#define PL_SYNTH_TAB_LEN 4096
#define PL_SYNTH_TAB_MASK (PL_SYNTH_TAB_LEN-1)
#define PL_SYNTH_TAB(WAVEFORM, K) tab[WAVEFORM][((int)((K) * PL_SYNTH_TAB_LEN)) & PL_SYNTH_TAB_MASK]

static uint32_t rand_state = 0xd8f554a5;
static float tab[4][PL_SYNTH_TAB_LEN];

extern float __attribute__((import_module("env"), import_name("sin")))
js_sinf(float v);

extern float __attribute__((import_module("env"), import_name("pow")))
js_powf(float base, float exp);

static inline float note_freq(int n, int oct, int semi, int detune) {
	return (0.00390625 * js_powf(1.059463094, n - 128 + (oct - 8) * 12 + semi)) * (1.0f + 0.0008f * detune);
}

void init(void) {
	for (int i = 0; i < PL_SYNTH_TAB_LEN; i++) {
		tab[0][i] = js_sinf(i*(float)(6.283184/PL_SYNTH_TAB_LEN));
		tab[1][i] = tab[0][i] < 0 ? -1 : 1;
		tab[2][i] = (float)i / PL_SYNTH_TAB_LEN - 0.5;
		tab[3][i] = i < PL_SYNTH_TAB_LEN/2
			? (i/(PL_SYNTH_TAB_LEN/4.0)) - 1.0
			: 3.0 - (i/(PL_SYNTH_TAB_LEN/4.0));
	}
}

void gen(
	float *samples_l,
	float *samples_r,
	int write_pos,

	int row_len,
	uint8_t note,

	uint8_t osc0_oct,
	uint8_t osc0_det,
	uint8_t osc0_detune,
	uint8_t osc0_xenv,
	uint8_t osc0_vol,
	uint8_t osc0_waveform,

	uint8_t osc1_oct,
	uint8_t osc1_det,
	uint8_t osc1_detune,
	uint8_t osc1_xenv,
	uint8_t osc1_vol,
	uint8_t osc1_waveform,

	uint8_t noise_fader,

	uint32_t env_attack,
	uint32_t env_sustain,
	uint32_t env_release,
	uint32_t env_master,

	uint8_t fx_filter,
	uint32_t fx_freq,
	uint8_t fx_resonance_p,
	uint8_t fx_delay_time,
	uint8_t fx_delay_amt,
	uint8_t fx_pan_freq_p,
	uint8_t fx_pan_amt_p,

	uint8_t lfo_osc0_freq,
	uint8_t lfo_fx_freq,
	uint8_t lfo_freq_p,
	uint8_t lfo_amt_p,
	uint8_t lfo_waveform
) {
	float fx_pan_freq = js_powf(2, fx_pan_freq_p - 8) / row_len;
	float lfo_freq = js_powf(2, lfo_freq_p - 8) / row_len;

	// We need higher precision here, because the oscilator positions may be
	// advanced by tiny values and error accumulates over time
	double osc0_pos = 0;
	double osc1_pos = 0;

	float fx_resonance = fx_resonance_p / 255.0f;
	float noise_vol = noise_fader * 4.6566129e-010f;
	float low = 0;
	float band = 0;
	float high = 0;

	float inv_attack = 1.0f / env_attack;
	float inv_release = 1.0f / env_release;
	float lfo_amt = lfo_amt_p / 512.0f;
	float pan_amt = fx_pan_amt_p / 512.0f;

	float osc0_freq = note_freq(note, osc0_oct, osc0_det, osc0_detune);
	float osc1_freq = note_freq(note, osc1_oct, osc1_det, osc1_detune);

	int num_samples = env_attack + env_sustain + env_release - 1;

	for (int j = num_samples; j >= 0; j--) {
		int k = j + write_pos;

		// LFO
		float lfor = PL_SYNTH_TAB(lfo_waveform, k * lfo_freq) * lfo_amt + 0.5f;

		float sample = 0;
		float filter_f = fx_freq;
		float temp_f;
		float envelope = 1;

		// Envelope
		if ((uint32_t)j < env_attack) {
			envelope = (float)j * inv_attack;
		}
		else if ((uint32_t)j >= env_attack + env_sustain) {
			envelope -= (float)(j - env_attack - env_sustain) * inv_release;
		}

		// Oscillator 1
		temp_f = osc0_freq;
		if (lfo_osc0_freq) {
			temp_f *= lfor;
		}
		if (osc0_xenv) {
			temp_f *= envelope * envelope;
		}
		osc0_pos += temp_f;
		sample += PL_SYNTH_TAB(osc0_waveform, osc0_pos) * osc0_vol;

		// Oscillator 2
		temp_f = osc1_freq;
		if (osc1_xenv) {
			temp_f *= envelope * envelope;
		}
		osc1_pos += temp_f;
		sample += PL_SYNTH_TAB(osc1_waveform, osc1_pos) * osc1_vol;

		// Noise oscillator
		if (noise_vol) {
			int32_t r = (int32_t)rand_state;
			sample += (float)r * noise_vol * envelope;
			rand_state ^= rand_state << 13;
			rand_state ^= rand_state >> 17;
			rand_state ^= rand_state << 5;
		}

		sample *= envelope * (1.0f / 255.0f);

		// State variable filter
		if (fx_filter) {
			if (lfo_fx_freq) {
				filter_f *= lfor;
			}

			filter_f = PL_SYNTH_TAB(0, filter_f * (0.5f / PL_SYNTH_SAMPLERATE)) * 1.5f;
			low += filter_f * band;
			high = fx_resonance * (sample - band) - low;
			band += filter_f * high;
			sample = (float[5]){sample, high, low, band, low + high}[fx_filter];
		}

		// Panning & master volume
		temp_f = PL_SYNTH_TAB(0, k * fx_pan_freq) * pan_amt + 0.5f;
		sample *= 0.00238f * env_master;

		samples_l[k] += (sample * (1-temp_f));
		samples_r[k] += (sample * temp_f);
	}
}

void clear(float *samples, int len) {
	for (int i = 0; i < len; i++) {
		samples[i] = 0;
	}
}

void delay(float *samples_l, float *samples_r, int len, int shift, float amount) {
	for (int i = 0, j = shift; j < len; i ++, j ++) {
		samples_l[j] += samples_r[i] * amount;
		samples_r[j] += samples_l[i] * amount;
	}
}
