# Data glove as numpad over Serial port

Input numbers and backspace by connecting your thumbs to other fingers with the help of a DIY data glove and an Arduino board. Inspired by Jeff Razon's mechanical 4-key numpad's experiment.

<img src="/images/Data%20glove%20as%20numpad.png" width="400" alt="Data glove as numpad">

<img src="/images/overview.jpg" width="600" alt="Data glove as numpad">

The data glove is made of a regular glove with conductive fabric ironed on at the tip of each finger, and wires linking the conductive fabric to pins on the Arduino board. The thumb is connected to the ground, and the other fingers to 4 digital pins. Touching a finger with the thumb closes the circuit and changes the pin's voltage state. All thumb/finger combinations are mapped as follow:

| fingers | keystroke |
|---------|-----------|
| index/pointer | 1 |
| middle | 2 |
| ring | 3 |
| little | 4 |
| index + middle | 5 |
| middle + ring | 6 |
| ring + little | 7 |
| index + middle + ring | 8 |
| middle + ring + little | 9 |
| index + middle + ring + little | 0 |
| index + ring | Backspace |
| middle + little | unused |
| index + little | unused |


## Getting started

1. Consult [the Bill of Material](/arduino/BOM.txt) for necessary hardware

1. Build the data glove and wire it to the Arduino board (see next sections)

1. Compile `arduino/sketch-fingernumpad.ino` to an Arduino board

1. Run `npm install` to install all runtime and devtime dependencies

1. Run `npm run cli` to read inputs from the data glove in command line

1. Run `npm run web` to read inputs from the data glove in a browser

Notes:
- `npm run web` will only work in Chrome as it's the only browser having implemented the Web Serial API (which Mozilla and Apple consider a security risk for good reasons)
- Sketch tested on an Arduino Uno R3, but should work on any board supporting the Serial protocol (which should be the majority of boards out there)
- Serial could be replaced by Keyboard with minimal effort for boards supporting the Human-Device-Interface (HDI) protocol (Arduino Uno R4 Wifi & Minima, Arduino Leonardo, etc)

## Repository overview
```
/
|- arduino/
|   |- sketch.ino                 -> Arduino sketch to flash the board with
|   |- BOM.txt                    -> Bill of Material for the microcontroller and data glove
|   |- circuit/schematic.png      -> instruction for wiring the microcontroller
|
|- cli/
|   |- serial.js                  -> NodeJS CLI program reading inputs from the data glove/Arduino on the Serial port
|                                    and logging them on the command line terminal
|- www/
|   |- index.html                 -> web page reading inputs from the data glove/Arduino from the Serial port with the
|                                    Web Serial API (Chrome only) and logging them inside the web page
|- images/
    |- build instructions.png     -> instructions for building the data glove
    |- *.png/jpg/mp4              -> step by step reference pictures
```

## Data glove build instructions

1. Cut two 0.5in x 1in pieces of conductive fabric (index and little fingers) and three 0.5in x 1.5in pieces (thumb, middle and ring fingers). Adapt dimensions to your own hand size.

1. Cut 2 holes in each piece, about 0.25in apart. Expose 0.75in of wire, slide it through the holes starting and finishing on the iron-on side of the fabric. Bent the tip so the wire doesn't move.

1. Pour 2 drops of glue onto the holes on the iron-on side of the fabric to secure the wires in place. You can also attempt to solder the wire on the conductive fabric side, but high temperature may melt the fabric (been there, done that) so practice first on a scrap of fabric.

1. Iron on (or glue, but that's less flexible once the glue cooled) the conductive fabric to each finger tip. The fabric should wrap around the thumb, middle and ring fingers. The little finger just need to be half covered on the ring finger side. Same with the index, but on the middle finger side. 

<img src="/images/build%20instructions.jpg" width="400">

## Wiring instructions

Note: in both diagrams, push buttons stand in the conductive fabric around each finger of the data glove.

### Circuit
<img src="/arduino/Circuit%20layout.png" width="600" alt="Circuit">

### Schematic
<img src="/arduino/Schematic.png" width="600" alt="Schematic">
