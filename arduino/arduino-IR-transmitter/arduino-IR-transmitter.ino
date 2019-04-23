
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
  one();
  one();
  one();
  one();
  zero();
  one();
  zero();
  one();
  delay(2000);
}
