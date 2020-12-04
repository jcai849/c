CC = gcc
CFLAGS = -Wall -g
LDLIBS = -lm

progs := $(basename $(wildcard *.c))
.PHONY: all

all: $(progs)
