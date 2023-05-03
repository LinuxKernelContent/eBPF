## About

eBPF (Extended Berkeley Packet Filter) is a virtual machine that runs within the Linux kernel. It allows developers to create and run small programs (called "eBPF programs") that can be attached to various kernel objects, such as network sockets, kernel functions, or system calls. These programs can be used for a variety of purposes, such as tracing system events, filtering packets, or implementing custom network protocols.

eBPF was first introduced in Linux kernel version 3.18 and has since become an important part of the Linux networking and performance analysis stack. It provides a powerful and flexible way to inspect and modify kernel behavior without requiring any kernel modifications or kernel module loading. eBPF programs are written in a restricted subset of the C programming language and are compiled into bytecode that can be loaded into the kernel.

eBPF has become popular in recent years for its ability to provide observability and tracing capabilities for containers and microservices. It has been adopted by many cloud providers and is used in a variety of open-source and commercial monitoring and observability tools.
## Example use case of eBPF
Suppose you are debugging a performance issue in a production Linux server and you want to find out which processes are causing the highest CPU usage. You can use eBPF to write a simple program that attaches to the Linux scheduler and records the CPU usage of each running process.





















