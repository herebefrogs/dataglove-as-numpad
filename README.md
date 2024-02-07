# Finger Numpad over Serial

Input numbers and backspace by connecting your thumbs to other fingers with the help of a wearable input device and an Arduino board. Inspired by Jeff Razon's mechanical 4-key numpad's experiment.
The wearable input device is a glove with conductive fabric at the tip of each finger, and wires linking the conductive fabric to pins on the Arduino board. The thumb is connected to the ground, and the other fingers to 4 digital pins. Connecting the thumb to a finger closes the circuit and changes the pin's voltage state. Some thumb/finger combinations are mapped as follow:

* INDEX_FINGER -> 1 
* MIDDLE_FINGER -> 2
* RING_FINGER -> 3
* LITTLE_FINGER -> 4
* INDEX_MIDDLE_FINGERS -> 5
* MIDDLE_RING_FINGERS -> 6
* RING_LITTLE_FINGERS -> 7
* INDEX_MIDDLE_RING_FINGERS -> 8
* MIDDLE_RING_LITTLE_FINGERS -> 9
* INDEX_MIDDLE_RING_LITTLE_FINGERS -> 0
* INDEX_RING_FINGERS -> Backspace

Other combinations are unused at the moment

## Getting started

1. Compile `arduino/sketch-fingernumpad.ino` to an Arduino board

1. Build the input device (see below) and wire it to the Arduino board

1. Run `npm install` to install all runtime and devtime dependencies

1. Run `npm run cli` to read inputs from the input device in command line

1. Run `npm run web` to read inputs from the input device in a browser

Notes:
- `npm run web` will only work in Chrome as it's the only browser having implemented the Web Serial API (which Mozilla and Apple consider a security risk for good reasons)
- Sketch tested on an Arduino Uno R3, but should work on any board supporting the Serial protocol (which should be the majority of boards out there)
- Serial could be replaced by Keyboard with minimal effort for boards supporting the Human-Device-Interface (HDI) protocol (Arduino Uno R4 Wifi & Minima, Arduino Leonardo, etc)

## Input device building instructions

TBD