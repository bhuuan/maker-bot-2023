#define SEN_1_PIN 39
#define SEN_2_PIN 36
#define SEN_3_PIN 2
#define SEN_4_PIN 32

char cRead_Sensor(void)
{
  short sSen_Pin[4] = {SEN_1_PIN, SEN_2_PIN, SEN_3_PIN, SEN_4_PIN};
  char cStatus = 0b00000000;

  for(short i=0; i<4; i++)
  {
    cStatus = cStatus | (digitalRead(sSen_Pin[i]) << i);
  }

  return cStatus;
}

void lineFollowing()
{
  char cSen_Status = 0b00000000;
  cSen_Status = cRead_Sensor();
  Serial.println(cSen_Status);
  if((cSen_Status == 0b00001001) || (cSen_Status == 0b00001011) || (cSen_Status == 0b00001101))
  {
    goForward();
  }
  else if((cSen_Status == 0b00001110) || (cSen_Status == 0b00001100) || (cSen_Status == 0b00001000))
  {
    turnRight();
  }
  else if((cSen_Status == 0b00000111) || (cSen_Status == 0b00000011) || (cSen_Status == 0b00000001))
  {
    turnLeft(); 
  }
  else if(cSen_Status == 0b00001111)
  {
    goBackward();  
  }
}