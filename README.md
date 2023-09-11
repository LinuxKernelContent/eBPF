## About
eBPF (Extended Berkeley Packet Filter) is a virtual machine that runs within the Linux kernel.
1. Install required dependencies:
```
sudo apt-get install build-essential cmake bison flex libedit-dev zlib1g-dev libllvm13 llvm-13-dev libclang-13-dev python3-distutils
```
2. Clone the 'bcc' repository
```
git clone https://github.com/iovisor/bcc.git
```
3. Build and install 'bcc':
```
cd bcc
mkdir build
cd build
cmake ..
make
sudo make install
```
4. Verify installation
```
python3 -c "import bcc"
```
run as sudoer:
```
sudu su
python3 opensnoop.py
```
