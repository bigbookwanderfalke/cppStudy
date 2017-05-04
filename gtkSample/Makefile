
CONFIG=$(shell pkg-config --libs --cflags gtk+-3.0)
all:
	g++ test.cpp $(CONFIG)

clean:
	-rm a.out
