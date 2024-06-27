#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

void setup() {
  Serial.begin(9600);
  if (radio.begin()) {
    Serial.println("nRF24L01+ module initialized successfully!");
  } else {
    Serial.println("nRF24L01+ module initialization failed.");
  }
}

void loop() {
}
