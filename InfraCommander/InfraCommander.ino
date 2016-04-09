#include <IRLib.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(8, 9); // RX, TX
int RECV_PIN = 11;
int Pow_PIN  = 13;

IRrecv My_Receiver(RECV_PIN);
IRdecode My_Decoder;
IRdecodeHash My_Hash_Decoder;

void setup()
{
  My_Receiver.enableIRIn(); // Start the receiver
  //Serial.begin(9600);
   mySerial.begin(9600);
  pinMode(Pow_PIN, OUTPUT);
}

void loop() {
  digitalWrite(Pow_PIN, HIGH);
  if (My_Receiver.GetResults(&My_Decoder)) {//Puts results in My_Decoder
    My_Decoder.decode();
    //Serial.println(My_Decoder.value, HEX);
    mySerial.println(My_Decoder.value, HEX);
    delay(100);
    My_Receiver.resume(); 
  }
}

