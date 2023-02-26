#include <linux/bpf.h>
#include <linux/sched.h>

struct bpf_map_def SEC("maps") cpu_usage = {
    .type = BPF_MAP_TYPE_HASH,
    .key_size = sizeof(u32),
    .value_size = sizeof(u64),
    .max_entries = 1024,
};

SEC("tracepoint/sched/sched_stat_runtime")
int trace_sched_stat_runtime(struct pt_regs *ctx) {
    struct task_struct *task = (struct task_struct *)bpf_get_current_task();
    u64 *val = bpf_map_lookup_elem(&cpu_usage, &task->pid);
    if (val) {
        (*val) += PT_REGS_RC(ctx);
    } else {
        u64 usage = PT_REGS_RC(ctx);
        bpf_map_update_elem(&cpu_usage, &task->pid, &usage, BPF_ANY);
    }
    return 0;
}
