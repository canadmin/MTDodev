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

//bluetooth
#define echoPin 33
#define trigPin 32
#define buzzerPin 30
#define yakinlikVcc 31

long duration, distance;

int maximumRange = 15;
int minimumRange = 0;
int yakinlik;
int boole=0;
char veri; 
int sayac;
int bekleme=5;

void setup() {

  // sayac=100;
  
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

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(yakinlikVcc, OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {
   digitalWrite(8,HIGH);
          digitalWrite(yakinlikVcc,HIGH);
   digitalWrite(yakinlikVcc,HIGH);
   digitalWrite(8,HIGH);
   digitalWrite(trigPin,LOW);
   delayMicroseconds(3);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   digitalWrite(8,HIGH);
   duration = pulseIn(echoPin, HIGH);
   distance=duration/29.1/2;
  if(Serial.available()>0){         //Seri haberleşmeden veri gelmesini bekliyoruz.
      veri = Serial.read();           //Seri haberleşmeden gelen veriyi okuyoruz.
      Serial.println(veri);
    }
  if(veri=='f'){  // Orta sensör çizgiyi gördüğünde robot ileri gitsin.
    //   sayac=100;
    ileri();
  }if(veri=='l'){  // Sağ sensör çizgiyi gördüğünde robot sağa dönsün.
    sag();
  }
  if(veri=='r'){  // Sol sensör çizgiyi gördüğünde robot sola dönsün.
    sol();
  }
  if(veri=='b'){  // Sol sensör çizgiyi gördüğünde robot sola dönsün.
    geri();
  }
  if(veri=='s'){
    dur();
    bekleme=5;
  }  if(veri=='a'){
    
      if(Serial.available()>0){         //Seri haberleşmeden veri gelmesini bekliyoruz.
      veri = Serial.read();           //Seri haberleşmeden gelen veriyi okuyoruz.
      Serial.println(veri);
  
    }
     digitalWrite(8,HIGH);
      digitalWrite(yakinlikVcc,HIGH);
      if(bekleme<=5){
      baslangicMelodisi();
      bekleme++;
      baslangicMelodisi();
      bekleme++;
      baslangicMelodisi();
      bekleme++;
      baslangicMelodisi();
      bekleme++;
      baslangicMelodisi();
      bekleme++;
    }else{
       if(distance>20){
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
      }  if(digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 1){  // Sağ sensör çizgiyi gördüğünde robot sağa dönsün.
        sol();
      }
     
      if(digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 0){  //
        sol();
      }if(digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 0){  // araba çizginin dışına çıktığında geri dönsün

          ileri();
     
      }
  }else if(distance<=20){
    dur();
  }
 }
}
  


  
}

void geri(){  // Robot çizginin dışına çıktığında geri gelicek
  //sayac-=1;
  digitalWrite(MotorR1, LOW); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, HIGH); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 90); // Sağ motorun hızı 150
  digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, HIGH); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 90); // Sol motorun hızı 1501 
      delay(100);

}
void ileri(){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 100); // Sağ motorun hızı 110
  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 94); // Sol motorun hızı 104
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
  analogWrite(MotorLE, 107); // Sol motorun hızı 130
}

void sag(){ // Robotun sola dönme hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 107); // Sağ motorun hızı 130

  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 0); // Sol motorun hızı 0 (Motor duruyor)

}
void melodi(int dly)
{ int snsr=dly/10;
  if(snsr<20){
  tone(buzzerPin, 440);
  delay(dly);
  noTone(buzzerPin);
  delay(dly);
  }
  
}
void baslangicMelodisi(){
  tone(buzzerPin,440);
  delay(500);
  noTone(buzzerPin);
  delay(500);
}
