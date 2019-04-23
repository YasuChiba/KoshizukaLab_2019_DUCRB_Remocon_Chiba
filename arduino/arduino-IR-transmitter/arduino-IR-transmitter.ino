
int irPIN = 3;

void setup()
{
 Serial.begin(9600);
 pinMode(irPIN, OUTPUT);
 digitalWrite(irPIN, LOW);
}

void one() {
  digitalWrite(irPIN, HIGH);
  delayMicroseconds(500);
  digitalWrite(irPIN, LOW);
  delayMicroseconds(500);
}

void zero() {
  digitalWrite(irPIN, HIGH);
  delayMicroseconds(500);
  digitalWrite(irPIN, LOW);
  delayMicroseconds(250);
}

void loop() 
{
  digitalWrite(irPIN, HIGH);
  delay(3);
  digitalWrite(irPIN, LOW);
  delay(3);
  one();
  zero();
  one();
  one();
  one();
  zero();
  zero();
  delay(2000);
}
