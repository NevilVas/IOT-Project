
#include <Blynk.h>
#include <SimpleDHT.h>


#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

#include <SoftwareSerial.h>

#define BLYNK_PRINT Serial

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

char auth[] = "A4dvk3fk7M_hIVOuR0wSfpse2N9lYRkM";

// Your WiFi credentials.
char ssid[] = "Doobie";
char pass[] = "meghana@123";


SoftwareSerial EspSerial(2, 3); // RX, TX



int pinDHT11 = 8;
SimpleDHT11 dht11(pinDHT11);

ESP8266 wifi(&EspSerial);

BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  int val;
  val = analogRead(A0);
 
  int newval;
  newval = map(val, 0, 1023, 0, 100);
  Serial.println(newval);
  Blynk.virtualWrite(V5, newval);
  if (newval >= 20) {
   
    Blynk.notify("Water plants!");
  }

}
int motor1pin1 = 4;
int motor1pin2 = 5;

byte temperature = 0;
byte humidity = 0;

void setup()
{
  // Debug console
  Serial.begin(9600);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
  Blynk.notify("HEllo");
}

BLYNK_WRITE(V3) {
 int pinValue = param.asInt(); // Assigning incoming value from pin V3 to a variable
 if (pinValue == 1) {
    digitalWrite(motor1pin1, HIGH); // Turn motor on.
  } else {
    digitalWrite(motor1pin1, LOW); // Turn motor off.
 }
 
}
   
void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
  //Serial.print((int)temperature); Serial.print("*C,"); 
  //Serial.print((int)humidity); Serial.println(" H");
  Blynk.virtualWrite(V4, (int)humidity);
  delay(1500);
  
  
}
