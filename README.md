# Wireless-Network-of-Sensors

This is a simple Contiki application that broadcasts a message when a button is pressed on a node. It uses the Rime stack for wireless communication and the Contiki OS for event handling. 
This project was part of a course I did in my 8th semester.

## Prerequisites

To use the files in this repository, you will need the following:
1. A Contiki-compatible platform with a button sensor.
2. The Contiki OS installed on your system.


## Getting Started

To get started with this project, follow these steps:

1. Clone the repository or download the source code.
2. Navigate to the directory containing the source code.
3. Type make TARGET=your_platform to compile the code.
4. Connect your Contiki-compatible platform to your computer.
5. Upload the binary file to the platform using make TARGET=your_platform upload.
6. Run the application on the platform.
7. Press the button on one of the nodes to trigger the broadcast message.

## Contents

This repository contains the following files:
1. Makefile
2. app.c

## Specifications

### Functionality

This program is designed to enable communication between multiple nodes in a wireless network using Contiki OS. 
The program uses a button sensor on each node to trigger an event that sends a broadcast message to all nodes in the network. 
Each node receives the broadcast message and increments a counter to keep track of the number of messages received.

## Contributing

This is a university project so you can not contribute.

## Authors

* **[University of West Attica]** - *Provided the exersice*
* **[Achilleas Pappas]** - *Made the app*

## License

This project is licensed by University of West Attica as is a part of a university course. Do not redistribute.

## Acknowledgments

Thank you to **University of West Attica** and my professors for providing the resources and knowledge to complete this project.
