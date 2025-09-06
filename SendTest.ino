#include <IRremote.h>

// Pin where IR LED is connected
const int IR_SEND_PIN = 3;

// Initialize IRsend object
IRsend irsend(IR_SEND_PIN);

void setup() {
  irsend.begin();
}

void loop() {
  // Raw data array: durations in microseconds
  // Positive values indicate mark (LED ON), negative values indicate space (LED OFF)
  unsigned int rawData[] = {
    3144, -9900, 512, -1592, 484, -536, 504, -528, 504, -528,
    508, -1596, 484, -536, 504, -536, 504, -528, 508, -1576,
    504, -1568, 504, -528, 508, -524, 508, -524, 512, -520,
    508, -528, 504, -528, 504, -528, 508, -524, 508, -528,
    504, -528, 504, -528, 504, -1596, 488, -524, 508, -1580,
    484, -540, 512, -540, 508, -544, 488, -1596, 484
  };
  
  const int rawLength = sizeof(rawData) / sizeof(rawData[0]);

  // Send the raw IR data
  irsend.sendRaw(rawData, rawLength, 38); // 38kHz carrier frequency
  
  // Wait before sending again
  delay(2000);
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
