# Running FPrime_MSTAR on PYNQ-Z1/Z2

## PYNQ Introduction
PYNQ or Python Productivity for Zynq, is a project created by Xilinx and is a member of the Zynq class of devices. The Zynq architecture combines a dual-core ARM Cortex-A9 with a Field Programmable Gate Array (FPGA).PYNQ enables users to use the Python language and libraries to build electronic systems. Two boards which implement PYNQ are the PYNQ-Z1 and the PYNQ-Z2.

## FPrime Introduction
FPrime is a software framework designed and created by NASA's Jet Propulsion Laboratory. FPrime's design focuses on rapid deployment and development for space applications. FPrime is component-driven which allows universal components to be re-used on multiple projects thus reducing development time and costs.

## Project Goal
Our project seeks to depoloy FPrime to both the PYNQ-Z1 and PYNQ-Z2 board and run benchmark tests in order to record performance metrics by running both memory and computing intensive tests. To this end we have created FPrime components which perform array copy operations as well as calculate modular exponentiation.

## Requirements
- [PYNQ-Z1 or PYNQ-Z2 board](http://www.pynq.io/board.html)
- MicoSD card larger than 8GB
- USB to Micro-USB cable
- Ethernet cable
- [PuTTY](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html)
- [Rufus](https://rufus.ie/) or any other software to create bootable drives

## Setup
Follow these steps to setup your PYNQ-Z1/Z2 board with FPrime.
### Creating the bootable drive
Bootable images with Fprime pre-installed are provided for the PYNQ-Z1/Z2 boards at the following locations:

[PYNQ-Z1](https://drive.google.com/file/d/1YAkFanKYf6I-Awh9FplME5GzHEEdMyyc/view?usp=sharing)

[PYNQ-Z2](https://drive.google.com/file/d/1dgWHEQ1UevHf3aKtwjIwMHDAUY-g6zwE/view?usp=sharing)

Once your respective image file has finished downloading, connect a MicroSD card with a storage capacity of more than 8GB to your computer and format the SD card with the downloaded image.

![Format MicroSD](https://user-images.githubusercontent.com/9275528/110201002-bfab0000-7e15-11eb-9b4a-b2bfcd5d9900.PNG)

The image is made up of two partitions, a bootable partition and an operating system and storage partition. 

![Partitions](https://user-images.githubusercontent.com/9275528/110201173-95a60d80-7e16-11eb-94eb-84aaabfa6e68.PNG)

The first time the image is booted the storage partition will expand to occupy the remaining available space on the MicroSD card. Once the partition is expanded a RESIZED flag is added to a file located at etc/environment.

![Resized](https://user-images.githubusercontent.com/9275528/110201506-4c56bd80-7e18-11eb-8dff-66cd870b6f66.PNG)

The resize script can be found at file location:
> usr/local/bin/resizefs.sh

### Connecting to PuTTY

## Additional Resources
### FPrime
- [FPrime Github](https://github.com/nasa/fprime)
- [FPrime Website](https://nasa.github.io/fprime/)
- [FPrime Community Group](https://groups.google.com/g/fprime-community)

### PYNQ
- [PYNQ Github](https://github.com/xilinx/pynq)
- [PYNQ Website](http://www.pynq.io/)
- [PYNQ Setup Guide](https://pynq.readthedocs.io/en/latest/getting_started.html)
