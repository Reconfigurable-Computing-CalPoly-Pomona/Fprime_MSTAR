---
permalink: /flightsoftware/
---

Our  project  investigates  aspects  of  flight  software  and  security and seeks to implement security features onto flight software frameworks.

## Flight Software
Flight software is commands for a system to follow and perform necessary actions during a mission. These commands can  either  be  sent  from  a  Ground  Control  System,  or  autonomously to maintain spacecraft functionality or stability during all steps of flight. Flight Software operates as a realtime system that can not miss operations in within a fixed period of time. Otherwise the system would be unreliable and fail to respond correctly to collected environment data. \{1\} One of the goals of both cFS and FPrime is to allow multiple missions with similar base hardware to use the same coded  components.  This  allows  missions  to  save  development time in turn saving on development costs.

### Security
Most flight software do not have security systems incorporated within the framework. System integrity is left to outside networking protection and the security of the system itself. Lightweight hash functions could be used as a working encryption component to secure sensitive data moving between nodes, to the ground system, or another craft in flight.

\{1\}: NASA. A Flight Software and Embedded Systems Framework.[Online] 2020. https://nasa.github.io/fprime/.
