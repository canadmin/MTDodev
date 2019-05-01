int veri;                           //Bluetooth üzerinden okuduğumuz değişken.
void setup() {
  Serial.begin(9600);               //Seri haberleşmeyi başlatıyoruz.
  pinMode(13,OUTPUT);
}
void loop() {
  if(Serial.available()>0){         //Seri haberleşmeden veri gelmesini bekliyoruz.
    veri = Serial.read();           //Seri haberleşmeden gelen veriyi okuyoruz.
    Serial.println(veri);
  }
  if(veri=='1'){
    digitalWrite(13,1);
  }
  if(veri=='0'){
        digitalWrite(13,0);

  }
  

}
