
const short trigPin = 4;
const short echoPin = 7;
const short buzzPin = 3;

const short far = 18;
const short medium = 10;
const short closer = 4;

const short farInterval = 200;
const short mediumInterval = 80;
const short closeInterval = 0;

unsigned long previousTime = 0; 
int buzzState = LOW;

long duration;
int dist;


void buzzer (int distance, unsigned long *currentTime) {
  if(distance > far){
    buzzState = LOW;
  }else if(distance <= far && distance >= medium) {
    if(previousTime < *currentTime - farInterval){
      previousTime = *currentTime;
      *currentTime = millis();
      if (buzzState == LOW){
        buzzState = HIGH;
      } else {
        buzzState = LOW;
      }
    }
  } else if(distance >= closer && distance < medium) {
    if(previousTime < *currentTime - mediumInterval){
      previousTime = *currentTime;
      *currentTime = millis();
      if (buzzState == LOW){
        buzzState = HIGH;
      } else {
        buzzState = LOW;
      }
    }
  } else {
      buzzState = HIGH;
  }
  digitalWrite(buzzPin, buzzState);
  //analogWrite(buzzPin,buzzState * 215); // use PWM to alter the frequency of the buzzer, not exactly appropriate
}

int distance (){
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034/2; //equação em relação a velocidade do Som v = 0,034 cm/micro_s

}

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzPin, OUTPUT);

  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long currentTime = millis();
  dist = distance();

  buzzer(dist,&currentTime);
  Serial.println(dist);
  delay(30);
}
