#include <SoftwareSerial.h>// import the serial library

SoftwareSerial plaviZub(12, 13); // RX, TX

int bluetoothInt;
String bluetoothString;
int relayPin = 5;
int led = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  plaviZub.begin(9600);

  Serial.println("Krecemo");
  plaviZub.println("Krecemo");
  
  pinMode(relayPin, OUTPUT);     
  pinMode(led, OUTPUT);     

}

void loop() {
  
  if (plaviZub.available())
  {
    bluetoothInt = plaviZub.read();
    Serial.print("Dobiveno preko zuba: ");
    Serial.println( char(bluetoothInt) );
    digitalWrite(relayPin, HIGH);
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    digitalWrite(relayPin, LOW);
  }
  
  if(Serial.available() > 0)
  {
    bluetoothInt = Serial.read();
    Serial.print("Poslano s kompa: ");
    Serial.println(bluetoothInt);
    
    plaviZub.print("Poslano s kompa: ");
    plaviZub.println(bluetoothInt);

    digitalWrite(relayPin, HIGH);
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    digitalWrite(relayPin, LOW);
  }
  delay(50);// prepare for next data ...
}

