#include <IRremote.h>

const int IR_SEND_PIN = 3;

unsigned int rawSignal[] = {
  // Your recorded waveform durations
  9000, 4500, 560, 560, 560, 1690, 560, 560, 560, 1690, 560, 560, 560, 1690
  // Add the rest of your waveform
};
int rawSignalLength = sizeof(rawSignal) / sizeof(rawSignal[0]);

void setup() {
  Serial.begin(9600);
  IrSender.begin(IR_SEND_PIN);
  Serial.println("Ready to send raw IR");
}

void loop() {
  // Send the raw waveform
  IrSender.sendRaw(rawSignal, rawSignalLength, 38); // 38 kHz frequency
  Serial.println("IR signal sent");
  delay(5000);
}
