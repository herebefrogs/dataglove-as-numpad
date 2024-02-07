// Define the digital pins used for input
const byte INDEX_PIN = 8;
const byte MIDDLE_PIN = 9;
const byte RING_PIN = 10;
const byte LITTLE_PIN = 11;
// Thumb pin will be represented by ground

// Define the possible finger binary combinations
const byte INDEX_FINGER = 1;
const byte MIDDLE_FINGER = 2;
const byte RING_FINGER = 4;
const byte LITTLE_FINGER = 8;
const byte INDEX_MIDDLE_FINGERS = 3;
const byte MIDDLE_RING_FINGERS = 6;
const byte RING_LITTLE_FINGERS = 12;
const byte INDEX_MIDDLE_RING_FINGERS = 7;
const byte MIDDLE_RING_LITTLE_FINGERS = 14;
const byte INDEX_MIDDLE_RING_LITTLE_FINGERS = 15;
const byte INDEX_RING_FINGERS = 5;

// const short REPEAT_TIME = 250;

void setup() {
  // Initialize the input pins
  // Onboard pullup resistors help us simplify the wiring (no need for external
  // pulldown resistors nor an extra wire for each finger connecting them to
  // the ground & thumb would be connected to +5V) at the cost of reverse values
  pinMode(INDEX_PIN, INPUT_PULLUP);
  pinMode(MIDDLE_PIN, INPUT_PULLUP);
  pinMode(RING_PIN, INPUT_PULLUP);
  pinMode(LITTLE_PIN, INPUT_PULLUP);

  // Begin serial communication at a baud rate of 9600
  Serial.begin(9600);
}

void loop() {
  static char pressedKey = 0;
  // static unsigned long pressedTime = 0;

  // Read the state of the input pins
  // Inverse the PULLUP value (HIGH for open circuit, LOW for closed circuit)
  // to go back to regular INPUT logic (HIGH for thumb connecting with a finger)
  byte indexState = !digitalRead(INDEX_PIN);
  byte middleState = !digitalRead(MIDDLE_PIN);
  byte ringState = !digitalRead(RING_PIN);
  byte littleState = !digitalRead(LITTLE_PIN);

  // Combine the finger states into a single binary number
  byte fingers = (littleState << 3) | (ringState << 2) |
                 (middleState << 1) | indexState;

  // Map the finger combination to an ASCII char
  char key = mapFingersToASCII(fingers);

  // Any key pressed?
  if (key > 0) {
    // TODO multi-finger combinations are going to detach 1 finger at a time
    // and will be immediately seen as another key press. (e.g. backspace
    // --- a 2 finger combination --- remove the last char, but as soon as
    // 1 finger is off, leaving one connected, it's another number input)
    // it should be debounced for a low number of cycle (empirical value
    // at the limit of lag)
    if (key != pressedKey) {
      pressedKey = key;
      // pressedTime = millis();
      Serial.write(key);
    }
  } else {
    pressedKey = 0;
  }

  // Small delay to debounce and prevent reading too fast
  delay(10);
}

char mapFingersToASCII(byte fingers) {
  switch (fingers) {
    case INDEX_FINGER:
      return '1'; 
    case MIDDLE_FINGER:
      return '2';
    case RING_FINGER:
      return '3';
    case LITTLE_FINGER:
      return '4';
    case INDEX_MIDDLE_FINGERS:
      return '5';
    case MIDDLE_RING_FINGERS:
      return '6';
    case RING_LITTLE_FINGERS:
      return '7';
    case INDEX_MIDDLE_RING_FINGERS:
      return '8';
    case MIDDLE_RING_LITTLE_FINGERS:
      return '9';
    case INDEX_MIDDLE_RING_LITTLE_FINGERS:
      return '0';
    case INDEX_RING_FINGERS:
      return 8; // BACKSPACE  
    // unused combination or no fingers 
    default:
      return 0; // NULL
  }
}
