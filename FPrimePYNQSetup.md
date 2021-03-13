# Running FPrime_MSTAR on PYNQ-Z1/Z2

[Video Walkthrough](https://drive.google.com/file/d/1WNCHOgCIJ6mEB0pbl5AY0Yh2j76HPpQH/view?usp=sharing)

## PYNQ Introduction
PYNQ or Python Productivity for Zynq, is a project created by Xilinx and is a member of the Zynq class of devices. The Zynq architecture combines a dual-core ARM Cortex-A9 with a Field Programmable Gate Array (FPGA). PYNQ enables users to use the Python language and libraries to build electronic systems. Two boards which implement PYNQ are the PYNQ-Z1 and the PYNQ-Z2.

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

[PYNQ-Z1](https://drive.google.com/file/d/1oSFLiyuEgIg-Y4KqXsf0uZ2Yt1L-2iae/view?usp=sharing)

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

PuTTY can be used to connect to the PYNQ-Z1/Z2 board in two ways.

If you connect a USB to Micro-USB cable to your computer you will be able to use a COM port to connect to your PYNQ board. First power on your board and wait for it to boot up. You will know that the board has booted when the LED light labeled DONE lights up. To find the correct COM port on Windows go to your Device Manager and look for the PYNQ board under the ports drop down option.

![Ports](https://user-images.githubusercontent.com/9275528/110284045-04f63b80-7f96-11eb-8452-b0d45f05ac9a.PNG) 

Once you find the correct COM port open PuTTY and select Serial from the menu on the left side. There you can change the settings to match the PYNQ board. The settings should be entered as follows
- Speed (baud): 115200
- Data bits: 8
- Stop bits: 1
- Parity: None
- Flow control: None

The correct settings are displayed below.

![PuTTYSettings](https://user-images.githubusercontent.com/9275528/110284743-10963200-7f97-11eb-9434-212b34db5e8a.PNG)

Press Open to open a terminal window. Press Enter once to initiate the login process. Both the username and password will be set to 'xilinx'.

To connect to your PYNQ board through an IP address your board will need to be connected to your network via an ethernet cable. Once the board has booted you can look for your board's IP address using an application such as [Advanced IP Scanner](https://www.advanced-ip-scanner.com/).

![AIPS](https://user-images.githubusercontent.com/9275528/110288511-f95a4300-7f9c-11eb-8851-e4ff4490c239.PNG)

You can now input this IP address into PuTTY as an SSH connection type.

![PuTTYIP](https://user-images.githubusercontent.com/9275528/110288615-2a3a7800-7f9d-11eb-9084-1b625e60197c.PNG)

Log into the board using 'xilinx' as both your username and password.

For more information about connecting to your PYNQ board please visit the Getting Started guide provided by Xilinx [here](https://pynq.readthedocs.io/en/v1.4/1_getting_started.html).

### Building FPrime

Once you have logged into your PYNQ-Z1/Z2 board you can navigate to the FPrime folder by running the following command:
> cd FPrime

You can now enter the python virtual environment by running the following command:
> . ./fprime-venv/bin/activate
 
Navigate to the Ref folder by running the following command:
> cd fprime/Ref/

FPrime can be built from the Ref folder by running:
> fprime-util build

![buildingFPrime](https://user-images.githubusercontent.com/9275528/110291692-08db8b00-7fa1-11eb-8741-80b3f0d8a5d9.PNG)

FPrime will now build. This may take a few minutes.

![BuildComplete](https://user-images.githubusercontent.com/9275528/110291896-4c35f980-7fa1-11eb-946b-5efbbb574392.PNG)

### Running FPrime

Running FPrime should be done with three terminals open. One terminal will be used to run the ground system, another terminal will be used to display the log outputs of any command that is run, the third terminal will be used to send commands to the ground system. Please make sure that you have enabled the virtual environment and are located in the fprime/Ref directory. Once you have built FPrime and have the three PuTTY sessions running you can start the ground system with the following command:

> fprime-gds --dictionary ../Ref/Top/RefTopologyAppDictionary.xml

![StartGDS](https://user-images.githubusercontent.com/9275528/110302938-aab5a480-7fae-11eb-9969-ca81cf9173c2.PNG)

Using the second terminal, run the following command to initialize the log:

> fprime-cli events --dictionary ../Ref/Top/RefTopologyAppDictionary.xml

![InitiateLog](https://user-images.githubusercontent.com/9275528/110303191-f10b0380-7fae-11eb-9130-c76c0fd08736.PNG)

Finally, the third terminal can be used to send commands to the GDS. In the following example we send an array copy command which will copy an array containing one-hundred thirty-two bit floating point valuesa specified amount of times. The command for the array copy is:

> fprime-cli command-send arrSender.AC_DO_ARR -args 10  --dictionary ../Ref/Top/RefTopologyAppDictionary.xml

Please note, the number ten in the command indicates that we are copying the array ten times. The log will now output timing data indicating when commands were recieved by both the recieving and sending components.

![LogOutput](https://user-images.githubusercontent.com/9275528/110304166-1a785f00-7fb0-11eb-8858-4fe788e8e766.PNG)

## Additional Resources
### FPrime
- [FPrime Github](https://github.com/nasa/fprime)
- [FPrime Website](https://nasa.github.io/fprime/)
- [FPrime Community Group](https://groups.google.com/g/fprime-community)

### PYNQ
- [PYNQ Github](https://github.com/xilinx/pynq)
- [PYNQ Website](http://www.pynq.io/)
- [PYNQ Setup Guide](https://pynq.readthedocs.io/en/latest/getting_started.html)
