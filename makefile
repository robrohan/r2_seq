CC:=clang
SED:=sed
BASE64:=base64 -i
# Linux
# BASE64=base64 -w 0
STACK_SIZE:=$$(( 8 * 1024 * 1024 ))

# Compiler and linker flags
CFLAGS:=-ggdb -O2 \
	-Wall -Wextra -Wpedantic \
	-Wformat=2 -Wno-unused-parameter -Wshadow \
	-Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
	-Wredundant-decls -Wnested-externs -Wmissing-include-dirs \
	-Wno-unused
WASMFLAGS:=--target=wasm32 -std=c99 \
	-nostdlib \
	-Os -flto \
	-Wl,--allow-undefined \
	-Wl,--export-dynamic \
	-Wl,--no-entry \
	-Wl,--lto-O3 \
	-Wl,--export-all \
	-Wl,-z,stack-size=$(STACK_SIZE) \
	-mbulk-memory
LDFLAGS:=-lm

# Source and target files
PLAIN_JS=js/pl_synth.js
PLAIN_JS_MIN=release/pl_synth.min.js

WASM_SRC=wasm/pl_synth_wasm_module.c
WASM_TARGET=wasm/pl_synth.wasm

WASM_TEMPLATE=wasm/pl_synth_wasm_template.js
WASM_JS_MIN=release/pl_synth_wasm.min.js

NATIVE_SRC=c/example.c c/pl_synth.h
NATIVE_BIN=c/example

.PHONY: all clean

all: $(WASM_JS_MIN) $(PLAIN_JS_MIN) $(NATIVE_BIN)

# Target: Minified plain JS version of pl_synth
$(PLAIN_JS_MIN): $(PLAIN_JS)
	cp $< $@
	cp tracker.html release/tracker.html

# Embed WASM module into JS
$(WASM_JS_MIN): $(WASM_TEMPLATE) $(WASM_TARGET)
	@ $(SED) "s|{{WASM_MODULE_EMBEDDED_HERE_AS_BASE64}}|$(shell $(BASE64) $(WASM_TARGET))|" $(WASM_TEMPLATE) > $@

# Compile the WASM module
$(WASM_TARGET): $(WASM_SRC)
	$(CC) $(CFLAGS) $(WASMFLAGS) -o $@ $<

# Target: Compiled native example
$(NATIVE_BIN): $(NATIVE_SRC)
	$(CC) $< $(CFLAGS) -o $@ $(LDFLAGS)

# Clean up generated files
clean:
	rm -f $(PLAIN_JS_MIN) $(WASM_TARGET) $(WASM_JS_MIN) $(NATIVE_BIN)
	rm -f release/tracker.html