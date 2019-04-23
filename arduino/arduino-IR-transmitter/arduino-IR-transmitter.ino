
int irPIN = 3;

void setup()
{
 Serial.begin(9600);
 pinMode(irPIN, OUTPUT);
 digitalWrite(irPIN, LOW);
}

void one() {
  digitalWrite(irPIN, HIGH);
  delay(3);
  digitalWrite(irPIN, LOW);
  delay(3);
}

void zero() {
  digitalWrite(irPIN, HIGH);
  delay(3);
  digitalWrite(irPIN, LOW);
  delay(1);
}

void loop() 
{
  digitalWrite(irPIN, HIGH);
  delay(10);
  digitalWrite(irPIN, LOW);
  delay(10);
  one();
  zero();
  one();
  one();
  one();
  zero();
  zero();
  delay(2000);
}
