// https://github.com/shirriff/Arduino-IRremote
//#include <IRremote.h>
#include <IRremote.hpp>

//IRsend irsend;
//IrSender irsend;

void setup()
{
  //irsend.begin(3);
  IrSender.begin(3);
}
unsigned int rawData_ON[] = {
  3368, 9848, 500, 1584, 504, 528, 504, 528, 504, 532, 500, 1560,
  504, 540, 500, 532, 500, 532, 500, 532, 500, 532, 500, 532,
  500, 532, 500, 532, 500, 532, 500, 532, 504, 536, 500, 1564,
  504, 536, 500, 1572, 492, 548, 500, 532, 500, 1572, 504, 532,
  500, 528, 504, 1572, 500, 1564, 496, 1580, 504, 532, 500
};

unsigned int rawData_OFF[] = {
  3168, 9856, 512, 1592, 492, 528, 536, 516, 484, 548, 520, 1548,
    488, 552, 516, 516, 512, 520, 516, 1552, 516, 1556, 488, 552,
    484, 548, 488, 548, 484, 544, 520, 516, 484, 548, 484, 548,
    512, 528, 516, 524, 516, 520, 484, 548, 484, 1588, 484, 548,
    488, 1588, 508, 532, 484, 556, 512, 520, 484, 1592, 512
};

unsigned int rawData_FAN[] = {
  3108, 9868, 496, 1580, 504, 524, 520, 540, 504, 532, 500, 1576,
  504, 500, 540, 532, 496, 536, 500, 532, 476, 556, 476, 556, 504, 516,
  520, 1576, 500, 532, 504, 1572, 476, 572, 500, 524, 508, 536, 496, 1564,
  504, 1560, 500, 540, 504, 1568, 476, 560, 500, 528, 504, 528, 500, 536,
  472, 556, 476, 1592, 500
};

unsigned int rawData_COOL[] = {
  3340, 9852, 496, 1588, 500, 532, 500, 532, 500, 532, 500, 1588, 500, 520, 520, 532,
  504, 528, 500, 532, 504, 528, 504, 528, 504, 536, 500, 1576, 500, 528, 520, 532,
  496, 532, 504, 1564, 500, 520, 520, 1572, 500, 540, 500, 532, 476, 1588, 500, 540,
  500, 532, 500, 532, 500, 1564, 476, 1612, 500, 524, 516
};

unsigned int rawData_AUTO[] = {
  3160, 9880, 496, 1596, 500, 532, 476, 556, 504, 528, 504, 1548, 524, 536, 504, 528,
  504, 528, 504, 528, 504, 528, 508, 524, 504, 540, 504, 1560, 500, 520, 520, 1564,
  500, 1564, 500, 528, 524, 528, 500, 1564, 500, 540, 500, 524, 520, 1576, 504, 528,
  504, 1560, 500, 532, 504, 528, 504, 1572, 500, 536, 504
};

void loop() {
    delay(5000);
    IrSender.sendRaw(rawData_ON, sizeof(rawData_ON) / sizeof(rawData_ON[0]), NEC_KHZ); // Note the approach used to automatically calculate the size of the array.
    delay(10000); // delay must be greater than 8 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal

    IrSender.sendRaw(rawData_COOL, sizeof(rawData_COOL) / sizeof(rawData_COOL[0]), NEC_KHZ); // Note the approach used to automatically calculate the size of the array.
    delay(10000); // delay must be greater than 8 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal

    IrSender.sendRaw(rawData_FAN, sizeof(rawData_FAN) / sizeof(rawData_FAN[0]), NEC_KHZ); // Note the approach used to automatically calculate the size of the array.
    delay(10000); // delay must be greater than 8 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal

    IrSender.sendRaw(rawData_AUTO, sizeof(rawData_AUTO) / sizeof(rawData_AUTO[0]), NEC_KHZ); // Note the approach used to automatically calculate the size of the array.
    delay(10000); // delay must be greater than 8 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal
 
    IrSender.sendRaw(rawData_OFF, sizeof(rawData_OFF) / sizeof(rawData_OFF[0]), NEC_KHZ); // Note the approach used to automatically calculate the size of the array.
    delay(10000); // delay must be greater than 8 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal
}

void testRaw(char *label, unsigned int *rawbuf, int rawlen) {
    IrSender.sendRaw(rawbuf, rawlen, 38 /* kHz */);
    delay(200);
}   
