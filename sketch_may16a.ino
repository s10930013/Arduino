#include <SimpleDHT.h>
int pinDHT11 = 4;
SimpleDHT11 dht11(pinDHT11);




void setup() {
  Serial.begin(115200);
  pinMode(15, OUTPUT);//選告GPIO15作為輸出（綠色LED）
  pinMode(2, OUTPUT);//選告GPIO 2作為輸出（黃色LED)
  //pinMode(0, OUTPUT);//選告GPIO 0作為輸出（黃色LED）
  pinMode(16, OUTPUT);//選告GPIO 4作為輸出（紅色LED）
  //pinMode(13, INPUT);//選告GPIO 13作為輸入（溫溼度讀取）
}

void loop() {
  Serial.println("Sample DHT11...");
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;}
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");  
  // DHT11 sampling rate is 1HZ
  delay(1500);
  
  if ((int)humidity < 65) {
    //小於65，代表濕度舒適亮綠燈
    digitalWrite(15, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(16, LOW);
    }


  if ((int)humidity >= 65 && (int)humidity < 80) {
    //65-80之間，代表濕度偏溼亮黃綠燈
    digitalWrite(15, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(16, LOW);
  }
  if ((int)humidity > 80) {
    //80以上，代表濕度潮溼亮紅黃綠燈
    digitalWrite(15, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(16, HIGH);
  }
  delay(1500);
  
}
