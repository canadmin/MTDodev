#define SensorSol 10  
#define SensorOrta 11
#define SensorSag 12

#define MotorR1 6
#define MotorR2 7 // Sensör ve Motorların Arduino'ya bağladığımız pinlerini tanımlıyoruz.
#define MotorRE 9

#define MotorL1 4
#define MotorL2 5
#define MotorLE 3


//sensor
#define echoPin 33
#define trigPin 32
#define buzzerPin 30
#define yakinlikVcc 31
    long duration, distance;

int maximumRange = 7;
int minimumRange = 0;
boolean dursunMu=false;

void setup() {

  Serial.begin(9600);
  pinMode(SensorSol, INPUT);
  pinMode(SensorOrta, INPUT);
  pinMode(SensorSag, INPUT);

  pinMode(MotorR1, OUTPUT); // Sensör ve Motorların Giriş-Çıkış bilgilerini belirtiyoruz.
  pinMode(MotorR2, OUTPUT);

  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(yakinlikVcc, OUTPUT);


}

void loop() {
    digitalWrite(yakinlikVcc,HIGH);
  

  digitalWrite(trigPin,LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  

  duration = pulseIn(echoPin, HIGH);
  distance=duration/29.1/2;
  Serial.println(distance);
  // melodi(distance*10);
  if(distance>10){
      
    if(digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 0){  // Orta sensör çizgiyi gördüğünde robot ileri gitsin.
        ileri();
    }
    if(digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 1){  // Orta sensör çizgiyi gördüğünde robot ileri gitsin.
   
        ileri();  
    }

    if(digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 1){  // Sağ sensör çizgiyi gördüğünde robot sağa dönsün.
    sag();
  }
  if(digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 0){  // Sol sensör çizgiyi gördüğünde robot sola dönsün.
    sol();
  }
    if(digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 1){  // Sağ sensör çizgiyi gördüğünde robot sağa dönsün.
    sag();
  }
  if(digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 0){  // Sol sensör çizgiyi gördüğünde robot sola dönsün.
    sol();
  }
  }
  if(distance<=10){
    dur();
  }
     
  


  
}


void ileri(){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 88); // Sağ motorun hızı 150
  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 75); // Sol motorun hızı 1501 
}




void dur(){ // Robotun durma hareketi için fonksiyon tanımlıyoruz.
  melodi(distance*10);
  
  digitalWrite(MotorLE, LOW);
  digitalWrite(MotorRE, LOW);

  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);

  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);

}
void sol(){ // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.
  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 0); // Sağ motorun hızı 0 (Motor duruyor)
  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 75); // Sol motorun hızı 150

  
}

void sag(){ // Robotun sola dönme hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 80); // Sağ motorun hızı 150

  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 0); // Sol motorun hızı 0 (Motor duruyor)
  
}

void melodi(int dly)
{
  int snsr=dly/10;
  if(snsr<25){
  tone(buzzerPin, 440);
  delay(dly);
  noTone(buzzerPin);
  delay(dly);
  }
  
}
