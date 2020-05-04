#include <SoftwareSerial.h>
#include <IRremote.h>

SoftwareSerial hc06(12,13);
IRsend irsend;

int MAX_SIGNAL_DELAY = 300;
int KHZ = 38;


unsigned int HDR_MARK = 3200;
unsigned int HDR_SPACE = 1600;


unsigned int BIT_MARK = 420;
unsigned int SPACE_0 = 410;
unsigned int SPACE_1 = 1200;

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
  int irRawSignalSize = prepareRawSignal(irRawSignal, buffor, countOfBufforBytes);

  Serial.println("raw data:");
  for(int i=0; i<irRawSignalSize; i++) {
    Serial.print(irRawSignal[i]);
    Serial.print(", ");
  }
   Serial.print("end of raw data");
  
//  unsigned int irSignal[] = {9000, 4500, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 39416, 9000, 2210, 560}; //AnalysIR Batch Export (IRremote) - RAW
//  
//  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), KHZ); //Note the approach used to automatically calculate the size of the array.
  
}

int prepareRawSignal(unsigned int *irRawSignal, byte *data, int dataSize) {
  Serial.println("prepareRawSignal:");
  int irRawSignalSize = 0;

  //hdr signal
  irRawSignal[0] = HDR_MARK;
  irRawSignal[1] = HDR_SPACE;
  irRawSignalSize = 2;
  
  for(int i = 0; i<dataSize ;i++) {
    Serial.print("raw hex: ");
    Serial.println(data[i], HEX);
    irRawSignalSize += witeToRawArray(data[i], irRawSignal, irRawSignalSize);
  }

  return irRawSignalSize;
}

int witeToRawArray(byte byteToAdd, unsigned int *rawSignal, int startPositionToWrite) {

  for(int bitIndex = 0; bitIndex<8 ;bitIndex++) {
    int bitPositionFromLeft = 7-bitIndex;
    
    int rawSignalIndex = startPositionToWrite + (bitIndex*2);

    rawSignal[rawSignalIndex] = BIT_MARK;
    
    if(getBit(byteToAdd, bitPositionFromLeft)) {
      rawSignal[rawSignalIndex+1] = SPACE_1;
    } else {
      rawSignal[rawSignalIndex+1] = SPACE_0;
    }
  }
  return 16;
}


boolean getBit(byte value, byte index) {
  return (1<<index) & value;
}
