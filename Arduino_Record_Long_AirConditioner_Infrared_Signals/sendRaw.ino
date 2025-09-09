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
 
void loop() {
 IrSender.sendRaw(rawData_ON, sizeof(rawData_ON) / sizeof(rawData_ON[0]), NEC_KHZ); // Note the approach used to automatically calculate the size of the array.

    delay(10000); // delay must be greater than 8 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal

 
    IrSender.sendRaw(rawData_OFF, sizeof(rawData_OFF) / sizeof(rawData_OFF[0]), NEC_KHZ); // Note the approach used to automatically calculate the size of the array.

    delay(10000); // delay must be greater than 8 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal
}

void testRaw(char *label, unsigned int *rawbuf, int rawlen) {
    IrSender.sendRaw(rawbuf, rawlen, 38 /* kHz */);
    delay(200);
}   
