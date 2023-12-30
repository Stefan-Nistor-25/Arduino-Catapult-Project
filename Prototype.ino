#include <Servo.h>
#include <LiquidCrystal.h>
#include <Stepper.h>
#define IR_SMALLD_NEC

#include <IRsmallDecoder.h>
IRsmallDecoder irDecoder(2);
irSmallD_t irData;

const int rolePerMinute = 16;
const int stepsPerRevolution = 2048;

Servo myservo;
Stepper myStepper(stepsPerRevolution, 7, 9, 8, 10);

const int xPin = A0;  //pin for the x direction of the joystick
const int yPin = A1;  //pin for the y direction of the joystick
const int servoPin = 13;  //pin for the servo

bool on = false;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 6; //pins for the LCD display
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);

  myservo.attach(servoPin);
  myStepper.setSpeed(rolePerMinute);

  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Move stick");
  lcd.setCursor(0, 1);
  lcd.print("and press power");

  delay(3000);

}

void loop() {

  int xVal = analogRead(xPin);  //read value from the xpin of the joystick
  int yVal = analogRead(yPin);  //read value from the ypin of the joystick

  Serial.println(xVal);
  Serial.println(yVal);

  //Wait for the IR reciever to get a signal from the controller, then proceed with the angle and launch functions

  /* if  (digitalRead(buttonPin) == HIGH) {
     on = !on;
    }
    if (on) {
     launch(velocity, servoAngle);
    }
    }*/

  int stepAngle = getAngle();
  int servoLaunch = getVelocity();

  if (irDecoder.dataAvailable(irData)) {

    if (irData.cmd == 69) {

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("X-val:");
      lcd.setCursor(6, 0);
      lcd.print(xVal);
      lcd.setCursor(0, 1);
      lcd.print("Y-val:");
      lcd.setCursor(6, 1);
      lcd.print(yVal);

      setAngle(stepAngle);
      delay(1000);
      setVelocity(servoLaunch);
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Launch");
      lcd.setCursor(0, 1);
      lcd.print("Successful");
      delay(2000);
      lcd.clear();

    }
    irData.cmd = 0;

    setVelocity(-servoLaunch);
    delay(1000);
    setAngle(-stepAngle);
  }

}

int getAngle() {

  int stepAngle;
  int xVal = analogRead(xPin);  //read value from the xpin of the joystick

  if (xVal > 503) {

    stepAngle = map(xVal, 504, 1023, 0, 512); //clockwise

  }

  else {

    stepAngle = map(xVal, 0, 503, -512, 0); //counter clockwise

  }

  return stepAngle;
}

void setAngle(int stepAngle) {

  myStepper.step(stepAngle);

}

int getVelocity() {

  int yVal = analogRead(yPin);  //read value from the ypin of the joystick

  int servoLaunch = map(yVal, 0, 1023, 0, 180);

  return servoLaunch;
}

int setVelocity(int servoLaunch) {

  myservo.write(servoLaunch);

}