#include <LiquidCrystal.h>

#define A 3
#define B 5
#define C 7

LiquidCrystal lcd(4, 6, 8, 9, 10, 11);

//Wiring Diagram

//LCD: VSS VDD V0 RS E R D0 D1 D2 D3 D4 D5 D6 D7 A K
//PIN: -   +   P  4  6               8  9  10 11 + -
//PRIMARY SWITCH: A5
//SECONDARY SWITCH: A4
//INPUT SWITCHES: A = 3 B = 5 C = 7


void setup() {
  //Begin Serial
  Serial.begin(9600);
  //Initialize all Switches
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  //Start LCD
  lcd.begin(16, 2);
  lcd.print("Access Ready");
}

//Useful Initial Values
boolean zone = false;
String str = "";
int cur = 3;

void loop() {
  //Check for primary switch activation
  if (digitalRead(A5) == HIGH) {
    zone = true;
    //Serial.println("Entered the Zone"); //Debug Code
    //Start Input with LCD framework
    lcd.clear();
    lcd.print("Enter Code:");
    lcd.setCursor(0, 2);
    lcd.print("->");
    lcd.setCursor(cur,2);
    delay(300);
  }
  while (zone) {
    //Append each input as a ternary value of 0, 1, or 2
    if (digitalRead(A)) {
      //Serial.println("A Entered"); //Debug Code
      str += "0";
      lcd.print("0");
      cur++;
      delay(200);
    } else if (digitalRead(B)) {
      //Serial.println("B Entered"); //Debug Code
      str += "1";
      lcd.print("1");
      cur++;
      delay(200);
    } else if (digitalRead(C)) {
      //Serial.println("C Entered"); //Debug Code
      lcd.print("2");
      str += "2";
      cur++;
      delay(200);
    } else if (digitalRead(A4)) {
      //Serial.println("Backspaced"); //Debug Code
      //Backspace last value by moving cursor temporarily
      str = str.substring(0, str.length()-1);
      cur -= 1;
      lcd.setCursor(cur, 2);
      lcd.print(" ");
      lcd.setCursor(cur, 2);
      delay(200);
    }
    //Serial.println(str); //Debug Code
    //Check for a exit command
    if (digitalRead(A5) == HIGH) {
      //Initiate Exit Command
      Serial.print((char)tern(str));
      zone = false;
      lcd.clear();
      lcd.print("Processing");
      lcd.setCursor(1,2);
      lcd.print("Request #");
      lcd.setCursor(10,2);
      //Send over a char to Serial from ternary value
      lcd.print(tern(str));
      //Serial.println("Exit Zone"); //Debug Code
      str = "";
      delay(2000);
      //Repeat Loop from Start
      lcd.clear();
      lcd.print("Access Ready");
      cur = 3;
      break;
    }
    delay(100);
  }
  delay(100);
}

long tern(String s) {
  //Convert the string of ternary digits to one char using 
  //conversion from base 3 -> int -> ASCII
  long num = 0;
  long power = 1;
  for (int i = 0; i < s.length(); i++) {
    for (int j = 0; j < i; j++) {
      power = 3 * power;
    }
    num += ((s.charAt(s.length() - 1 - i) - '0') * power);
    power = 1;
    //Serial.print("Char is "); //Debug Code
    //Serial.print(s.charAt(s.length() - 1 - i) - '0'); //Debug Code
    //Serial.print("\n And Num is "); //Debug Code
    //Serial.print(num); //Debug Code
    //Serial.print("\n"); //Debug
  }
  return num;
}
