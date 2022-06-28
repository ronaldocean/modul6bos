#include "DHT.h"

#define dht_1 2
#define DHTTYPE DHT11
#define kpa2atm 0.00986923267
DHT dht(dht_1, DHTTYPE);

// pin
int pressurePin = 1;

// variables 
int val;
float pkPa; // pressure in pkPa
float pAtm; // pressure in pAtm

unsigned long time;
const int buzzer = 13;
const int blue = 12;
const int green = 11;
const int red = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);

  val = analogRead(pressurePin);
  pkPa = ((float)val/(float)1023 + 0.095)/0.009;
  pAtm = kpa2atm*pkPa;
  
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();
  float heatIndex = dht.computeHeatIndex(temp, humid, false);

  Serial.print("Humidity = ");
  Serial.println(humid);
  Serial.print("Heat Index = ");
  Serial.println(heatIndex);  
  Serial.print("Temperature = ");
  Serial.println(temp);
  Serial.println("degree centigrade");
  Serial.println("");

  Serial.print(pkPa);
  Serial.println(" kPa");
  Serial.print(pAtm);
  Serial.println(" Atm");
  Serial.println("");

    if (heatIndex >= 0 && heatIndex < 45 && pkPa < 80){
      digitalWrite(blue, HIGH);
      delay(1000);
      digitalWrite(blue, LOW);
    }
    else if (heatIndex >= 45 && heatIndex < 55 && pkPa >= 80 && pkPa < 100){
      digitalWrite(green, HIGH);
      delay(1000);
      digitalWrite(green, LOW);
    }
    if (heatIndex >= 55 && pkPa > 100){
      digitalWrite(red, HIGH);
      tone(buzzer, 1000);
      delay(1000);
      noTone(buzzer);
      digitalWrite(red, LOW);
    }
    else {
      digitalWrite(blue, LOW);
      digitalWrite(green, LOW);
      digitalWrite(red, LOW);
      noTone(buzzer);
      Serial.println("");
    }
 }
