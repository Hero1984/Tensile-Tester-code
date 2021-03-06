const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

int count;
double duration;
double cmAvg, temp;



void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(pingPin, OUTPUT); 
   pinMode(echoPin, INPUT);
   count=0;
}

void loop() {

  count++;
  Serial.print("Cycle: ");
  Serial.println(count);
  
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin ,HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin ,LOW);
  duration = pulseIn(echoPin, HIGH);
  
  Serial.print("Distance: ");
  Serial.print(msToCm(duration));
  Serial.print(" cm");
  Serial.println();
  
  delay(200);
}

double msToCm(double microseconds){
  return   microseconds  / 29 / 2;
}

