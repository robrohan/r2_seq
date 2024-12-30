CC=clang
TERSER=terser
SED=sed
BASE64=base64

# Compiler and linker flags
CFLAGS=-O3
WASMFLAGS=--target=wasm32 -nostdlib -Wl,--no-entry -Wl,--export-all -mbulk-memory
LDFLAGS=-lm

# Source and target files
PLAIN_JS=js/pl_synth.js
PLAIN_JS_MIN=release/pl_synth.min.js
WASM_SRC=wasm/pl_synth_wasm_module.c
WASM_TARGET=wasm/pl_synth.wasm
WASM_TEMPLATE=wasm/pl_synth_wasm_template.js
WASM_JS=wasm/pl_synth_wasm.js
WASM_JS_MIN=release/pl_synth_wasm.min.js
NATIVE_SRC=c/example.c c/pl_synth.h
NATIVE_BIN=c/example

.PHONY: all clean

all: $(PLAIN_JS_MIN) $(WASM_JS_MIN) $(NATIVE_BIN)

# Target: Minified plain JS version of pl_synth
$(PLAIN_JS_MIN): $(PLAIN_JS)
	$(TERSER) $< -c -m -o $@

# Target: Minified JS + WASM version of pl_synth
$(WASM_JS_MIN): $(WASM_JS)
	$(TERSER) $< -c -m -o $@

# Embed WASM module into JS
$(WASM_JS): $(WASM_TEMPLATE) $(WASM_TARGET)
	$(SED) "s|{{WASM_MODULE_EMBEDDED_HERE_AS_BASE64}}|$(shell $(BASE64) -w 0 $(WASM_TARGET))|" $(WASM_TEMPLATE) > $@

# Compile the WASM module
$(WASM_TARGET): $(WASM_SRC)
	$(CC) $(CFLAGS) $(WASMFLAGS) -o $@ $<

# Target: Compiled native example
$(NATIVE_BIN): $(NATIVE_SRC)
	$(CC) $< $(CFLAGS) $(LDFLAGS) -o $@

# Clean up generated files
clean:
	rm -f $(PLAIN_JS_MIN) $(WASM_TARGET) $(WASM_JS) $(WASM_JS_MIN) $(NATIVE_BIN)