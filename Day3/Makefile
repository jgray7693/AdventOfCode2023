CC = g++	# use g++ for compiling c++ code
CFLAGS = -g -Wall -std=c++11		# compilation flags: -g for debugging. Change to -O or -O2 for optimized code.

all: test
SRCS = Gears.cpp
DEPS = $(SRCS:.cpp=.d)

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

test: Gears.o
	$(CC) Gears.o -o Gears
	
clean:
	rm *.o Gears