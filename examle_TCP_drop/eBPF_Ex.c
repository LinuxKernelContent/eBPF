/*eBPF (extended Berkeley Packet Filter) is a technology that 
 * allows you to write and load custom programs into the Linux kernel to perform 
 * various network-related tasks, such as packet filtering, monitoring, and tracing. 
 * Here's an example of a simple eBPF program and how to load it 
 * using the bpftool command-line utility:
 * filename: my_ebpf_program.c
*/

#include <linux/bpf.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
#include <linux/in.h>

SEC("filter")
int filter(struct __sk_buff *skb) {
    struct ethhdr *eth = bpf_hdr_pointer(skb);
    struct iphdr *ip = (struct iphdr *)(eth + 1);

    if (ip->protocol == IPPROTO_TCP && ip->daddr == htonl(INADDR_LOOPBACK)) {
        return XDP_DROP;
    }

    return XDP_PASS;
}
