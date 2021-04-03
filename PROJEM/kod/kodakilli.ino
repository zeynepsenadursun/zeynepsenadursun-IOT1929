
 #define trigPin 13
 #define echoPin 12
 #define trigPin2 11
 #define echoPin2 10
 #define led 9
 int LDRPin = A0;/* uncomment one of the following lines that describes your display

 * and comment out the line that does not describe your display */

int i = 0;
int currentState = 0;
int previousState = 0;
int currentState2 = 0;
int previousState2 = 0;
 



void setup() {

 pinMode(button, INPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(trigPin2, OUTPUT);
 pinMode(echoPin2, INPUT);
 pinMode(led, OUTPUT);
 Serial.begin (9600);
}

void loop() {
 
 long duration, distance;
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1;
 long duration2, distance2;
 digitalWrite(trigPin2, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin2, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin2, LOW);
 duration2 = pulseIn(echoPin2, HIGH);
 distance2 = (duration2/2) / 29.1;

 Serial.println(i);
 int isik_degeri = analogRead(LDRPin);
 if(i<1&& isik_degeri>30 ){
      digitalWrite(led,LOW);
      }
  if(i<1&& isik_degeri<30 ){
      digitalWrite(led,LOW);
      }   
    if(i>=1&& isik_degeri>30 ){
      digitalWrite(led,LOW);
      }   
       if(i>=1&& isik_degeri<30 ){
      digitalWrite(led,HIGH);
      }   
      
      
 if (distance <= 10){
 currentState = 1;
 }
 else {
 currentState = 0;
 }
 //delay(100);
 if(currentState != previousState){
 while(currentState == 1) 
 {
 long duration2, distance2;
 digitalWrite(trigPin2, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin2, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin2, LOW);
 duration2 = pulseIn(echoPin2, HIGH);
 distance2 = (duration2/2) / 29.1;
 if (distance2 <= 10){
 currentState2 = 1;
 }
 else {
 currentState2 = 0;
 
 }
 //delay(100);
 if(currentState2 != previousState2){
 if(currentState2 == 1) 
 {
 i = i+1;
  delay(1000);
 }
 else {
 
 }
 return;
 
   }
  }
 }
if (distance2 <= 10){
 currentState2 = 1;
 }
 else {
 currentState2 = 0;
 }
 delay(100);
 if(currentState2 != previousState2){
 while (currentState2 == 1) {
 long duration, distance;
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1;
 if (distance <= 10){
 currentState = 1;

 }
 else {
 currentState = 0;
 }
 delay(100);
 if(currentState != previousState){
 if(currentState == 1) {
 i = i-1; 
 
 delay(1000); 
 }
 else {
  }
 return;
   }
  }
 }
}
