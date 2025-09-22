// Pin connected to IR LED
const int irPin = 3;

// The data to send: 0xA0200001
uint32_t irData = 0xA0200001;

void setup() {
  pinMode(irPin, OUTPUT);
}

void loop() {
  sendNEC(irData);
  delay(5000); // Wait 5 seconds before sending again
}

// Function to send NEC protocol IR signal
void sendNEC(uint32_t data) {
  // Send leader code
  sendPulse(9000);   // 9ms pulse
  sendSpace(4500);   // 4.5ms space
  
  // Send 32 bits (LSB first)
  for (int i = 0; i < 32; i++) {
    sendPulse(560); // 560us pulse
    if (data & 0x1) {
      sendSpace(1690); // bit '1'
    } else {
      sendSpace(560);  // bit '0'
    }
    data >>= 1;
  }
  
  // Final pulse (stop bit)
  sendPulse(560);
  // No need for final space
}

// Function to send IR pulse
void sendPulse(int microseconds) {
  digitalWrite(irPin, HIGH);
  delayMicroseconds(microseconds);
  digitalWrite(irPin, LOW);
}

// Function to send IR space (no signal)
void sendSpace(int microseconds) {
  digitalWrite(irPin, LOW);
  delayMicroseconds(microseconds);
}
