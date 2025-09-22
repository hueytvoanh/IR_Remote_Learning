const int irPin = 9; // Set your IR LED pin here

void setup() {
  pinMode(irPin, OUTPUT);
  // Call your send function here
  sendCustomIRData(0xA0200001);
}

void loop() {
  // Repeat or add delay as needed
}

// Function to send your custom IR data matching your raw data timings
void sendCustomIRData(uint32_t data) {
  // Send header (leader) mark
  sendPulse(3180);
  sendSpace(9928);
  
  // Send 32 bits
  for (int i = 0; i < 32; i++) {
    sendPulse(560); // pulse for each bit
    if (data & 0x1) {
      sendSpace(1690); // bit '1'
    } else {
      sendSpace(560);  // bit '0'
    }
    data >>= 1; // shift to next bit
  }

  // Send final pulse
  sendPulse(560);
  // Optional: add a delay here if needed
}

// Helper functions to send pulse and space
void sendPulse(int microseconds) {
  digitalWrite(irPin, HIGH);
  delayMicroseconds(microseconds);
  digitalWrite(irPin, LOW);
}

void sendSpace(int microseconds) {
  digitalWrite(irPin, LOW);
  delayMicroseconds(microseconds);
}
