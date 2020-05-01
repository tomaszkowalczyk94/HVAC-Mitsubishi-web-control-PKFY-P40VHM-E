#include <SoftwareSerial.h>
#include <IRremote.h>

SoftwareSerial hc06(12,13);
IRsend irsend;

int MAX_SIGNAL_DELAY = 300;
int KHZ = 38;

unsigned long lastByteTime = 0;
boolean signalFlushed = true;
long countOfBufforBytes = 0;
byte buffor[560];

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

  static unsigned int dataToSend[280];
  readDataToSendFromBufor(dataToSend);
  
  

//  unsigned int irSignal[] = {9000, 4500, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 39416, 9000, 2210, 560}; //AnalysIR Batch Export (IRremote) - RAW
//  
//  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), KHZ); //Note the approach used to automatically calculate the size of the array.
  
}

/**
 * return count of array
 */
int readDataToSendFromBufor(unsigned int *dataToSend) {

  Serial.println("=== XX: ===");
  Serial.println(buffor[0], HEX);
  Serial.println(buffor[1], HEX);
  
  volatile int iDataToSend = 0;
  volatile unsigned int valueToSave = 0;
  
  Serial.println("countOfBufforBytes:");
  Serial.println(countOfBufforBytes);
  
  for(int i; i<countOfBufforBytes;i++) {

    if(i%2 == 0) {
      Serial.println("i%2 == 0:");
      valueToSave = 0;
      valueToSave = buffor[i];
      Serial.println("valueToSave");
      Serial.println(valueToSave, HEX);
    } else {
      //dataToSend[iDataToSend] = valueToSave | (buffor[i]<<8);
      //dataToSend[iDataToSend] = (buffor[i]);
      Serial.println("else:");
      Serial.println(valueToSave, HEX);

      //dataToSend[iDataToSend] =  (valueToSave<<8) | buffor[i];      
     dataToSend[iDataToSend] = 2;
      iDataToSend++;
    }
  }
  
//  Serial.println("readed raw data:");
//  Serial.println(dataToSend[0], HEX);
}
