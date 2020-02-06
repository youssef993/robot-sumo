#define echoPin 7 // Echo Pin
#define trigPin 9 // Trigger Pin
#define MA 2
#define MB 3// 

int maximumRange = 85; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(MA, OUTPUT); 
  pinMode(MB, OUTPUT);// 
}

void loop() {

 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 if (distance >= maximumRange || distance <= minimumRange){

 Serial.println("-1");
 digitalWrite(MA, HIGH); 
 digitalWrite(MB, LOW);
 delay(100);
 digitalWrite(MA, LOW);
 delay(100);
 
 }
 else {
 
 Serial.println(distance);
 digitalWrite(MA, HIGH);
digitalWrite(MB, HIGH); 
 }
 
 //Delay 50ms before next reading.
 
}
