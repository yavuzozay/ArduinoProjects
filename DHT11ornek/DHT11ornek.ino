#include <dht11.h>
#define DHT11PIN 12

dht11 DHT11;
float sicaklik;
float nem=0.0;

void setup() {
  // yüklenirken
    Serial.begin(9600); // Seri iletişimi başlatıyoruz.
  delay(2000);        // 2sn bekleme
  Serial.println("DHT11 Test Programi");  // seri porttan bilgilendirme

}
void Kontrol()
{
  if(sicaklik<=25&&sicaklik>=20&&nem<=40&&nem>=60)
  {
    digitalWrite(10,HIGH);
     digitalWrite(9,LOW);
      digitalWrite(8,LOW);
       digitalWrite(7,LOW);
        digitalWrite(6,LOW);
     
    //STABİL
  }
  else if(sicaklik<20)
  {
     digitalWrite(9,HIGH);
      digitalWrite(8,LOW);
     Serial.println("Dusuk sicaklik ");
  }
  else if(sicaklik>25)
  {
     digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
     Serial.println("Yüksek sicaklik ");
  }

 
  else if(nem<40)
  {
     digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
  }
  else if(nem>60)
  {
     digitalWrite(7,LOW);
     digitalWrite(6,HIGH);
  }
}
void loop() {
  // döngü

  DHT11.read(12); 
  Serial.print("Nem (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Sicaklik (Celcius): ");
  Serial.println(sicaklik);

  sicaklik=(float)DHT11.temperature;
  nem=(float)DHT11.humidity;
  Kontrol();
  delay(2000);

}
