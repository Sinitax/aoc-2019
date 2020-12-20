CFLAGS = -I include
LDLIBS = 

all: build/libaoc.a

build:
	mkdir build

build/util.o: src/util.c | build
	$(CC) -c -o $@ $^ $(CFLAGS) $(LDLIBS)

build/libaoc.a: build/util.o
	ar rcs $@ $^
