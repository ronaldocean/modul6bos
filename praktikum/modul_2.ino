#include <SoftwareSerial.h>
SoftwareSerial SwSerial(0, 1); //RX, TX

int buttonState = 0;

void setup() {
  // put your setup code here, to run once:

  //SERIAL
  SwSerial.begin(9600);
   // pin RED
  pinMode(13,OUTPUT);
  pinMode(12,INPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);

  // PIN BLUE
  pinMode(11,OUTPUT);
  pinMode(10,INPUT);
  pinMode(3,OUTPUT);
  pinMode(6,OUTPUT);

  // PIN GREEN
  pinMode(9,OUTPUT);
  pinMode(8,INPUT);
  pinMode(2,OUTPUT);
  pinMode(5,OUTPUT);

   
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(9,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  // button green
   buttonState = digitalRead(12);
  if (buttonState == HIGH) {
    SwSerial.println("Lampu Hijau dan Buzzer menyala");
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
  } else {
    digitalWrite(2,LOW);
    digitalWrite(5,LOW);
  }
  
  // button blue
    buttonState = digitalRead(10);
  if (buttonState == HIGH) {
    SwSerial.println("Lampu Blue dan Buzzer menyala");
    digitalWrite(3,HIGH);
    digitalWrite(6,HIGH);
  } else {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
  }

    // button red
    buttonState = digitalRead(8);
  if (buttonState == HIGH) {
    SwSerial.println("Lampu Red dan Buzzer menyala");
    digitalWrite(4,HIGH);
    digitalWrite(7,HIGH);
  } else {
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
  }
}
