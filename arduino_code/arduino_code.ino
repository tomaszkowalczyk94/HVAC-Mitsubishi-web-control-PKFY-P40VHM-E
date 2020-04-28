//#include <IRremote.h>

//void setup() {
//  // put your setup code here, to run once:
//
//}
//
//IRsend irsend;
//
//void loop() {
//  int khz = 38; // 38kHz carrier frequency for the NEC protocol
//  unsigned int irSignal[] = {9000, 4500, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 39416, 9000, 2210, 560}; //AnalysIR Batch Export (IRremote) - RAW
//  
//  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
//
//  delay(10000); 
//}


void setup() {
  Serial.begin(9600);
}
void loop() {
  Serial.print(".");
  delay(100);
}
