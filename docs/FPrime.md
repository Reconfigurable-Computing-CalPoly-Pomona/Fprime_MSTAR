---
permalink: /background/FPrime/
---

## FPrime
FPrime is a component-driven framework that enables rapid development and deployment of spaceflight and other embedded software applications. Originally developed by NASA Jet Propulsion Laboratory, FPrime has been successfully deployed on several space applications. It is tailored but not limited to small-scale spaceflight systems such as CubeSats, SmallSats, and instruments. \{1\} Components developed for FPrime are reusable which allows for quick development and deployment on missions. Components are defined through clear xml templates to create custom features and connected through a defined topology. FPrime uses peer to peer connections for communication between components. FPrime is well documented with an active GitHub repository and a google group community.

### Types Of FPrime Components
Components are divided into 3 groups: Active, Passive, and Queued. Active components have their own dedicated thread to perform functions upon request. Passive components uses the thread of active components when called upon. Queued components have no dedicated thread but instead have a queue which is used to dedicate time to tasks when appropriate. 

In addition to differences in component types, there are also differences in port/connection types. The port types are output ports, synchronous ports, and asynchronous ports. The three component types are able to handle different port types. Active components need at least one asynchronous port to differentiate themselves from passive components but can handle all three connection types. Passive components support output ports and synchronous ports but do not support asynchronous port. Queued components must have at least one synchronous port and one asynchronous port. They can also utilize output ports.

### FPrime Development Environments
FPrime can be developed and run in a Linux environment with a graphical user interface or no graphical user interfaces. For the purposes of this project both development environments were utilized. The initial design work when creating a new component was often done in a graphical version of the Ubuntu operating system. This environment allowed for the usage of the graphical FPrime ground system which creates an easy and intuitive way of sending commands. The graphical ground system combines the ability to send commands and view logged events.

Development on the PYNQ boards was done by making use of multiple instances of PuTTY as well as the file sharing service Samba. The PuTTY instances would allow us to have terminal access to the PYNQ boards. From the terminals a non-graphical instance of the FPrime ground system could be instantiated. A second terminal could also be used to send commands to the ground system while yet another terminal could be used to view event logs containing both timing data and calculation results. Samba can be accessed from the windows file explorer allowing for developers to make use of the Windows OS environment. Much of the file editing performed in this project was done using Notepad++. The PYNQ boards run a modified version of Ubuntu 18.04.

### FPrime Component Development
FPrime utilizes xml files to assist in the creation of components. In an xml file the component type is specified and named and the ports, serializable types, and array types used within the component are imported. The xml file is also used to specify input and output ports, commands and their arguments, telemetry, and events and their arguments. Once the component has been detailed in full within the xml file a cpp file and a header file can be generated which will parse the xml file to provide a template.

The initial cpp file will contain a constructor and destructor as well as functions which handle the events defined in the xml file. The logic appropriate to the component can be added to the cpp file. 

This development process holds true regardless of the type of component being created but does contain some differences. Queued and active components will contain a function which initializes the queue to the specified size.

### FPrime Topology Development
Once components and ports have been specified and created components can be connected to each other through the topology folder. First the components must be specified in the components header file located in the top folder. The header of the component must be included and the component can then be given a name.

The topology xml file must include the xml file of the component being implemented. The component is then given a unique base id value. Connections between components can be specified by identifying the source port, message type, and target port. The type of the source and target should match.

The topology cpp file is used to initialize the components, register the commands, and exit the components when appropriate.

\{1\} https://github.com/nasa/fprime
