// Thêm bộ thư viện
// Add the library.
#include "Makerlabvn_I2C_Motor_Driver.h"

// Khai báo module.
// Declare module.
Makerlabvn_I2C_Motor_Driver myDriver(0);

// khai báo chân đọc tín hiệu
int PWMPin[6] = {2, 3, 4, 5, 6, 7};
// int PWMPin[6] = {2, 3, A3, A2, A1, A0};
String PWMName[6] = {"s1Pin", "s2Pin", "MB0", "MB1", "MA1", "MA0"};
int PWMValue_new[6];
int PWMValue_old[6];
int passLed = 9;
int warning = 10;

void setup()
{
  // Khởi động kết nối Serial UART ở tốc độ 115200 để truyền dữ liệu lên máy tính.
  // Start the Serial UART connection at 115200 to transfer data to the computer.
  Serial.begin(115200);

  // Khởi tạo module
  // init module
  myDriver.begin();
  resetAll();

  // set chan doc tin hieu
  for(int i=0; i<6; i++)
    pinMode(PWMPin[i], INPUT);

  pinMode(passLed, OUTPUT);
  pinMode(warning, OUTPUT);

  // check signal
  checkSignal();

  // check servo
  checkServoPin();

  // check motor
  checkMotorPin();

  digitalWrite(passLed, 1);

}

void loop()
{
  
}

void resetAll(){
  myDriver.S1(0);
  myDriver.S2(0);
  myDriver.MA(0, 0);
  myDriver.MB(0, 0);
  delay(50);
}

void readPWM(int arr[6]){
  for(int i=0; i<6; i++){
    if(i<2)
      arr[i] = pulseIn(PWMPin[i], HIGH);
    else
      arr[i] = digitalRead(PWMPin[i]);
  }
}

void checkSignal(){
  resetAll();

  //checkS1
  myDriver.S1(100);
  delay(1);
  if((pulseIn(PWMPin[0], HIGH)<90) || (pulseIn(PWMPin[0], HIGH)>110)){
    Serial.println("S1 signal err");
    Serial.println(pulseIn(PWMPin[0], HIGH));
    digitalWrite(warning, 1);
    while(1);
  }
  myDriver.S1(0);

  //checkS2
  myDriver.S2(100);
  delay(10);
  if((pulseIn(PWMPin[1], HIGH)<90) || (pulseIn(PWMPin[1], HIGH)>110)){
    Serial.println("S2 signal err");
    Serial.println(pulseIn(PWMPin[1], HIGH));
    digitalWrite(warning, 1);
    while(1);
  }
  myDriver.S2(0);

  //checkMB0
  myDriver.MB(0,255);
  delay(10);
  if(digitalRead(PWMPin[2]) != 1){
    Serial.println("MB0 signal err");
    Serial.println(digitalRead(PWMPin[2]));
    digitalWrite(warning, 1);
    while(1);
  }
  myDriver.MB(0,0);

  //checkMB1
  myDriver.MB(1,255);
  delay(10);
  if(digitalRead(PWMPin[3]) != 1){
    Serial.println("MB1 signal err");
    Serial.println(digitalRead(PWMPin[3]));
    digitalWrite(warning, 1);
    while(1);
  }
  myDriver.MB(0,0);

  //checkMA1
  myDriver.MA(1,255);
  delay(10);
  if(digitalRead(PWMPin[4]) != 1){
    Serial.println("MA1 signal err");
    Serial.println(digitalRead(PWMPin[4]));
    digitalWrite(warning, 1);
    while(1);
  }
  myDriver.MA(0,0);

  //checkMA0
  myDriver.MA(0,255);
  delay(10);
  if(digitalRead(PWMPin[5]) != 1){
    Serial.println("MA0 signal err");
    Serial.println(digitalRead(PWMPin[5]));
    digitalWrite(warning, 1);
    while(1);
  }
  myDriver.MA(0,0);
}

