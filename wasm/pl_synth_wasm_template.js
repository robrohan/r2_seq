/*

Copyright (c) 2024, Dominic Szablewski - https://phoboslab.org
SPDX-License-Identifier: MIT

Based on Sonant, published under the Creative Commons Public License
(c) 2008-2009 Jake Taylor [ Ferris / Youth Uprising ]

*/

let pl_synth_wasm_init = (ctx, callback) => {
	let
	samplerate = 44100,

	wasm = null,
	wasm_page_size = 64 * 1024,
	wasm_mem_base = 0,
	wasm_source = '{{WASM_MODULE_EMBEDDED_HERE_AS_BASE64}}',

	alloc = (num_samples) => {
		// Ensures the WASM instance has enough memory for backing two channels
		// of num_samples of audio data. This "overwrites" previously allocated
		// Float32Arrays, if any.
		let req_size = wasm_mem_base + num_samples * 2 * 4;
		let req_pages = Math.ceil(req_size / wasm_page_size);
		let pages = Math.ceil(wasm.memory.buffer.byteLength / wasm_page_size);
		if (req_pages > pages) {
			wasm.memory.grow(req_pages - pages);
		}
		return [
			new Float32Array(wasm.memory.buffer, wasm_mem_base,                   num_samples),
			new Float32Array(wasm.memory.buffer, wasm_mem_base + num_samples * 4, num_samples)
		];
	},

	unundefine = (data) => {
		for (let i = 0; i < data.length; i++) {
			data[i] = Array.isArray(data[i]) ? unundefine(data[i]) : (data[i] ?? 0);
		}
		return data;
	},

	instrumentLen = (instrument, row_len) => {
		let delay_shift = (instrument[20/*fx_delay_time*/] * row_len) >> 1,
			delay_amount = instrument[21/*fx_delay_amt*/] / 255,
			delay_iter = Math.ceil(Math.log(0.1) / Math.log(delay_amount));
		return instrument[13/*env_attack*/] +
			instrument[14/*env.sustain*/] +
			instrument[15/*env.release*/] +
			delay_iter * delay_shift;
	},

	apply_delay = (left, right, row_len, instrument) => {
		let
			delay_shift = (instrument[20/*fx_delay_time*/] * row_len) >> 1,
			delay_amount = instrument[21/*fx_delay_amt*/] / 255;
		if (delay_amount) {
			wasm.delay(left.byteOffset, right.byteOffset, left.length, delay_shift, delay_amount);
		}
	},

	sound = (instrument, note = 147 /* C-5 */, row_len = 5513 /* 120 BPM */) => {
		// "note" is now a midi message, and we need to translate that
		// to whatever this needs...  147 == C, midi == 60
		note += 87;
		instrument = unundefine(instrument);

		let
			num_samples = instrumentLen(instrument, row_len),
			audio_buffer = ctx.createBuffer(2, num_samples, samplerate),
			sound_left = audio_buffer.getChannelData(0),
			sound_right = audio_buffer.getChannelData(1),
			[left, right] = alloc(num_samples);

		wasm.clear(left.byteOffset, left.length);
		wasm.clear(right.byteOffset, right.length);

		wasm.gen(left.byteOffset, right.byteOffset, 0, row_len, note, ...instrument);
		apply_delay(left, right, row_len, instrument);

		sound_left.set(left);
		sound_right.set(right);

		return audio_buffer;
	},

	song = (songData, seqlen=16) => {
		songData = unundefine(songData);

		let
			row_len = songData[0/*row_len*/],
			tracks = songData[1/*track*/],
			num_samples = 0;

		// console.log("song: ", songData);
		// console.log("tracks: ", songData[1]);

		for (let track of tracks) {
			let track_samples = track[1/*sequence*/].length * row_len * seqlen + instrumentLen(track[0/*instrument*/], row_len);
			if (track_samples > num_samples) {
				num_samples = track_samples;
			}
		}

		let
			audio_buffer = ctx.createBuffer(2, num_samples, samplerate),
			song_left = audio_buffer.getChannelData(0),
			song_right = audio_buffer.getChannelData(1),
			[left, right] = alloc(num_samples);

		for (let track of tracks) {
			let
				instrument = track[0/*instrument*/],
				sequence = track[1/*sequence*/],
				write_pos = 0,
				first = num_samples;

			wasm.clear(left.byteOffset, left.length);
			wasm.clear(right.byteOffset, right.length);

			for (let pi of sequence) {
				// console.log("pattern:", pi, track);
				for (let row = 0; row < seqlen; row++) {
					// these notes will be in midi format (60==C)
					let note = track[2/*patterns*/][pi-1]?.[row];
					note += 87;
					// console.log("\t", row, note);
					if (note) {
						first = Math.min(first, write_pos);
						wasm.gen(left.byteOffset, right.byteOffset, write_pos, row_len, note, ...instrument);
					}
					write_pos += row_len;
				}
			}

			apply_delay(left, right, row_len, instrument);

			for (let i = first; i < num_samples; i++) {
				song_left[i] += left[i];
				song_right[i] += right[i];
			}
		}
		return audio_buffer;
	};

	let wasm_bin = atob(wasm_source);
	let wasm_bytes = new Uint8Array(wasm_bin.length);
	for (let i = 0; i < wasm_bin.length; i++) {
		wasm_bytes[i] = wasm_bin.charCodeAt(i);
	}

	WebAssembly.instantiate(wasm_bytes, {env: {pow: Math.pow, sin: Math.sin}}).then(r => {
		wasm = r.instance.exports;
		wasm.init();
		wasm_mem_base = wasm.memory.buffer.byteLength;
		callback && callback({sound, song});
	});
};
