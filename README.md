# NoobOS

A simple OS template for developers to get started with OS dev

## What does this do?

This is a simple and minimalistic implementation of a bootloader and a kernel to boot the OS from the disk, load the kernel, and indicate the same by printing a message on the screen.

## Purpose

If you want to learn more about OS dev but can't find any simple source on the same, then you can use this repository as a reference. Modern operating systems are much more complex compared to this implementation, so it is advisable to refer to other sources such as [OSdev Wiki](https://wiki.osdev.org/Main_Page) once you have a better understanding of OS dev

## Building the project

If your system needs to set file permissions for the build script, use the command below:

`chmod +x build.sh`

Once permissions are set, run the command below to compile the source files and boot the OS:

`./build.sh`

See **dependencies** for more info on required libraries and software installed

## Working Screenshot

<img src="screenshot/NoobOS.png" alt="NoobOS" />

## Dependencies

- QEMU
- gcc
- NASM
- WSL (Windows machines only)

## Pre-requisites

- Knowledge of C programming
- Basics of Assembly x86
- Basics of operating systems
- Registers and flags (x86 architecture)

## References

- [VGA text mode](https://en.wikipedia.org/wiki/VGA_text_mode)
- [Multiboot](https://www.gnu.org/software/grub/manual/multiboot/multiboot.html)
- [How does assembly bootloader code work?](https://stackoverflow.com/questions/34183799/how-does-this-assembly-bootloader-code-work)

## Alternative sources

- [OS tutorial by cfenollosa](https://github.com/cfenollosa/os-tutorial)

## Credits

- [Vineeth B V](https://github.com/vinsdragonis)
