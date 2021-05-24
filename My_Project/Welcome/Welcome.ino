#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 20 chars and 4 line display

int servopin = 2;
int i;
Servo motor;

#define STEPPER_PIN_1 8
#define STEPPER_PIN_2 9
#define STEPPER_PIN_3 10
#define STEPPER_PIN_4 11
int step_number = 0;

int st1 = 3;
void setup()
{
  lcd.init();               // initialize the lcd 
  lcd.backlight();          // backlight turn on

  motor.attach(servopin);   // Servo motor pin initialize

        pinMode(STEPPER_PIN_1, OUTPUT);   // Stepper motor pin initialize start
        pinMode(STEPPER_PIN_2, OUTPUT);
        pinMode(STEPPER_PIN_3, OUTPUT);
        pinMode(STEPPER_PIN_4, OUTPUT);   // Stepper motor pin initialize stop
  
   // Print a message to the LCD.
  lcd.setCursor(2,0);
  lcd.print(" Welcome To My ");
  lcd.setCursor(3,1);
  lcd.print("Digiterduino!");
  delay(1000);
  lcd.clear();
  delay(1000);
}


void loop()
{
  servomotor1();        //Calling servomotor1()
  servomotor2();        //Calling servomotor2()

    lcd.setCursor(0,0);
    lcd.print("Stepper motor is "); 
    lcd.setCursor(0,1);
    lcd.print("starting");
    delay(2000);
    lcd.clear();
    
    for(int st = 0; st < st1 ; st++)
    {
      steppermotor();
    }    
}

void servomotor1()                    //////////Servo Motor 1 main Function Starting
{
    // put your main code here, to run repeatedly:

    lcd.setCursor(0,0);
    lcd.print("Servo motor is "); 
    lcd.setCursor(0,1);
    lcd.print("starting"); 
    lcd.setCursor(0,2);
    lcd.print("Position-> 0 Degree");
    delay(500);
  motor.write(0);
  delay(1000);
  lcd.clear();
  
    direction();
    anticlock();
    angle(90);
  motor.write(90);
  delay(2000);
  lcd.clear();
  
    direction();
    anticlock();
    angle(180);
  motor.write(180);
  delay(2000);
  lcd.clear();

    direction();
    clock();
    angle(-180);

  for(i = 180; i >= 0; i=i-5)
  {
    motor.write(i);
    delay(100);
  }
  delay(2000);
  lcd.clear();

}                                   //////////Servo Motor 1 main Function Ending

void servomotor2()                  //////////Servo Motor 2 main Function Starting
{
    direction();
    anticlock();
    angle(90);
  motor.write(90);
  delay(1000);
  lcd.clear();
  
    direction();
    anticlock();
    angle(180);
  motor.write(180);
  delay(1000);
  lcd.clear();

    direction();
    clock();
    angle(-180);
  motor.write(0);
  delay(1000);
  lcd.clear();
}                                   //////////Servo Motor 1 main Function Ending

void direction()                    /////Sub Function Starting
{
    lcd.setCursor(0,0);
    lcd.print("Direction : "); 
}
void rotation()
{
    lcd.setCursor(0,0);
    lcd.print("Rotation : "); 
}
void anticlock()
{ 
    lcd.setCursor(0,1);
    lcd.print("AntiClock Wise");
}
void clock()
{ 
    lcd.setCursor(0,1);
    lcd.print("Clock Wise");
}
void angle(int an)
{
  lcd.setCursor(0,2);
  lcd.print("Angle-> ");
  lcd.print(an);
  lcd.print(" Degree");
}                                   /////Sub Function Ending

void steppermotor()                 //////////Stepper Motor main Function Starting
{
  rotation();
  anticlock();
  delay(500);
  for(int a = 0; a < 2020; a++)
  {
    OneStep(false);
    delay(2);
  }
  lcd.clear();

  rotation();
  clock();
  delay(500);
  for(int a = 0; a < 2020; a++)
  {
    OneStep(true);
    delay(2);
  }
  lcd.clear();
}                                 //////////Stepper Motor main Function Ending

void OneStep(bool dir){           /////Stepper Motor sub Function Starting
    if(dir){
switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
} 
  }else{
    switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
 
  
} 
  }
step_number++;
  if(step_number > 3){
    step_number = 0;
  }
}                                 /////Stepper Motor sub Function Ending
