
int irPIN = 3;

void setup()
{
 Serial.begin(9600);
 pinMode(irPIN, OUTPUT);
 digitalWrite(irPIN, LOW);
}

void one() {
  digitalWrite(irPIN, HIGH);
  delay(100);
  digitalWrite(irPIN, LOW);
  delay(100);
}

void zero() {
  digitalWrite(irPIN, HIGH);
  delay(100);
  digitalWrite(irPIN, LOW);
  delay(50);
}

void loop() 
{
  digitalWrite(irPIN, HIGH);
  delay(800);
  digitalWrite(irPIN, LOW);
  delay(300);
  one();
  zero();
  one();
  one();
  one();
  zero();
  zero();
  delay(2000);
}
