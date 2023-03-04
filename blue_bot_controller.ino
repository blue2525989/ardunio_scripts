
#include "Keyboard.h"
#include "Mouse.h"

 String RC = "RIGHT_CLICK\n";
 String LC = "LEFT_CLICK\n";
 String RELEASE = "RELEASE|";
 String PRESS = "PRESS|";

 const int F7_BUTTON = 9;
 const int F8_BUTTON = 8;
 const int F9_BUTTON = 7;
 const int F10_BUTTON = 10;
 const int F11_BUTTON = 16;
 const int F12_BUTTON = 14;

 int F7_BUTTON_STATE = 0;
 int F8_BUTTON_STATE = 0;
 int F9_BUTTON_STATE = 0;
 int F10_BUTTON_STATE = 0;
 int F11_BUTTON_STATE = 0;
 int F12_BUTTON_STATE = 0;


void setup() {  
  Serial.begin(9600);
  // initialize mouse and keyboard control:
  Mouse.begin();
  Keyboard.begin();
}

void keyPress(int keyVal, int holdWasFound) {
    Keyboard.press(keyVal);
    if (holdWasFound == 0) {
      Keyboard.release(keyVal);
    }
}

void loop() {


  if (Serial.available() > 0) {

    int holdWasFound = 0;
    String inputStr = Serial.readStringUntil("\n");
    if (inputStr != NULL) {
      Serial.print("Incoming string-> ");
      Serial.println(inputStr);
      if (inputStr.indexOf(PRESS) != -1) {
        holdWasFound = 1;
        Serial.println("PRESS found");
        inputStr = inputStr.substring(inputStr.indexOf("|") +1, inputStr.length());
        Serial.println(inputStr);
      }

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
      else if(inputStr == RC || inputStr == "right") {
        Mouse.press(MOUSE_RIGHT);
        if (holdWasFound == 0) {
          Mouse.release();
        }
      } 
      //left click
      else if(inputStr == LC || inputStr == "left") {
        Mouse.press(MOUSE_LEFT);
        if (holdWasFound == 0) {
          Mouse.release();
        }
      }  
      // release left click
      else if(inputStr.indexOf(RELEASE) != -1) {
        Mouse.release();
        Keyboard.releaseAll();
      }  
      // keyboard input
      else {
        Serial.println(inputStr);
        if (inputStr == "a\n") {
          keyPress(97, holdWasFound);
        }
        else if (inputStr == "b\n") {
          keyPress(98, holdWasFound);
        }
        else if (inputStr == "c\n") {
          keyPress(99, holdWasFound);
        }
        else if (inputStr == "e\n") {
          keyPress(101, holdWasFound);
        }
        else if (inputStr == "i\n") {
          keyPress(105, holdWasFound);
        }
        else if (inputStr == "k\n") {
          keyPress(107, holdWasFound);
        }
        else if (inputStr == "1\n") {
          keyPress(49, holdWasFound);
        }
        else if (inputStr == "2\n") {
          keyPress(50, holdWasFound);
        }
        else if (inputStr == "3\n") {
          keyPress(51, holdWasFound);
        }
        else if (inputStr == "4\n") {
          keyPress(52, holdWasFound);
        }
        else if (inputStr == "capslock\n") {
          keyPress(KEY_CAPS_LOCK, holdWasFound);
        }
        else if (inputStr == "tab\n") {
          keyPress(KEY_TAB, holdWasFound);
        }
        else if (inputStr == "w\n") {
          keyPress(119, holdWasFound);
        }
        else if (inputStr == "esc\n") {
          keyPress(KEY_ESC, holdWasFound);
        }
        else if (inputStr == "~\n") {
          keyPress(126, holdWasFound);
        }
        else if (inputStr == "f1\n") {
          keyPress(KEY_F1, holdWasFound);
        }
        else if (inputStr == "f2\n") {
          keyPress(KEY_F2, holdWasFound);
        }
        else if (inputStr == "f3\n") {
          keyPress(KEY_F3, holdWasFound);
        }
        else if (inputStr == "f4\n") {
          keyPress(KEY_F4, holdWasFound);
        }
        else if (inputStr == "f5\n") {
          keyPress(KEY_F5, holdWasFound);
        }
        else if (inputStr == "f6\n") {
          keyPress(KEY_F6, holdWasFound);
        }
        else if (inputStr == "f7\n") {
          keyPress(KEY_F7, holdWasFound);
        }
        else if (inputStr == "f8\n") {
          keyPress(KEY_F8, holdWasFound);
        }
        else if (inputStr == "f9\n") {
          keyPress(KEY_F9, holdWasFound);
        }
        else if (inputStr == "f10\n") {
          keyPress(KEY_F10, holdWasFound);
        }
        else if (inputStr == "f11\n") {
          keyPress(KEY_F11, holdWasFound);
        }
        else if (inputStr == "f12\n") {
          keyPress(KEY_F12, holdWasFound);
        }
      }
    }
  }



}
