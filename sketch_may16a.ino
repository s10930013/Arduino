#include <SimpleDHT.h>
int pinDHT11 = 4;
SimpleDHT11 dht11(pinDHT11);




void setup() {
  Serial.begin(115200);
  pinMode(15, OUTPUT);//選告GPIO15作為輸出（綠色LED）
  pinMode(2, OUTPUT);//選告GPIO 2作為輸出（黃色LED)
  pinMode(0, OUTPUT);//選告GPIO 0作為輸出（黃色LED）
  pinMode(4, OUTPUT);//選告GPIO 4作為輸出（紅色LED）
  //pinMode(13, INPUT);//選告GPIO 13作為輸入（溫溼度讀取）
}

void loop() {
  
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");  
  // DHT11 sampling rate is 1HZ
 
  //LightValue = analogRead(13); //讀取的GPIO 13讀取的數值放在LightValue
 // Serial.println(LightValue); //LightValue顯示在序列視窗
  if ((int)humidity < 50) {
    //小於500，代表亮度充足，關閉所有LED
    digitalWrite(15, LOW);
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    }
  }


 .

  
  if ((int)humidity>= 50 && (int)humidity < 60) {
    //500-1000之間，代表亮度中等
    digitalWrite(15, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
  }
  if ((int)humidity >= 60 && (int)humidity < 70) {
    //1000-2000之間，代表亮度不足
    digitalWrite(15, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
  }
  if ((int)humidity > 80) {
    //2000以上，代表完全無燈光
    digitalWrite(15, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(100);
}
