
$(info $(shell mkdir -p bin))

all: usbreset

clean:
		rm bin/*

usbreset:
		gcc -std=gnu99 src/usbreset.c -lusb-1.0 -o bin/usbreset
