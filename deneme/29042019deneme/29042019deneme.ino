s

void setup() {

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
  if(distance>10){
      
        if(digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 0){  // Orta sensör çizgiyi gördüğünde robot ileri gitsin.
            ileri();
        }
        else if(digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 1){  // Orta sensör çizgiyi gördüğünde robot ileri gitsin.
            ileri();  
        }
        else if(digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 1){  // Sağ sensör çizgiyi gördüğünde robot sağa dönsün.
        sag();
        }
      else if(digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 0){  // Sol sensör çizgiyi gördüğünde robot sola dönsün.
        sol();
      }
        else if(digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 1){  // Sağ sensör çizgiyi gördüğünde robot sağa dönsün.
        sag();
      }
      else if(digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 0){  //
        sol();
      }else if(digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 0){  // araba çizginin dışına çıktığında geri dönsün
        geri();
      }
  }else if(distance<=10){
    dur();
  }
     
  


  
}
void ileri(){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 101); // Sağ motorun hızı 150
  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 98); // Sol motorun hızı 1501 
}


void geri(){  // Robot çizginin dışına çıktığında geri gelicek
 

  digitalWrite(MotorR1, LOW); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, HIGH); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 65); // Sağ motorun hızı 150
  digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, HIGH); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 65); // Sol motorun hızı 1501 
      delay(100);

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
  analogWrite(MotorLE, 100); // Sol motorun hızı 150
}

void sag(){ // Robotun sola dönme hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 100); // Sağ motorun hızı 150

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


  
