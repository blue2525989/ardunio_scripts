
#include "Keyboard.h"
#include "Mouse.h"

 String RC = "RIGHT_CLICK\n";
 String LC = "LEFT_CLICK\n";

void setup() {  
  Serial.begin(9600);
  // initialize mouse and keyboard control:
  Mouse.begin();
  Keyboard.begin();
}

void keyPress(int keyVal) {
    Keyboard.press(keyVal);
    Keyboard.release(keyVal);
}

void loop() {
  if (Serial.available() > 0) {
    const String inputStr = Serial.readStringUntil("\n");
    if (inputStr != NULL) {
      Serial.print("Incoming string-> ");
      Serial.println(inputStr);
      // check mouse coordinates first
      if (inputStr.indexOf(",") != -1) 
      {
        String x = inputStr.substring(0, inputStr.indexOf(","));
        String y = inputStr.substring(inputStr.indexOf(",") +1, inputStr.length());
        x.trim();
        y.trim();
        Mouse.move(x.toInt(), y.toInt());
      } 
      // right click
      else if(inputStr == RC) {
        Mouse.press(MOUSE_RIGHT);
        Mouse.release();
      } 
      // left click
      else if(inputStr == LC) {
        Mouse.press(MOUSE_LEFT);
        Mouse.release();
      } 
      // keyboard input
      else {
        Serial.println(inputStr);
        if (inputStr == "a\n") {
          keyPress(97);
        }
        else if (inputStr == "b\n") {
          keyPress(98);
        }
        else if (inputStr == "c\n") {
          keyPress(99);
        }
        else if (inputStr == "e\n") {
          keyPress(101);
        }
        else if (inputStr == "i\n") {
          keyPress(105);
        }
        else if (inputStr == "k\n") {
          keyPress(107);
        }
        else if (inputStr == "1\n") {
          keyPress(49);
        }
        else if (inputStr == "2\n") {
          keyPress(50);
        }
        else if (inputStr == "3\n") {
          keyPress(51);
        }
        else if (inputStr == "4\n") {
          keyPress(52);
        }
        else if (inputStr == "capslock\n") {
          keyPress(KEY_CAPS_LOCK);
        }
        else if (inputStr == "tab\n") {
          keyPress(KEY_TAB);
        }
        else if (inputStr == "w\n") {
          keyPress(119);
        }
        else if (inputStr == "ESC\n") {
          keyPress(KEY_ESC);
        }
        else if (inputStr == "~\n") {
          keyPress(126);
        }
        else if (inputStr == "F1\n") {
          keyPress(KEY_F1);
        }
        else if (inputStr == "F2\n") {
          keyPress(KEY_F2);
        }
        else if (inputStr == "F3\n") {
          keyPress(KEY_F3);
        }
        else if (inputStr == "F4\n") {
          keyPress(KEY_F4);
        }
        else if (inputStr == "F5\n") {
          keyPress(KEY_F5);
        }
        else if (inputStr == "F6\n") {
          keyPress(KEY_F6);
        }
        else if (inputStr == "F7\n") {
          keyPress(KEY_F7);
        }
        else if (inputStr == "F8\n") {
          keyPress(KEY_F8);
        }
        else if (inputStr == "F9\n") {
          keyPress(KEY_F9);
        }
        else if (inputStr == "F10\n") {
          keyPress(KEY_F10);
        }
        else if (inputStr == "F11\n") {
          keyPress(KEY_F11);
        }
        else if (inputStr == "F12\n") {
          keyPress(KEY_F12);
        }
      }
    }
  }
}
