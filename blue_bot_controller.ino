
#include "Keyboard.h"
#include "Mouse.h"

 String RC = "RIGHT_CLICK\n";
 String LC = "LEFT_CLICK\n";
 String RELEASE = "RELEASE|";

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
  // setup physical buttons
  pinMode(F7_BUTTON, INPUT);
  pinMode(F8_BUTTON, INPUT);
  pinMode(F9_BUTTON, INPUT);
  pinMode(F10_BUTTON, INPUT);
  pinMode(F11_BUTTON, INPUT);
  pinMode(F12_BUTTON, INPUT);
}

void keyPress(int keyVal) {
    Keyboard.press(keyVal);
    Keyboard.release(keyVal);
}

void loop() {
  // delay(1);


  // F7_BUTTON_STATE = digitalRead(F7_BUTTON);
  // F8_BUTTON_STATE = digitalRead(F8_BUTTON);
  // F9_BUTTON_STATE = digitalRead(F9_BUTTON);
  // F10_BUTTON_STATE = digitalRead(F10_BUTTON);
  // F11_BUTTON_STATE = digitalRead(F11_BUTTON);
  // F12_BUTTON_STATE = digitalRead(F12_BUTTON);
  // Serial.println(F7_BUTTON_STATE);
  // Serial.println(F8_BUTTON_STATE);
  // Serial.println(F9_BUTTON_STATE);
  // Serial.println(F10_BUTTON_STATE);
  // Serial.println(F11_BUTTON_STATE);
  // Serial.println(F12_BUTTON_STATE);
  // Serial.println();
  // if (F7_BUTTON_STATE == LOW ) {
  //   Serial.println("f7");
  //   // keyPress(KEY_F7);
  // }
  // if (F8_BUTTON_STATE == LOW) {
  //   Serial.println("f8");
  //   // keyPress(KEY_F8);
  // }
  // if (F9_BUTTON_STATE == LOW) {
  //   Serial.println("f9");
  //   // keyPress(KEY_F9);
  // }
  // if (F10_BUTTON_STATE == LOW) {
  //   Serial.println("f10");
  //   // keyPress(KEY_F10);
  // }
  // if (F11_BUTTON_STATE == LOW) {
  //   Serial.println("f11");
  //   // keyPress(KEY_F11);
  // }
  // if (F12_BUTTON_STATE == LOW) {
  //   Serial.println("f12");
  //   // keyPress(KEY_F12);
  // }
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
