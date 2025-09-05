#include <IRremote.h>

IRsend irsend;

void setup() {
  // Initialize IR sender
  irsend.begin();
}

void loop() {
  // Raw timing data in microseconds
  uint16_t rawData[] = {
    3150, 9770, 480, 1570, 530, 520, 480, 520, 480, 520,
    530, 1570, 430, 570, 530, 520, 530, 520, 480, 520,
    480, 520, 530, 520, 480, 520, 480, 1620, 430, 570,
    480, 520, 480, 570, 480, 1570, 480, 1570, 480, 1570,
    480, 1570, 480, 520, 530, 1570, 430, 570, 480, 1570,
    530, 1520, 530, 1570, 430, 570, 480, 520, 480
  };
  const int dataSize = sizeof(rawData) / sizeof(rawData[0]);

  // Send the raw data with 38kHz frequency
  irsend.sendPulseDistanceWidth(
    38000, // Carrier frequency in Hz
    rawData, 
    dataSize,
    0 // Number of repeats
  );

  delay(5000); // Wait 5 seconds before sending again
}


/*
#include <IRremote.h>

IRsend irsend;

void setup() {
  irsend.begin();
}

void loop() {
  uint16_t rawData[] = {
    3150, 9770, 480, 1570, 530, 520, 480, 520, 480, 520,
    530, 1570, 430, 570, 530, 520, 530, 520, 480, 520,
    480, 520, 530, 520, 480, 520, 480, 1620, 430, 570,
    480, 520, 480, 570, 480, 1570, 480, 1570, 480, 1570,
    480, 1570, 480, 520, 530, 1570, 430, 570, 480, 1570,
    530, 1520, 530, 1570, 430, 570, 480, 520, 480
  };

  const int dataSize = sizeof(rawData) / sizeof(rawData[0]);

  irsend.sendPulseDistanceWidth(38000, rawData, dataSize, 0);
  
  delay(10000); // Wait before re-sending
}
*/
