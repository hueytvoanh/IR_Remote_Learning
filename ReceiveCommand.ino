#include <IRremote.h>

const int RECV_PIN = 2;        // IR receiver pin
//const int IR_SEND_PIN = 3;     // IR transmitter pin (sending pin)

IRrecv irrecv(RECV_PIN);
decode_results results;

// Instantiate IRsend without parameters (defaults to pin 3)
IRsend irsend;

void setup() {
  Serial.begin(9600);
  Serial.println("IRrecvDumpV2 ready");
  irrecv.enableIRIn();

  // Set the IR send pin as output (optional, since IRremote defaults to pin 3)
  //pinMode(IR_SEND_PIN, OUTPUT);
  // Initialize IRsend with 38kHz carrier frequency
  //irsend.enableIROut(38);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println("-------------------------");
    Serial.print("Raw Data Length: ");
    Serial.println(results.rawlen);
    Serial.print("Protocol: ");
    Serial.println(protocolName(results.decode_type));

    if (results.value != 0) {
      Serial.print("Decoded Value: 0x");
      Serial.println(results.value, HEX);
    }

    Serial.println("Raw timing data (microseconds):");
    for (unsigned int i = 1; i < results.rawlen; i++) {
      Serial.print(results.rawbuf[i]);
      Serial.print(i % 16 == 0 ? "\n" : "\t");
    }

    Serial.println("\nRaw data (internal ticks):");
    for (unsigned int i = 1; i < results.rawlen; i++) {
      Serial.print(results.rawbuf[i]);
      Serial.print(i % 16 == 0 ? "\n" : "\t");
    }
    /*
    // Send back if pattern matches
    if (results.rawlen >= 4 && results.rawbuf[1] == 0xBC && results.rawbuf[2] == 0x01) {
      Serial.print("Pronto Hex: ");
      for (unsigned int i = 1; i < results.rawlen; i++) {
        if (i > 1) Serial.print(" ");
        Serial.print(results.rawbuf[i], HEX);
      }
      Serial.println();

      // Send the raw data back using sendRaw
      irsend.sendRaw((const unsigned int*)results.rawbuf, results.rawlen, 38);
    }
    */
    irrecv.resume();
  }
}

String protocolName(decode_type_t type) {
  switch (type) {
    case NEC: return "NEC";
    case SONY: return "SONY";
    case RC5: return "RC5";
    case RC6: return "RC6";
    case JVC: return "JVC";
    // case MITSUBISHI: return "MITSUBISHI"; // Uncomment if supported
    case SAMSUNG: return "SAMSUNG";
    case LG: return "LG";
    case UNKNOWN: return "UNKNOWN";
    default: return "OTHER";
  }
}
