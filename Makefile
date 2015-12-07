CFILES := $(shell find src -name "*.c")

OBJFILES := $(CFILES:src/%.c=%)
OFILES := $(OBJFILES:%=obj/%.o)

BINFILE = bin/synacor

CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -pedantic

all: $(BINFILE)
   
$(BINFILE): $(OFILES)
	if [ ! -d `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CC) -o $@ $(OFILES)

obj/%.o: src/%.c
	if [ ! -d `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(BINFILE) obj/*