
int irPIN = 3;

void setup()
{
 Serial.begin(9600);
 pinMode(irPIN, OUTPUT);
 digitalWrite(irPIN, LOW);
}

void one() {
  digitalWrite(irPIN, HIGH);
  delay(50);
  digitalWrite(irPIN, LOW);
  delay(50);
}

void zero() {
  digitalWrite(irPIN, HIGH);
  delay(50);
  digitalWrite(irPIN, LOW);
  delay(10);
}

void loop() 
{
  digitalWrite(irPIN, HIGH);
  delay(500);
  digitalWrite(irPIN, LOW);
  delay(200);
  one();
  zero();
  one();
  one();
  one();
  zero();
  zero();
  delay(1000);
}
