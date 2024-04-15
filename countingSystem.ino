#define trig 2
#define echo 3
#define led 6

int count = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  digitalWrite(trig, LOW);
  delay(1000); 
  digitalWrite(trig, HIGH);
  delay(1000);
  digitalWrite(trig, LOW);
  
  float dist = pulseIn(echo, HIGH);
  //Serial.println(dist); -- To print Garbage value
  float distance = dist*0.3433/20;
      //formula to convert garbage to cm
    Serial.println(distance);
  if(distance<80)
  {
    count = count+1;
    digitalWrite(led, HIGH);
    Serial.print("Count=");
    Serial.println(count);
    delay(1000);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}

