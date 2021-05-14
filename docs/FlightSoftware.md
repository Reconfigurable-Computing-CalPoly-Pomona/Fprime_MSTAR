---
permalink: /flightsoftware/
---

Our  project  investigates  aspects  of  flight  software  and  se-curity and seeks to implement security features onto flightsoftware frameworks.

## Flight Software
Flight software is commands for a system to follow and per-form necessary actions during a mission. These commandscan  either  be  sent  from  a  Ground  Control  System,  or  au-tonomously to maintain spacecraft functionality or stabilityduring all steps of flight. Flight Software operates as a realtime system that can not miss operations in within a fixed pe-riod of time. Otherwise the system would be unreliable andfail to respond correctly to collected environment data<sup>1</sup> . One of the goals of both cFS and FPrime is to allow mul-tiple missions with similar base hardware to use the samecoded  components.  This  allows  missions  to  save  develop-ment time in turn saving on development costs.

# Security
Most flight software do not have security systems incorpo-rated within the framework. System integrity is left to out-side networking protection and the security of the system it-self. Lightweight hash functions could be used as a workingencryption component to secure sensitive data moving be-tween nodes, to the ground system, or another craft in flight.

<sup>1</sup>: NASA. A Flight Software and Embedded Systems Framework.[Online] 2020. https://nasa.github.io/fprime/.
