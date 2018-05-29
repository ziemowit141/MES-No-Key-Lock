#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  Serial.println("Goodnight moon!");

  delay(500);

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.print("Wake up wake up wake up wake up wake up! Wake up wake up wake up wake up wake up!");
}

void loop() // run over and over
{
  if (mySerial.available()) {
    String s = "";
    char c;
    while((c = mySerial.read()) != -1) {
      s += c;
      delay(10);
    }

    Serial.println("Received: " + s);
  }

  if (Serial.available()) {
    String s = "";
    char c;
    while((c = Serial.read()) != -1) {
      s += c;
      delay(10);
    }

    delay(10);

    Serial.println("Sent: " + s);

    mySerial.print(s);
  }
}
