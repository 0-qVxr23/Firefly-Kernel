# Firefly-Kernel
Kernel for FireflyOS which can be booted on UEFI and BIOS

## x64 demo:
![Firefly OS](docs/x64-progress.png)

### Clone the repo 
 * `git clone https://github.com/FireflyOS/Firefly-Kernel --recursive`
 * `cd Firefly-Kernel`

## Ubuntu 

```bash
sudo apt install meson ninja-build nasm xorriso qemu-system-x86 clang lld ovmf #For UEFI emulation only
```

Firefly OS uses the meson build system:
```bash
# Note: We invoke the meson build commands using regular Makefiles as a QoL improvement
make all run # Alternatively you can use 'make all uefi' for uefi emulation

# "I want to execute the build commands manually!" - Here you go:
make -C limine/
meson build --cross-file meson_config.txt # You *must* use build, other scripts depend on this directory name
cd build
meson compile && ../scripts/geniso.sh && ../scripts/qemu-bios.sh # If meson compile is not supported you can either upgrade meson or use ninja
```
Note: It is assumed you have meson version `0.60.1` or higher, you may or may not run into problems with older versions.
