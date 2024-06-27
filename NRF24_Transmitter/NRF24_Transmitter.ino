#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  if (radio.begin()) {
    Serial.println("Transmitter initialized successfully");
    radio.openWritingPipe(address);
    radio.setPALevel(RF24_PA_MIN);
    radio.stopListening();
  } else {
    Serial.println("Transmitter initialization failed");
  }
}

void loop() {
  const char text[] = "Hello World";
  bool success = radio.write(&text, sizeof(text));
  if (success) {
    Serial.println("Message sent successfully");
  } else {
    Serial.println("Message sending failed");
  }
  delay(1000);
}
