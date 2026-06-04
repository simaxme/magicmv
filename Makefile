SOURCES = $(shell find src -type f -name "*.c" -printf "%p ")

all:
	mkdir -p ./out && gcc $(SOURCES)-o out/magicmv
