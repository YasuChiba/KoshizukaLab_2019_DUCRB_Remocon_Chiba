
int irPIN = 3;

void setup()
{
 Serial.begin(9600);
 pinMode(irPIN, OUTPUT);
}

void loop() 
{
  
  for (int i = 0; i < 50000; i++) { 
    digitalWrite(irPIN, HIGH);
    delay(3);
    digitalWrite(irPIN, LOW);
    delay(3);
  }
 
 
}
