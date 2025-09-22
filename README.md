# IR Remote Learning

     1. Header \
        HDR_MARK 
        HDR_SPACE
     2. Data \
        HVAC_MITSUBISHI_BIT_MARK
        HVAC_MITSUBISHI_ONE_SPACE
        HVAC_MISTUBISHI_ZERO_SPACE

     3. Retransmission
        HVAC_MITSUBISHI_RPT_MARK
        HVAC_MITSUBISHI_RPT_SPACE

https://github.com/Arduino-IRremote/Arduino-IRremote/tree/master/examples/SendLGAirConditionerDemo

https://github.com/r45635/HVAC-IR-Control/tree/master
<img width="774" height="415" alt="image" src="https://github.com/user-attachments/assets/9fee9f2a-2365-49b8-9ece-8867fc1b0951" />

https://github.com/crankyoldgit/IRremoteESP8266/issues/285

Code for Sending LG protocol
<img width="961" height="225" alt="image" src="https://github.com/user-attachments/assets/a24e6615-485c-42ee-9afa-f005f908675e" />

sendPulseDistanceWidth_P \
sendPulseDistanceWidth_P(&LGProtocolConstants, computeLGRawDataAndChecksum(aAddress, aCommand), LG_BITS, aNumberOfRepeats); \

<img width="1072" height="283" alt="image" src="https://github.com/user-attachments/assets/dda2d1be-512c-48d2-a2f6-53507bf37337" />

https://github.com/Arduino-IRremote/Arduino-IRremote/blob/ee3b9cd8dab1ed61b7d8555b712dbe4a0573a544/src/IRProtocol.h#L161
struct PulseDistanceWidthProtocolConstants {
    decode_type_t ProtocolIndex;
    uint_fast8_t FrequencyKHz;
    DistanceWidthTimingInfoStruct DistanceWidthTimingInfo;
    uint8_t Flags;
    unsigned int RepeatPeriodMillis; // Time between start of two frames. Thus independent from frame length.
    void (*SpecialSendRepeatFunction)(); // using non member functions here saves up to 250 bytes for send demo
//    void (IRsend::*SpecialSendRepeatFunction)();
};
/*
 * Definitions for member PulseDistanceWidthProtocolConstants.Flags
 */
#define PROTOCOL_IS_PULSE_DISTANCE      0x00
#define PROTOCOL_IS_PULSE_DISTANCE_WIDTH 0x00 // can often successfully be decoded as pulse distance
#define PROTOCOL_IS_PULSE_WIDTH         0x10
#define PROTOCOL_IS_PULSE_WIDTH_MASK    PROTOCOL_IS_PULSE_WIDTH
#define SUPPRESS_STOP_BIT               0x20 // Stop bit is otherwise sent for all pulse distance protocols, i.e. aOneSpaceMicros != aZeroSpaceMicros.
#define PROTOCOL_IS_MSB_FIRST           IRDATA_FLAGS_IS_MSB_FIRST
#define PROTOCOL_IS_LSB_FIRST           IRDATA_FLAGS_IS_LSB_FIRST
#define PROTOCOL_IS_MSB_MASK            IRDATA_FLAGS_IS_MSB_FIRST

<img width="1227" height="758" alt="image" src="https://github.com/user-attachments/assets/fc94c84f-abf2-43f7-bd2c-1d3eecc28a72" /> \

Send Misubishi
<img width="972" height="469" alt="image" src="https://github.com/user-attachments/assets/1c29a816-de8d-4a00-9b38-9eba6634133a" />


