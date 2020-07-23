int buzzer=8;
const int ledPin1=12;
const int ledPin2=11;
const int ledPin3=10;
const int inputPin=2;
const int redLED=ledPin1;
const int yellowLED=ledPin2;
const int greenLED=ledPin3;
volatile boolean isWinner = false;
long colorNum;
void setup() {
  // put your setup code here, to run once:
pinMode(ledPin1,OUTPUT);
pinMode(ledPin2,OUTPUT);
pinMode(ledPin3,OUTPUT);
pinMode(inputPin,INPUT_PULLUP);
attachInterrupt(0,buttonPressed,FALLING);
digitalWrite(ledPin1,LOW);
digitalWrite(ledPin2,LOW);
digitalWrite(ledPin3,LOW);
//attaching interrupt,first arguement 0,ISR buttonPressed function,
//occur when FALLING
Serial.begin(9600);
}

void loop() {//nothing to perform here
  // put your main code here, to run repeatedly:
  //0 is Red
  //1 is Yellow
  //2 is Green
  colorNum=random(3);
//  if(colorNum==0){
//    digitalWrite(ledPin1,HIGH);
//    delay(1000);
//    digitalWrite(ledPin1,LOW);
//  }
//  if(colorNum==1){
//    digitalWrite(ledPin2,HIGH);
//    delay(1000);
//    digitalWrite(ledPin2,LOW);
//  }
//  if(colorNum==2){
//    digitalWrite(ledPin3,HIGH);
//    delay(1000);
//    digitalWrite(ledPin3,LOW);
//  }
lightLEDloopHelper(colorNum);
if(isWinner){//will be set by interrupt
  isWinner=false;
  tone(buzzer,300);
  delay(200);
  noTone(buzzer);
  delay(200);
  tone(buzzer,300);
  delay(200);
  noTone(buzzer);
  delay(200);
  tone(buzzer,300);
  delay(200);
  noTone(buzzer);
  winner();
  Serial.println("\nYOU\nWON");
  
}
}
void lightLEDloopHelper(long colorNum){
  if(colorNum==0){
    digitalWrite(ledPin1,HIGH);
    delay(1000);
    digitalWrite(ledPin1,LOW);
  }
  else if(colorNum==1){
    digitalWrite(ledPin2,HIGH);
    delay(1000);
    digitalWrite(ledPin2,LOW);
  }
  else if(colorNum==2){
    digitalWrite(ledPin3,HIGH);
    delay(1000);
    digitalWrite(ledPin3,LOW);
  }
  else{
    
  }
}
void winner() {
  for (int i=0; i<3; i++) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    delay(250);    
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW); 
    delay(250);    
  }
  delay(3000);
}
void buttonPressed(){//ISR cannot take any arguments or return values
  Serial.println("interrupt Occurred");
  //if(digitalRead(ledPin1,HIGH){Serial.print("RED")};
  if(digitalRead(ledPin2))
  {
    Serial.println("YELLOW");
  
  }
  if(digitalRead(ledPin3))
  {
    Serial.println("GREEN");
    }
  if(digitalRead(ledPin1)){//if HIGH
    Serial.println("RED");
    //Serial.println("Winnner");
    //digitalWrite(ledPin1,HIGH);//toggle state to low
    isWinner=true;
  }
  else{
    //digitalWrite(ledPin,HIGH);//if not HIGH set to HIGH
  }
}

