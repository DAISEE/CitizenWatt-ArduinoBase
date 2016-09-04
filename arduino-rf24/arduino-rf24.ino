#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"

#define SERIAL_BAUDRATE 57600

// PreAmplifier level for the nRF
// Lower this to reduce power consumption. This will reduce range.
rf24_pa_dbm_e NRF_PA_LEVEL = RF24_PA_MIN;

// Speed for the nrf module
// RF24_250KBPS / RF24_1MBPS / RF24_2MBPS
// Reduce it to improve reliability
rf24_datarate_e NRF_SPEED = RF24_250KBPS;

// Channel for the nrf module
// 76 is default safe channel in RF24
uint8_t NRF_CHANNEL = 0x4c;

// Struct of RF data
uint8_t payload[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// Set up nRF24L01 radio on SPI bus plus pins 7 & 8
RF24 radio(7, 8);

void setup() {
  
  Serial.begin(SERIAL_BAUDRATE);

  printf_begin();
  
  radio.begin();   
  
  radio.setChannel(NRF_CHANNEL);

  // Max number of retries and max delay between them
  radio.setRetries(15, 15);

  // Reduce payload size to improve reliability
  radio.setPayloadSize(16);

  // Set the datarate
  radio.setDataRate(NRF_SPEED);

  // Use the largest CRC
  radio.setCRCLength(RF24_CRC_16);

  // Ensure auto ACK is enabled
  radio.setAutoAck(1);

  // Use the adapted PA level
  radio.setPALevel(NRF_PA_LEVEL);

  radio.openReadingPipe(1, 0xE056D446D0LL);
  
  radio.startListening();

  // for debug
  //radio.printDetails();
    
}

void loop() {
    
    if(radio.available()) {
              
        radio.read(&payload, sizeof(payload));
        
        Serial.write(payload, sizeof(payload));

        // for debug
        //for(int i=0; i<sizeof(payload); i++) {
        //      Serial.print(String(payload[i],HEX));
        //}  
                
    }

    delay(100);

}
