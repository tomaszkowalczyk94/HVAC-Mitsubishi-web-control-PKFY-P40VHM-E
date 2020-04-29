#include <SoftwareSerial.h>
#include <IRremote.h>
SoftwareSerial hc06(12,13);

int MAX_SIGNAL_DELAY = 300;
int KHZ = 38;

void setup(){
  //Initialize Serial Monitor
  Serial.begin(9600);
  //Initialize Bluetooth Serial Port
  hc06.begin(9600);
}




unsigned long lastByteTime = 0;
boolean signalFlushed = true;
long numberOfNextByteToWrite = 0;


byte buffor[300];

void loop(){
  //Write data from HC06 to Serial Monitor
  if (hc06.available()){
    byte readedData = hc06.read();
    
    Serial.write(readedData);
    Serial.write("\n");

    buffor[numberOfNextByteToWrite] = readedData;
    
    lastByteTime = millis();
    signalFlushed = false;
  } else {
    if(lastByteTime + MAX_SIGNAL_DELAY <  millis() && !signalFlushed) {
      flush();
      signalFlushed = true;
      numberOfNextByteToWrite = 0;
    }
  }
}

void flush() {
  Serial.write("MAMY TO");

  unsigned int irSignal[] = {9000, 4500, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 39416, 9000, 2210, 560}; //AnalysIR Batch Export (IRremote) - RAW
  
  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), KHZ); //Note the approach used to automatically calculate the size of the array.
  
}




//void setup() {
//  // put your setup code here, to run once:
//
//}
//
//IRsend irsend;
//
//void loop() {
//  int khz = 38; // 38kHz carrier frequency for the NEC protocol

//
//  delay(10000); 
//}
