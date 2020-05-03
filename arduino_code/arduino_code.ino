#include <SoftwareSerial.h>
#include <IRremote.h>

SoftwareSerial hc06(12,13);
IRsend irsend;

int MAX_SIGNAL_DELAY = 300;
int KHZ = 38;

unsigned long lastByteTime = 0;
boolean signalFlushed = true;
long countOfBufforBytes = 0;
byte buffor[40];

void setup(){
  //Initialize Serial Monitor
  Serial.begin(9600);
  //Initialize Bluetooth Serial Port
  hc06.begin(9600);
}

void loop(){
  readBtData();
}

void readBtData() {
    //Write data from HC06 to Serial Monitor
  if (hc06.available()){
    byte readedData = hc06.read();
    buffor[countOfBufforBytes] = readedData;
    countOfBufforBytes++;
    
    lastByteTime = millis();
    signalFlushed = false;
  } else {
    if(lastByteTime + MAX_SIGNAL_DELAY <  millis() && !signalFlushed) {
      flush();
      signalFlushed = true;
      countOfBufforBytes = 0;
    }
  }
}


void flush() {
  static unsigned int irRawSignal[300];
  prepareRawSignal(irRawSignal, buffor);
  
//  unsigned int irSignal[] = {9000, 4500, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 39416, 9000, 2210, 560}; //AnalysIR Batch Export (IRremote) - RAW
//  
//  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), KHZ); //Note the approach used to automatically calculate the size of the array.
  
}

void prepareRawSignal(unsigned int *irRawSignal, byte *data) {
  
  
}
