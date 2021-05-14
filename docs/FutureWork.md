---
permalink: /futurework/
---

## Future Work
In the future we will aim to have similar tests implemented on the cFS framework to compare differences in performance metrics across the same hardware. We'd like to see which framework is best suited to support embedded systems.

The ability for FPrime to be used as an alternative to commercial drone software can be explored. This would extend current drone meshes to include secure communication to create autonomous movement, collision detection, or advanced team movements to accomplish a goal one drone could not.

Future projects can seek to implement input devices onto an FPGA board with the goal of communicating with FPrime Input devices may include a variety of sensors such as accelerometers, gyroscopes, image sensors, etc. It may also be beneficial to implement actuators for orientation for future implementation on CubeSats.

### Hardware Implementation
In addition to the working software GAGE implementation, the GAGE hash function can be implemented on the hardware layer of the PYNQ board to communicate with FPrime. A hardware implementation of GAGE can be built with the shared memory and an AXI bus architecture. The results of the hardware implementation of GAGE can then be compared to the software implementation. 

The GAGE function has been implemented in both C and VHDL. Two-way connection can be established between two PYNQ Z1/Z2 boards with both FPrime software and hardware implementations. This can provide a secured communication between components on separate devices. FPGAs which have an ARM processor like the PYNQ board can use hardware implementation. Software can be used for data pre-processing and hardware can be used to accelerate data processing and hashing.

Hardware implementation of GAGE involves two phases. The first phase decides what message will be sent. This phase can be done using a C or Python driver on the PYNQ board. A driver will pre-process the data and include padding the data. The data will then be stored into a streaming buffer with a physical address or a register for the hardware to access. The hardware will access the input data and send it into the GAGE hardware implementation. Once the data is hashed, it will be send back to the processor through a streaming buffer, or put onto a register for later processing.

The default frequency on PYNQ is 100MHz, and the frequency of GAGE to process data is about 6-8MHz. In order to establish the communication we will add a clocking wizard to generate the correct frequency for both PYNQ and GAGE.A FIFO can be used to feed data to GAGE to prevent data hazards. The data transfer between the ARM processor and GAGE is established with Master/Slave AXI interface.
