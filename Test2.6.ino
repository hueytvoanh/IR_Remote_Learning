#include <IRremote.h>

const int RECV_PIN = 2; // Change to your IR receiver pin

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  Serial.println("IRrecvDumpV2 ready");
  irrecv.enableIRIn();
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
      Serial.print(results.rawbuf[i]); // Removed * USECPERTICK
      Serial.print(i % 16 == 0 ? "\n" : "\t");
    }

    Serial.println("\nRaw data (internal ticks):");
    for (unsigned int i = 1; i < results.rawlen; i++) {
      Serial.print(results.rawbuf[i]);
      Serial.print(i % 16 == 0 ? "\n" : "\t");
    }

    if (results.rawlen >= 4 && results.rawbuf[1] == 0xBC && results.rawbuf[2] == 0x01) {
      Serial.print("Pronto Hex: ");
      for (unsigned int i = 1; i < results.rawlen; i++) {
        if (i > 1) Serial.print(" ");
        Serial.print(results.rawbuf[i], HEX);
      }
      Serial.println();
    }

    irrecv.resume();
  }
}

// Map protocol enums to string names
String protocolName(decode_type_t type) {
  switch (type) {
    case NEC: return "NEC";
    case SONY: return "SONY";
    case RC5: return "RC5";
    case RC6: return "RC6";
    case JVC: return "JVC";
    //case MITSUBISHI: return "MITSUBISHI"; // Uncomment if supported
    case SAMSUNG: return "SAMSUNG";
    case LG: return "LG";
    case UNKNOWN: return "UNKNOWN";
    default: return "OTHER";
  }
}
