This catapult was made for a school project in my Arduino class. The entire project was made using parts from this kit on Amazon https://www.amazon.com/dp/B01CZTLHGE?psc=1&ref=ppx_yo2ov_dt_b_product_details . The stepper motor chagnes the angle at which it launches. The servo motor spins the catapult arm (launches). The joystick reads two values which are mapped to output to the stepper and servo motor. The LCD screen displays the two values. The remote activates the launching sequence by pointing it at the receiver and pressing the power button.

Parts List (All from kit found on Amazon https://www.amazon.com/dp/B01CZTLHGE?psc=1&ref=ppx_yo2ov_dt_b_product_details):
Arduino UNO,
Servo motor,
Stepper motor,
Stepper motor controller board,
LCD screen,
Joystick,
IR receiver,
IR remote,
9 volt power adapter,
Bread board

I used the following libraries:

IR Receiver and Remote Library:

https://github.com/LuisMiCa/IRsmallDecoder/tree/master 

Liquid Crystal Display Library:

https://github.com/arduino-libraries/LiquidCrystal

Servo Motor Library:

https://github.com/arduino-libraries/Servo 

Stepper Motor Library:

https://github.com/arduino-libraries/Stepper 
