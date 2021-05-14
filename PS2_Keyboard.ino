//A program to read in the key press of a PS/2 keyboard and display the read key onto an attached LCD screen

#include <LiquidCrystal.h>

const int d7 = 12;
const int d6 = 11;
const int d5 = 10;
const int d4 = 9;
const int en = 8;
const int rs = 7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);      //Initiallizing LCD

const int dataPin = 4;
const int clockPin = 2;

int bitCount = 0;
int readArray[11];
int keyValue[8];
int i;

bool arrayCheck = false;
bool enterBit = false;
bool clearSent = false;

String keyString;
String sentence;
char key;
char prevKey;

void setup() {

  pinMode(dataPin, INPUT);                                                    //Setting data pins to input and pullup mode
  pinMode(clockPin, INPUT);
  digitalWrite(dataPin, HIGH);
  digitalWrite(clockPin, HIGH);
    
  attachInterrupt(digitalPinToInterrupt(clockPin), readKeyboard, FALLING);    //Interrupt for key press

  lcd.begin(16, 2);
  
  //Serial.begin(9600);                                                       //Serial needed if inputting new key codes
}

void loop() {
  
    if (arrayCheck == true) {                                                 //Checking that a correct keycode was received
      for (i = 0; i < 8; i++) {
        keyString = keyString + String(keyValue[i]);                          //Converting the values in keyValue to string and adding it to keyString
      }
      setChar();                                                              //Going to the setChar function to reference keycode to ASCII character
      if (key != prevKey) {                                                   //Adding the found character to the sentence string and printing it
          lcd.clear();                                                        //if the key isn't a repeat  
          sentence = sentence + key;
          lcd.print(sentence);

        //Serial.println(sentence);  
        //Serial.println(key);
        //Serial.println(keyString);
      }
      //Serial.println(keyString);
      prevKey = key;
    }
    arrayCheck = false;
    keyString = "";
}

void readKeyboard() {                                                           //The interrupt that triggers on the falling edge of the keyboards clock

  readArray[bitCount] = digitalRead(dataPin);

    if (bitCount == 10) {
      
    if (readArray[0] == 0 && readArray[10] == 1) {                              //Checking for the correct start and stop bits
        arrayCheck = true;
        for (i = 8; i >= 1; i--) {                                              //Transferring key value to seperate array
          keyValue[i - 1] = readArray[i];
        }
        arrayReset();                                                           //Calling arrayReset to clear the readArray array
      }
      
      else {
        lcd.print("ERROR: Invalid keycode.");
        arrayReset();
      }
    }
    else {
      bitCount +=1;
    }
    
  return;  
}

void arrayReset() {
  for (i = 0; i < 11; i++) {
    readArray[i] = 0;
  }
  bitCount = 0;
  
  return;
}

void setChar() {                                                               //Setting char value to the ASCII key the binary translates to

 
        if (keyString.equals("01101000") || keyString.equals("10010110")) {
          key = '1';
        }
        else if (keyString.equals("01111000")|| keyString.equals("01001110")) {
          key = '2';
        }
        else if (keyString.equals("01100100")|| keyString.equals("01011110")) {
          key = '3';
        }
        else if (keyString.equals("10100100")|| keyString.equals("11010110")) {
          key = '4';
        }
        else if (keyString.equals("01110100")|| keyString.equals("11001110")) {
          key = '5';
        }
        else if (keyString.equals("01101100")|| keyString.equals("00101110")) {
          key = '6';
        }
        else if (keyString.equals("10111100")|| keyString.equals("00110110")) {
          key = '7';
        }
        else if (keyString.equals("01111100")|| keyString.equals("10101110")) {
          key = '8';
        }
        else if (keyString.equals("01100010")|| keyString.equals("10111110")) {
          key = '9';
        }
        else if (keyString.equals("10100010") || keyString.equals("00001110")) {
          key = '0';
        }
        else if (keyString.equals("10101000")) {
          key = 'q';
        }
        else if (keyString.equals("10111000")) {
          key = 'w';
        }
        else if (keyString.equals("00100100")) {
          key = 'e';
        }
        else if (keyString.equals("10110100")) {
          key = 'r';
        }
        else if (keyString.equals("00110100")) {
          key = 't';
        }
        else if (keyString.equals("10101100")) {
          key = 'y';
        }
        else if (keyString.equals("00111100")) {
          key = 'u';
        }
        else if (keyString.equals("11000010")) {
          key = 'i';
        }
        else if (keyString.equals("00100010")) {
          key = 'o';
        }
        else if (keyString.equals("10110010")) {
          key = 'p';
        }
        else if (keyString.equals("00101010")) {
          key = '[';
        }
        else if (keyString.equals("11011010")) {
          key = ']';
        }
        else if (keyString.equals("00101010")) {
          key = '[';
        }
        else if (keyString.equals("10111010")) {
         // key = '\';
        }
        else if (keyString.equals("00111000")) {
          key = 'a';
        }
        else if (keyString.equals("11011000")) {
          key = 's';
        }
        else if (keyString.equals("11000100")) {
          key = 'd';
        }
        else if (keyString.equals("11010100")) {
          key = 'f';
        }
        else if (keyString.equals("00101100")) {
          key = 'g';
        }
        else if (keyString.equals("11001100")) {
          key = 'h';
        }
        else if (keyString.equals("11011100")) {
          key = 'j';
        }
        else if (keyString.equals("01000010")) {
          key = 'k';
        }
        else if (keyString.equals("11010010")) {
          key = 'l';
        }
        else if (keyString.equals("00110010")) {
          key = ';';
        }
        else if (keyString.equals("01001010")) {
          //   key = "'";
        }
        else if (keyString.equals("01011000")) {
          key = 'z';
        }
        else if (keyString.equals("01000100")) {
          key = 'x';
        }
        else if (keyString.equals("10000100")) {
          key = 'c';
        }
        else if (keyString.equals("01010100")) {
          key = 'v';
        }
        else if (keyString.equals("01001100")) {
          key = 'b';
        }
        else if (keyString.equals("10001100")) {
          key = 'n';
        }
        else if (keyString.equals("01011100")) {
          key = 'm';
        }
        else if (keyString.equals("10000010")) {
          key = ',';
        }
        else if (keyString.equals("10010010")) {
          key = '.';
        }
        else if (keyString.equals("01010010")) {
          key = '/';
        }
        else if (keyString.equals("00111110")) {
          key = '*';
        }
        else if (keyString.equals("11011110")) {
          key = '-';
        }
        else if (keyString.equals("10011110")) {
          key = '+';
        }
        else if (keyString.equals("10010100")) {
          key = ' ';
        }
        else if (keyString.equals("00001111") || ("00000111")) {          //Repeat code
        }
        else {
          key = '\0';
        }
  return;
}
