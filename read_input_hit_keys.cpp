#include "Keyboard.h"
#include "Mouse.h"
int incomingByte;
void setup() {

  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0) {
   incomingByte = Serial.read();
   if (incomingByte != NULL) {
     Serial.print ('\n');
     Serial.print ('F5 Pressed');
     Keyboard.write(65);
     Keyboard.write(68);
     Keyboard.write(69);
   }
 }
}
