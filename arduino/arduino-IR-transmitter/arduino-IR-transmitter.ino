
int irPIN = 3;

void setup()
{
 Serial.begin(9600);
 pinMode(irPIN, OUTPUT);
}

void loop() 
{
  //digitalWrite(irPIN, HIGH);
 
  for (int i = 0; i < 50; i++) { 
    digitalWrite(irPIN, HIGH);
    delay(100);
    digitalWrite(irPIN, LOW);
    delay(100);
  }
 
}
