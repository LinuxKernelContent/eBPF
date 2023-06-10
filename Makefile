# Makefile

PROGRAM_NAME := /home/guydavidi/projects/eBPF/eBPF_Ex
OBJECT_FILE := eBPF_Ex.o
SOURCE_FILE := /home/guydavidi/projects/eBPF/eBPF_Ex.c

.PHONY: all compile load attach clean

all: attach

compile: $(OBJECT_FILE)

$(OBJECT_FILE): $(SOURCE_FILE)
	clang -O2 -target bpf -c $(SOURCE_FILE) -o $(OBJECT_FILE)

load: compile
	bpftool prog load $(OBJECT_FILE) $(PROGRAM_NAME)

attach: load
	bpftool prog attach $(PROGRAM_NAME) dev eth0

clean:
	rm -f $(OBJECT_FILE)
