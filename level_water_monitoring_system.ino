#include<LiquidCrystal_I2C_Hangul.h>
#include <Wire.h>
#include <WiFi.h>
//#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp32.h>
#define WIFI_SSID ""// put your wifi ssid here
#define WIFI_PASSWORD "" // put your wifi password here
#define BLYNK_TEMPLATE_ID "" // put your blynk template id here
#define BLYNK_TEMPLATE_NAME "Système de surveillance du niveau deau"

LiquidCrystal_I2C_Hangul lcd(0x27, 16, 2);



BlynkTimer timer;


#define trig 12
#define echo 13
#define LED1 2
#define LED2 4
#define LED3 5
#define relay 14
#define buzzer 33



int MaxLevel = 7;

int Level1 = (MaxLevel * 75) / 100;//4.5
int Level2 = (MaxLevel * 50) / 100;//3
int Level3 = (MaxLevel * 25) / 100;//1.5

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  lcd.setCursor(0, 0);
  lcd.print("Niveau d'eau:");
  lcd.setCursor(4, 1);
  lcd.print("contrôle");
  delay(4000);
  lcd.clear();

  
 timer.setInterval(100L, ultrasonic);
}


void ultrasonic() {
  digitalWrite(trig, LOW);
  delayMicroseconds(4);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long t = pulseIn(echo, HIGH);
  int distance = t / 29 / 2;

 int blynkDistance = (distance - MaxLevel) * -1;
 if (distance <= MaxLevel) {
 Blynk.virtualWrite(V0, blynkDistance);
  } else {
    Blynk.virtualWrite(V0, 0);
  }
  lcd.setCursor(0, 0);
  lcd.print("Niveau:");

  if (Level1 <= distance) {
    lcd.setCursor(8, 0);
    lcd.print("Low");
    lcd.print("      ");
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(buzzer, LOW);
   Serial.println(distance);
    
  } else if (Level2 <= distance && Level1 > distance) {
    lcd.setCursor(8, 0);
    lcd.print("Medium");
    lcd.print("      ");
    digitalWrite(LED1,LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(buzzer, LOW);
     Serial.println(distance);

  } else if (Level3 <= distance && Level2 > distance) {
    lcd.setCursor(8, 0);
    lcd.print("High");
    lcd.print("      ");
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
     digitalWrite(buzzer, HIGH);
    delay(1000);
    Serial.println(distance);
    
 
}


BLYNK_WRITE(V1) {
  bool Relay = param.asInt();
 if (Relay == 1) {
    digitalWrite(relay, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Moteur est ON ");
  } else {
    digitalWrite(relay, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Moteur est OFF");
  }
}

void loop(){
  Blynk.run();
  timer.run();
}
