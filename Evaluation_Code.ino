const int button = 8;
int count = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(button,INPUT);
}

void loop()
{
  int c = analogRead(A0);
  delay(500);
  if(c<300)
  {
    if(digitalRead(button)==HIGH){
      delay(500);
      count++;
      }
      
    if(count%2==0){
      for(int i=2;i<=7;i++)
  {
     digitalWrite(i,HIGH);
  	 delay(100);
  	 digitalWrite(i,LOW);
     delay(100);
  }
      }
    if(count%2!=0){
      for(int i=0;i<6;i++)
  {
    if(i==0)
    {
     digitalWrite(2, HIGH);
     digitalWrite(4, HIGH);
     digitalWrite(6, HIGH);
  	 delay(1000);
  	 digitalWrite(2, LOW);
     digitalWrite(4, LOW);
     digitalWrite(6, LOW);
    }
    if(i==1)
    {
     digitalWrite(3, HIGH);
     digitalWrite(5, HIGH);
     digitalWrite(7, HIGH);
     delay(1000);
     digitalWrite(3, LOW);
     digitalWrite(5, LOW);
     digitalWrite(7, LOW);
    }
  }
      }     
  }
  else
  {
    digitalWrite(2,LOW);
    delay(1000);
  }
}