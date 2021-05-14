---
permalink: /background/PYNQ/
---

## PYNQ
PYNQ is a project created by Xilinx and is a member of the Zynq class of devices. The Zynq architecture combines a dual-core ARM Cortex-A9 with a Field Programmable Gate Array (FPGA). PYNQ enables users to use the python language and libraries to build electronic systems. Two boards which implement PYNQ are the PYNQ-Z1 and the PYNQ-Z2. Each board allows the user to program the system on a chip to integrates both programmable logic level of an FPGA with the dual-core ARM Cortex™-A9 processor. Our project makes use of both the PYNQ-Z1/Z2 boards and benchmark data is taken for both boards to compare the results.

### PYNQ Bootable Images
Xilinx provides modified versions of Ubuntu 18.04 \{1\} which can be burned onto a microSD and booted on their respective PYNQ board. The provided image contains two partitions. The first smaller partition has a partition type of W95 FAT32 LBA Bootable and utilizes the FAT file system. This is the partition used when booting the PYNQ board to utilize modified version of Ubuntu.

The second partition takes up the rest of the available space on the drive. The size of this partition will change the first time the PYNQ board is booted and a RESIZED flag will be written to the Environment file stored in the etc folder. The partition type is Linux and utilized the Ext4 file system. A bootable image containing FPrime with each of the test components can be downloaded from the GitHub page linked through the QR code at the end of the paper.

\{1\}:
