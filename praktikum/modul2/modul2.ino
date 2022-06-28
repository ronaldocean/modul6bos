#include <SoftwareSerial.h>
SoftwareSerial SwSerial(0, 1);

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

int buttonout1 = 13;
int buttonout2 = 11;
int buttonout3 = 9;
int buttonin1 = 12;
int buttonin2 = 10;
int buttonin3 = 8;

int buzz1 = 7;
int buzz2 = 6;
int buzz3 = 5;

int ledRed = 4;
int ledBlue = 3;
int ledGreen = 2;

void setup() {
  // put your setup code here, to run once:
  SwSerial.begin(9600);
  pinMode(buttonout1, OUTPUT);
  pinMode(buttonin1,INPUT);
  pinMode(buttonout2, OUTPUT);
  pinMode(buttonin2,INPUT);
  pinMode(buttonout3, OUTPUT);
  pinMode(buttonin3,INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(buzz1, OUTPUT);
  pinMode(buzz2, OUTPUT);
  pinMode(buzz3, OUTPUT);

  digitalWrite(buttonout1, HIGH);
  digitalWrite(buttonout2, HIGH);
  digitalWrite(buttonout3, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState1 = digitalRead(buttonin1);
  buttonState2 = digitalRead(buttonin2);
  buttonState3 = digitalRead(buttonin3);

  if (buttonState1 == HIGH) {
    SwSerial.println("Bell A Menyala");
    digitalWrite(ledRed, HIGH);
    tone(buzz1, 1000);
  }
  else if (buttonState2 == HIGH) {
    SwSerial.println("Bell B Menyala");
    digitalWrite(ledBlue, HIGH);
    tone(buzz2, 800);
  }
  else if (buttonState3 == HIGH) {
    SwSerial.println("Bell C Menyala");
    digitalWrite(ledGreen, HIGH);
    tone(buzz3, 500);
  }
  else {
    digitalWrite(ledRed, LOW);
    digitalWrite(ledBlue, LOW);
    digitalWrite(ledGreen, LOW);
    noTone(buzz1);
    noTone(buzz2);
    noTone(buzz3);
  }
}
