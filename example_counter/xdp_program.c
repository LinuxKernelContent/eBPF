#include <linux/bpf.h>
#include <linux/pkt_cls.h>

struct bpf_map_def {
    __u32 type;
    __u32 key_size;
    __u32 value_size;
    __u32 max_entries;
};

// Define SEC macro if it's not defined elsewhere
#ifndef SEC
#define SEC(NAME) __attribute__((section(NAME), used))
#endif

struct bpf_map_def SEC("maps") pkt_count_map = {
    .type = BPF_MAP_TYPE_ARRAY,
    .key_size = sizeof(__u32),
    .value_size = sizeof(__u64),
    .max_entries = 1,
};

__u32 key = 0;

SEC("xdp_count")
int xdp_count_func(struct xdp_md *ctx) {
    // Increment packet counter

    return XDP_PASS;
}
