int Knock = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(Knock, INPUT);
}

void loop()
{
  Serial.println(digitalRead(Knock));
}
