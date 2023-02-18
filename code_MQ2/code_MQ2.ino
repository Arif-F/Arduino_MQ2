/*

*/

#include <sofwareSerial.h>
sofwareSerail sim(2, 4);
#define tx 2 // pin GSM 2 & 4 
#define rx 4
String_buffer;
String number = "xxxxxx";
#define RL 1// Nilai 1-10
#define m -0.46820
#define b 1.28218
#define Ro 5.5
#define MQ2 A0 //PIN Sendor MQ2 Gas
#define relay 6
#define buzzer 10
#define led 8
float VRL ;
float Rs;
float Ratio;

void setup() {
  Serial.begin(9600);
  sim.begin(9600);
  delay(3000);
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  VRL = analogRead(MQ2) * (3.3 / 4095.0);
  Rs = ((3.3 * RL) / VRL) - RL;
  Ratio = Rs / Ro;
  PPM = pow(10, ((log10(ratio) - b) / m));
  Serial.print("Rs/Ro = ");
  Serial.print(Ratio);
  Serial.print("LPG(ppm)=");
  Serial.print(PPM);
  delay(500)

  if (PPM > 250) {
    digitalWrite(relay, LOW);
    callNumber();
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, LOW);
  }

  if (PPM < 24) {
    digitalWrite(relay, HIGH);
    digitalWrite(buzzer, LOW);
    digitalWrite(led, HIGH);
  }
}
