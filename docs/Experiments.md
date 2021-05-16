---
permalink: /experiments/
---

**WIP**


## Experiments
Both memory intensive and computationally intensive tasks were designed and executed on both the PYNQ-Z1 and PYNQ-Z2 board. Three tests were designed, an array copy test, an exponential modulation test, and a GAGE hash function test. The goal is to compare any performance differences between the boards and to benchmark any overhead from the FPrime framework.

### Memory Operation
In order test memory bandwidth custom array components were made to copy the serialized data at the receiver end. Our array copy method uses a one hundred size array containing 32 bit integers. The copy command is sent one hundred times and the resulting timing data is averaged to take relevant measurements such as execution time, copy time, etc. The copied array is then sent back to the sender as the result of the operation. This method tests our memory read and write speeds and analyze time taken.

#### Memory Benchmanrk

