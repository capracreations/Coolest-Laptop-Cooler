#include <LiquidCrystal.h>

#define FAN 9
#define P1 3
#define P2 4
#define P3 5

//const int fan = 9;
int count = 0;
unsigned long time;
int rpm;
bool PL;
bool PM;
bool PR;
int pwm = constrain(pwm, 0, 320);
int val;

LiquidCrystal lcd(6, 7, 8, 10, 11, 12);

void setup() {
  
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM11);
  TCCR1B = _BV(WGM13) | _BV(CS10);
  ICR1 = 320;
  pinMode(FAN, OUTPUT);
  OCR1A = 0;
  OCR1B = 0;

  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), counter, RISING);

  pinMode(P1, INPUT_PULLUP);
  pinMode(P2, INPUT_PULLUP);
  pinMode(P3, INPUT_PULLUP);

  lcd.begin(16, 2);
}

void loop() {

    PL = digitalRead(P1);
    PM = digitalRead(P2);
    PR = digitalRead(P3);

  if(PL == LOW && pwm > 0) {

    pwm -= 32;
    val = pwm;
    OCR1A = pwm;
  }
  if(PR == LOW && pwm < 320) {

    pwm += 32;
    val = pwm;
    OCR1A = pwm;
  }
  if(PM == LOW) {

    if(val != 0) {
      for(pwm = val; pwm >= 32; pwm -= 32) {

        OCR1A = pwm;
        lcd.clear();
        lcd.print(" Ramping Down..");    
        lcd.setCursor(0, 1);  
        lcd.print("PWM=");
        lcd.setCursor(4, 1);  
        lcd.print(map(pwm, 0, 320, 0, 100));
        lcd.print("%");
        lcd.setCursor(8, 1);
        lcd.print("RPM=");
        lcd.print(floor(map(pwm, 0, 320, 0, 1700)));
        Serial.println(pwm);
        delay(500);
      }
      delay(4500);
      pwm = 0;
      val = pwm;
      OCR1A = pwm;  
    } 
  }

    lcd.clear();
    lcd.print(" COOLER STATUS:");
    lcd.setCursor(0, 1);  
    lcd.print("PWM=");  
    lcd.print(map(pwm, 0, 320, 0, 100));
    lcd.print("%");
    lcd.setCursor(8, 1);
    lcd.print("RPM=");
    lcd.print(floor(map(pwm, 0, 320, 0, 1700)));

    Serial.print(PL);
    Serial.print("\t");
    Serial.print(PM);
    Serial.print("\t");
    Serial.print(PR);
    Serial.print("\n");
    //Serial.println(count);
    //Serial.print("Speed = ");
    //Serial.print(rpm);
    //Serial.println(" rpm");

  delay(125);

}

void counter() {

  count++;
}