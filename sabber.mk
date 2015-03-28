# Compiler
#
CC = g++
#
# # Flags to the compiler

all: hw
hw: sabber.cpp
	${CC} sabber.cpp earthquake.cpp station.cpp inputoutput.cpp -o sabber

clean:
	rm -rf sabber
