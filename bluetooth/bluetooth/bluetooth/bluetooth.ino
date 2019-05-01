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


int maximumRange = 30;
int minimumRange = 0;
int yakinlik;
int boole=0;
char veri;    //Bluetooth üzerinden okuduğumuz değişken.

void setup() {
    Serial.begin(9600);               //Seri haberleşmeyi başlatıyoruz.

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
  pinMode(8,OUTPUT);


}

void loop() {
      digitalWrite(8,HIGH);

  if(Serial.available()>0){         //Seri haberleşmeden veri gelmesini bekliyoruz.
      veri = Serial.read();           //Seri haberleşmeden gelen veriyi okuyoruz.
      Serial.println(veri);
    }
  if(veri=='f'){  // Orta sensör çizgiyi gördüğünde robot ileri gitsin.
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
  }
  
  
}


void ileri(){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 153); // Sağ motorun hızı 150
  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 141); // Sol motorun hızı 150

  
}


void geri(){  // Robot çizginin dışına çıktığında geri gelicek
 

  digitalWrite(MotorR1, LOW); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, HIGH); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 65); // Sağ motorun hızı 150
  digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, HIGH); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 65); // Sol motorun hızı 1501 

}

void sol(){ // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.
  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 0); // Sağ motorun hızı 0 (Motor duruyor)
  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 150); // Sol motorun hızı 150

  
}

void sag(){ // Robotun sola dönme hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 150); // Sağ motorun hızı 150

  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 0); // Sol motorun hızı 0 (Motor duruyor)
  
}

void dur(){ // Robotun durma hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorRE, LOW);

  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorLE, LOW);

}
