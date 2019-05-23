#define SensorSol 10  
#define SensorOrta 11
#define SensorSag 12

#define MotorR1 6
#define MotorR2 7 
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

  pinMode(MotorR1, OUTPUT); 
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
  if(Serial.available()>0){         
      veri = Serial.read();           
      Serial.println(veri);
    }
  if(veri=='f'){  
    //   sayac=100;
    ileri();
  }if(veri=='l'){  
    sag();
  }
  if(veri=='r'){  
    sol();
  }
  if(veri=='b'){  
    geri();
  }
  if(veri=='s'){
    dur();
    bekleme=5;
  }  if(veri=='a'){
    
      if(Serial.available()>0){         
      veri = Serial.read();           
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
        if(digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 0){  
            ileri();
        }
        if(digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 1){ 
            ileri();  
        }
      if(digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 1){  
        sag();
        }
        if(digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 0){  
        sol();
      }
        if(digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 1){
        sag();
      }  if(digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 1){  
        sol();
      }
     
      if(digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 0){  
        sol();
      }if(digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 0){ 

          ileri();
     
      }
  }else if(distance<=20){
    dur();
  }
 }
}
  


  
}

void geri(){  
  //sayac-=1;
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH); 
  analogWrite(MotorRE, 90); 
  digitalWrite(MotorL1, LOW); 
  digitalWrite(MotorL2, HIGH); 
  analogWrite(MotorLE, 90); 
      delay(100);

}
void ileri(){  

  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 100); 
  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, 94); 
}







void dur(){ 
  melodi(distance*10);
  digitalWrite(MotorLE, LOW);
  digitalWrite(MotorRE, LOW);

  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);

  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);



}
void sol(){ 
  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW);
  analogWrite(MotorRE, 0); 
  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, 107); 
}

void sag(){ 

  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW);
  analogWrite(MotorRE, 107); 

  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, 0); 

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
  //tone(buzzerPin,440);
    digitalWrite(buzzerPin,HIGH);
    delay(500);
    digitalWrite(buzzerPin,LOW);
 // noTone(buzzerPin);
   delay(500);

}
