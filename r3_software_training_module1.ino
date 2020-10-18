//Vincent Phung R3 Software Training Module

const int potentPin = A0; //Potentiometer pin number

//Dip Switch Pins
const int FF = 8;   //Pin 8, Forward Forward
const int BB = 9;  //Pin 9, Backward Backward
const int LBRF = 12;  //Pin 12, Left Backward Right Forward
const int RBLF = 3;  //Pin 3, Right Backward Left Forward

//Motor A connections
int enA = 6; //pwm enabled 
int in1 = 4;
int in2 = 7;

//Motor B connectioins
int enB = 5; //pwm enabled
int in3 = 11;
int in4 = 10; 

void setup()
{
  	// Set all the motor control pins to outputs
	pinMode(enA, OUTPUT); //pwm
	pinMode(enB, OUTPUT); //pwm
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
  
  	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
  
  	//Set Dip Switch to INPUT_PULLUP
    //This effectively inverts the behavior, 
    //where HIGH means the sensor is off, 
    //and LOW means the sensor is on
  
  pinMode(FF, INPUT_PULLUP);
  pinMode(BB, INPUT_PULLUP);
  pinMode(LBRF, INPUT_PULLUP);
  pinMode(RBLF, INPUT_PULLUP);
  
  //All switches off - Initial state
    digitalWrite(FF, HIGH);
	digitalWrite(BB, HIGH);
	digitalWrite(LBRF, HIGH);
	digitalWrite(RBLF, HIGH);
  
  //****Testing****
  //Serial.begin(9600);
  //Serial.println("Serial port open");
}

void loop()
{
  int potentValue = analogRead(potentPin); //Potent contains current analog voltage value
  int pwmOutput = map(potentValue,0,1023, 0,255); //Scales it, since pwm is used between 0 to 255
  speedControl(pwmOutput);
  directionControl();
  //5 milliseconds delay for everything to settle
  //before next reading
  delay(5);
  
  //****Testing****
  //Serial.println(digitalRead(FF));
  //Serial.println(digitalRead(BB));
  //Serial.println(digitalRead(LBRF));
  //Serial.println(digitalRead(RBLF));
}

void directionControl(){
  //Dip Switch Modes
 
  //Move Forward (Both Motors Moving Forward)
  if (digitalRead(FF) == LOW && digitalRead(BB) == HIGH 
      && digitalRead(LBRF) == HIGH && digitalRead(RBLF) == HIGH)
  {
    //Motor A, Forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    //Motor B, Forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  
  }//Move Backwards (Both Motors Moving Backward) 
  else if (digitalRead(FF) == HIGH && digitalRead(BB) == LOW 
      && digitalRead(LBRF) == HIGH && digitalRead(RBLF) == HIGH){
     //Motor A, Backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    //Motor B, Backward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    
  }//Move Left (Move Left Motor Backwards and Right Motor Forwards)
  else if (digitalRead(FF) == HIGH && digitalRead(BB) == HIGH 
      && digitalRead(LBRF) == LOW && digitalRead(RBLF) == HIGH){
     //Motor A, Backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    //Motor B, Forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    
  }//Move Right (Move Right Motor Backwards and Left Motor Forwards) 
  else if (digitalRead(FF) == HIGH && digitalRead(BB) == HIGH 
      && digitalRead(LBRF) == HIGH && digitalRead(RBLF) == LOW){
     //Motor A, FORWARD
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    //Motor B, BACKWARD
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    
  } else {
    //If more than one switch is flipped on at a time or all switches off, motors turn/remain off
    digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
  } 
  
}

void speedControl(int pwmOutput){
  analogWrite(enA, pwmOutput);
  analogWrite(enB,pwmOutput);
}



