---
permalink: /experiments/
---

**WIP**


## Experiments
Both memory intensive and computationally intensive tasks were designed and executed on both the PYNQ-Z1 and PYNQ-Z2 board. Three tests were designed, an array copy test, an exponential modulation test, and a GAGE hash function test. The goal is to compare any performance differences between the boards and to benchmark any overhead from the FPrime framework.

### Memory Operation
In order test memory bandwidth custom array components were made to copy the serialized data at the receiver end. Our array copy method uses a one hundred size array containing 32 bit integers. The copy command is sent one hundred times and the resulting timing data is averaged to take relevant measurements such as execution time, copy time, etc. The copied array is then sent back to the sender as the result of the operation. This method tests our memory read and write speeds and analyze time taken.

#### Memory Benchmanrk

![Table1](https://user-images.githubusercontent.com/9275528/118407216-963bfb00-b634-11eb-9544-3cafb89360b9.PNG)

Computation time is defined as how long it takes for the receiver component to receive and output the copied data, Data transmission is the amount of time the data spends being sent through the port, and the Command execution time is how long it takes to get an output from the receiver after sending the initial command to the sender. The resulting analysis of the data with these definitions is shown in the table 1.

In Table 1, we observed that data computation time for the PYNQ-Z2 was 20.3% higher than it was for the Z1 board. Since the median values are significantly lower than the Z1's, The Z2 memory assignment time has high variance compared to the average value. The Z1 overall command execution is 69% faster given the variance and even has a median value that is only 10% lower compared to the 60\% lower Z2 median.
