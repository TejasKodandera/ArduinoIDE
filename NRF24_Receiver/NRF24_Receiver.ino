#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  if (radio.begin()) {
    Serial.println("Receiver initialized successfully");
    radio.openReadingPipe(0, address);
    radio.setPALevel(RF24_PA_MIN);
    radio.startListening();
  } else {
    Serial.println("Receiver initialization failed");
  }
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.print("Received message: ");
    Serial.println(text);
  } else {
    Serial.println("No message received");
  }
  delay(1000);
}
