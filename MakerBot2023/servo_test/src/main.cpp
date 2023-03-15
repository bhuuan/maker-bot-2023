// Include Wire Library for I2C
#include <Wire.h>
 
// Include Adafruit PCA9685 Servo Library
#include <Adafruit_PWMServoDriver.h>
 
// Creat object to represent PCA9685 at default I2C address
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(0x40);


//#define SERVOMIN  70  // Minimum value
//#define SERVOMAX  520  // Maximum value
#define SERVOMIN  70  // Minimum value
#define SERVOMAX  520  // Maximum value
#define SER1  4

int pwm1, pwm2, pwm3, pwm4, pwm5;
int arm_servo1_pos = 0; 

void setup() {
  // put your setup code here, to run once:
  // Initialize PCA9685
  pca9685.begin();
 
  // Set PWM Frequency to 50Hz
  pca9685.setPWMFreq(50);

    arm_servo1_pos = 0;
    pwm1 = map(arm_servo1_pos, 0, 180, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER1, 0, pwm1);
    delay(5000);
    
    arm_servo1_pos = 180;
    pwm1 = map(arm_servo1_pos, 0, 180, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER1, 0, pwm1);
    delay(5000);
    
    arm_servo1_pos = 70;
    pwm1 = map(arm_servo1_pos, 0, 180, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER1, 0, pwm1);
    delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
}