#include <BluetoothSerial.h>
BluetoothSerial btSerial;
#define BT_NAME "ESP32BT-SCT-Test" // Set bluetooth name

// Include Wire Library for I2C
#include <Wire.h>
 
// Include Adafruit PCA9685 Servo Library
#include <Adafruit_PWMServoDriver.h>
 
// Creat object to represent PCA9685 at default I2C address
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(0x40);

int bluetooth_signal = 0;

#define SERVOMIN  70  // Minimum value
#define SERVOMAX  520  // Maximum value
#define SER1  2
#define SER2  3
#define SER3  4
#define SER4  5

int pwm1, pwm2, pwm3, pwm4;
int arm_servo1_pos = 90, arm_servo2_pos = 90, arm_servo3_pos = 90, arm_servo4_pos = 50; 

void goForward(int leftSpeed, int rightSpeed)
{
  pca9685.setPWM(14, 4096, 0);
  pca9685.setPWM(15, 0, leftSpeed);
  pca9685.setPWM(12, 4096, 0);
  pca9685.setPWM(13, 0, leftSpeed);

  pca9685.setPWM(8, 0, rightSpeed);-
  pca9685.setPWM(9, 4096, 0);
  pca9685.setPWM(10, 0, rightSpeed);
  pca9685.setPWM(11, 4096, 0);
}

void turnRight(int leftSpeed, int rightSpeed)
{
  pca9685.setPWM(14, 4096, 0);
  pca9685.setPWM(15, 0, leftSpeed);
  pca9685.setPWM(12, 4096, 0);
  pca9685.setPWM(13, 0, leftSpeed);

  pca9685.setPWM(8, 4096, 0);
  pca9685.setPWM(9, 0, rightSpeed);
  pca9685.setPWM(10, 4096, 0);
  pca9685.setPWM(11, 0, rightSpeed);
}

void turnLeft(int leftSpeed, int rightSpeed)
{
  pca9685.setPWM(14, 0, leftSpeed);
  pca9685.setPWM(15, 4096, 0);
  pca9685.setPWM(12, 0, leftSpeed);
  pca9685.setPWM(13, 4096, 0);

  pca9685.setPWM(8, 0, rightSpeed);
  pca9685.setPWM(9, 4096, 0);
  pca9685.setPWM(10, 0, rightSpeed);
  pca9685.setPWM(11, 4096, 0);
}

void goBackward(int leftSpeed, int rightSpeed)
{
  pca9685.setPWM(14, 0, leftSpeed);
  pca9685.setPWM(15, 4096, 0);
  pca9685.setPWM(12, 0, leftSpeed);
  pca9685.setPWM(13, 4096, 0);

  pca9685.setPWM(8, 4096, 0);
  pca9685.setPWM(9, 0, rightSpeed);
  pca9685.setPWM(10, 4096, 0);
  pca9685.setPWM(11, 0, rightSpeed);
}

void stopBot()
{
  pca9685.setPWM(14, 0, 0);
  pca9685.setPWM(15, 0, 0);
  pca9685.setPWM(12, 0, 0);
  pca9685.setPWM(13, 0, 0);

  pca9685.setPWM(8, 0, 0);
  pca9685.setPWM(9, 0, 0);
  pca9685.setPWM(10, 0, 0);
  pca9685.setPWM(11, 0, 0);
}

void bluetoothControl()
{
  if (btSerial.available() > 0) 
  {
    bluetooth_signal = btSerial.read();
  }
  switch (bluetooth_signal)
  {

/*Robot moving control*/

    case 'a':
    {
      goForward(4096, 4096);
      break;
    }

    case 'b':
    {
      goBackward(4096, 4096);
      break;
    }

    case 'c':
    {
      turnLeft(4096, 4096);
      break;
    }

    case 'd':
    {
      turnRight(4096, 4096);
      break;
    }

    case 'e':
    {
      stopBot();
      break;
    }

    case 'p':
      if (arm_servo1_pos < 165)
      {
        arm_servo1_pos = (arm_servo1_pos + 1);
      }
 
    // Determine PWM pulse width
    pwm1 = map(arm_servo1_pos, 0, 180, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER1, 0, pwm1);
    delay(30);
    break;
    
    case 'q':
      if (arm_servo1_pos > 5)
      {
        arm_servo1_pos = (arm_servo1_pos - 1);
      }
 
    // Determine PWM pulse width
    pwm1 = map(arm_servo1_pos, 0, 180, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER1, 0, pwm1);
    delay(30);
    break;
      
    case 'h':
      if (arm_servo2_pos < 180)
      {
        arm_servo2_pos = (arm_servo2_pos + 1);
      }
    pwm2 = map(arm_servo2_pos, 0, 180, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER2, 0, pwm2);
    delay(30);
    break;
    
    case 'i':
      if (arm_servo2_pos > 10)
      {
        arm_servo2_pos = (arm_servo2_pos - 1);
      }
    pwm2 = map(arm_servo2_pos, 0, 180, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER2, 0, pwm2);
    delay(30);
    break;
      
    case 'j':
      if (arm_servo3_pos > 0)
      {
        arm_servo3_pos = (arm_servo3_pos - 1);
      }
    pwm3 = map(arm_servo3_pos, 0, 180, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER3, 0, pwm3);
    delay(30);
    break;
    
    case 'k':
      if (arm_servo3_pos < 180)
      {
      arm_servo3_pos = (arm_servo3_pos + 1);
      }
    pwm3 = map(arm_servo3_pos, 0, 180, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER3, 0, pwm3);
    delay(30);
    break;
      
    case 'l':
    pwm4 = map(45, 0, 180, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER4, 0, pwm4);
    delay(30);
    break;
    
    case 'm':
    pwm4 = map(107, 0, 180, SERVOMIN, SERVOMAX);
    // Write to PCA9685
    pca9685.setPWM(SER4, 0, pwm4);
    delay(30);
    break;

    case 'r':
      //xi nhan trai
      digitalWrite(2, 1);
      digitalWrite(32, 0);
    break;
        
    case 's':
      //xi nhan phai
      digitalWrite(2, 0);
      digitalWrite(32, 1);
    break;

    case 'f':
      digitalWrite(2, 0);
      digitalWrite(32, 0);
    break;
    case 'n':
      digitalWrite(2, 1);
      digitalWrite(32, 1);
    break;
  }
}

void servo_init()
{
    pwm1 = map(arm_servo1_pos, 0, 180, SERVOMIN, SERVOMAX);
    pwm2 = map(arm_servo2_pos, 0, 180, SERVOMIN, SERVOMAX);
    pwm3 = map(arm_servo3_pos, 0, 180, SERVOMIN, SERVOMAX);
    pwm4 = map(arm_servo4_pos, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER1, 0, pwm1);
    delay(30);
    pca9685.setPWM(SER2, 0, pwm2);
    delay(30);
    pca9685.setPWM(SER3, 0, pwm3);
    delay(30);
    pca9685.setPWM(SER4, 0, pwm4);
    delay(30);

}
void setup() 
{
  Serial.begin(115200);
  btSerial.begin(BT_NAME);

  // Initialize PCA9685
  pca9685.begin();
 
  // Set PWM Frequency to 50Hz
  pca9685.setPWMFreq(50);

  //servo_init();
  pinMode(2, OUTPUT);
  pinMode(32, OUTPUT);
  digitalWrite(2, 0);
  digitalWrite(32, 0);
}

void loop() 
{
  bluetoothControl();
}