CC=clang
CFLAGS=-O2 -target bpf
XDP_OBJ=xdp_program.o
BENCHMARK_OBJ=benchmark.o
XDP_PROG=xdp_program.c
BENCHMARK_PROG=benchmark.c
IFACE=enp0s3

.PHONY: all xdp benchmark load_xdp clean

all: xdp benchmark

xdp: $(XDP_OBJ)

$(XDP_OBJ): $(XDP_PROG)
	$(CC) $(CFLAGS) -c $(XDP_PROG) -o $(XDP_OBJ)

benchmark: $(BENCHMARK_OBJ)

$(BENCHMARK_OBJ): $(BENCHMARK_PROG)
	gcc $(BENCHMARK_PROG) -o $(BENCHMARK_OBJ)

load_xdp: xdp
	ip link set dev $(IFACE) xdp obj $(XDP_OBJ) sec xdp_count

clean:
	rm -f $(XDP_OBJ) $(BENCHMARK_OBJ) benchmark
