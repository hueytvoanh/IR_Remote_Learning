const int IR_LED_PIN = 3;  // Change to your IR LED pin

// Timing constants in microseconds
const unsigned int HEADER_PULSE = 3180;
const unsigned int HEADER_SPACE = 9880;

const unsigned int BIT_PULSE = 560;
const unsigned int ONE_SPACE = 1572;
const unsigned int ZERO_SPACE = 532;

void setup() {
  pinMode(IR_LED_PIN, OUTPUT);
  digitalWrite(IR_LED_PIN, LOW);
}

void loop() {
  sendCustomIr(0x88C0051);
  delay(5000); // Wait 5 seconds before sending again
}

void sendPulse(unsigned int duration) {
  digitalWrite(IR_LED_PIN, HIGH);
  delayMicroseconds(duration);
  digitalWrite(IR_LED_PIN, LOW);
  delayMicroseconds(560); // Gap between pulses, typical at 560us
}

void sendSpace(unsigned int duration) {
  digitalWrite(IR_LED_PIN, LOW);
  delayMicroseconds(duration);
}

void sendCustomIr(unsigned long code) {
  // Send header
  sendPulse(HEADER_PULSE);
  sendSpace(HEADER_SPACE);

  // Send 24 bits of data (assuming 24-bit code)
  for (int i = 23; i >= 0; i--) {
    sendPulse(BIT_PULSE);
    if (code & (1UL << i)) {
      sendSpace(ONE_SPACE); // Bit '1'
    } else {
      sendSpace(ZERO_SPACE); // Bit '0'
    }
  }
}