void checkServoPin(){
  // check s1
  readPWM(PWMValue_old);
  myDriver.S1(100);

  readPWM(PWMValue_new);
  if((PWMValue_new[0]<=110) && (PWMValue_new[0]>=90)){
    if(PWMValue_new[1] != PWMValue_old[1]){
      resetAll();
      Serial.println("S2 thay doi khi set s1");
      Serial.println("S2 old: " + String(PWMValue_old[1]));
      Serial.println("S2 new: " + String(PWMValue_new[1]));
      while(1);
    }
    else{
      myDriver.S1(0);
      // Serial.println("S1 oke");
    }
  }
  else{
    resetAll();
    Serial.println("khong set duoc S1");
    while(1);
  }
  // check s2
  readPWM(PWMValue_old);
  myDriver.S2(100);

  readPWM(PWMValue_new);
  if((PWMValue_new[1]<=110) && (PWMValue_new[1]>=90)){
    if(PWMValue_new[0] != PWMValue_old[0]){
      resetAll();
      Serial.println("S1 thay doi khi set s2");
      Serial.println("S1 old: " + String(PWMValue_old[0]));
      Serial.println("S1 new: " + String(PWMValue_new[0]));
      while(1);
    }
    else{
      myDriver.S2(0);
      // Serial.println("S2 oke");
    }
  }
  else{
    resetAll();
    Serial.println("khong set duoc S2");
    while(1);
  }
}

void checkMotorPin(){
  //check MA0
  readPWM(PWMValue_old);
  myDriver.MA(0,255);
  readPWM(PWMValue_new);
  if(PWMValue_new[5] == 1){
    if(PWMValue_new[4] != 1){
      myDriver.MA(0,0);
      // Serial.println("MA0 oke");
    }
    else{
      resetAll();
      Serial.println("MA1 thay doi khi set MA0");
      Serial.println("MA1 old: " + String(PWMValue_old[4]));
      Serial.println("MA1 new: " + String(PWMValue_new[4]));
      while(1);
    }
  }
  else{
    resetAll();
    Serial.println("khong set duoc MA0");
    while(1);
  }

  //check MA1
  readPWM(PWMValue_old);
  myDriver.MA(1,255);
  readPWM(PWMValue_new);
  if(PWMValue_new[4] == 1){
    if(PWMValue_new[5] != 1){
      myDriver.MA(0,0);
      // Serial.println("MA1 oke");
    }
    else{
      resetAll();
      Serial.println("MA0 thay doi khi set MA1");
      Serial.println("MA0 old: " + String(PWMValue_old[5]));
      Serial.println("MA0 new: " + String(PWMValue_new[5]));
      while(1);
    }
  }
  else{
    resetAll();
    Serial.println("khong set duoc MA1");
    while(1);
  }

  //check MB1
  readPWM(PWMValue_old);
  myDriver.MB(1,255);
  readPWM(PWMValue_new);
  if(PWMValue_new[3] == 1){
    if(PWMValue_new[2] != 1){
      myDriver.MB(0,0);
      // Serial.println("MB1 oke");
    }
    else{
      resetAll();
      Serial.println("MB0 thay doi khi set MB1");
      Serial.println("MB0 old: " + String(PWMValue_old[2]));
      Serial.println("MB0 new: " + String(PWMValue_new[2]));
      while(1);
    }
  }
  else{
    resetAll();
    Serial.println("khong set duoc MB1");
    while(1);
  }

  //check MB0
  readPWM(PWMValue_old);
  myDriver.MB(0,255);
  readPWM(PWMValue_new);
  if(PWMValue_new[2] == 1){
    if(PWMValue_new[3] != 1){
      myDriver.MB(0,0);
      // Serial.println("MB0 oke");
    }
    else{
      resetAll();
      Serial.println("MB1 thay doi khi set MB0");
      Serial.println("MB1 old: " + String(PWMValue_old[3]));
      Serial.println("MB1 new: " + String(PWMValue_new[3]));
      while(1);
    }
  }
  else{
    resetAll();
    Serial.println("khong set duoc MB0");
    while(1);
  }
}

