CC = gcc
FLAGS = -g -O3 -Wall --std=gnu11
LINKOPTS = 

all: xurls

xurls: xurls.c xurls.h
	$(CC) $^ $(FLAGS) $(LINKOPTS) -o $@

.PHONY: clean
clean:
	rm  -f xurls
