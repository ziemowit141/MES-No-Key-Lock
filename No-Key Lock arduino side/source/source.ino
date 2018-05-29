#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 9); 
// https://www.pjrc.com/teensy/td_libs_AltSoftSerial.html
 
 
char c=' ';
boolean NL = true;
 
void setup() 
{
    Serial.begin(9600);
    Serial.print("Sketch:   ");   Serial.println(__FILE__);
    Serial.print("Uploaded: ");   Serial.println(__DATE__);
    Serial.println(" ");
 
    BTserial.begin(9600);  
    Serial.println("BTserial started at 9600");
}
 
void loop()
{
    // Read from the Bluetooth module and send to the Arduino Serial Monitor
    if (BTserial.available())
    {
        c = BTserial.read();
        Serial.write(c);
    }
 
 
    // Read from the Serial Monitor and send to the Bluetooth module
    if (Serial.available())
    {
        BTserial.write(Serial.read());
 
        // do not send line end characters to the HM-10
//        if (c!=10 & c!=13 ) 
//        {  
//             BTserial.write(c);
//        }
// 
        // Echo the user input to the main window. 
        // If there is a new line print the ">" character.
//        if (NL) { Serial.print("\r\n>");  NL = false; }
//        Serial.write(c);
//        if (c==10) { NL = true; }
    }
}
