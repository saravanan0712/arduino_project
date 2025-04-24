#define D0 2    
#define D1 3
#define D2 4
#define D3 5

#define ENA 9   
#define IN1 6
#define IN2 7

#define ENB 10  
#define IN3 8   
#define IN4 11

#define ENC 12  
#define IN5 13  
#define IN6 14

#define END 15  
#define IN7 16 
#define IN8 17

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(ENC, OUTPUT);
  pinMode(END, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);

  pinMode(D0, INPUT);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);

  Serial.begin(9600);  
}

void loop() {
  int dtmfValue = (digitalRead(D3) << 3) | (digitalRead(D2) << 2) | (digitalRead(D1) << 1) | digitalRead(D0);

  Serial.print("DTMF Value: ");
  Serial.println(dtmfValue);  

  switch (dtmfValue) {
    case 1:  
      forward();  
      break;
    case 2:  
      backward();  
      break;
    case 3:  
      turnRight();  
      break;
    case 4: 
      turnLeft();  
      break;
    case 5:  
      backwardRightTurn();  
      break;
    case 6: 
      backwardLeftTurn();  
      break;
    case 7:  
      stopMotors();  
      break;
    case 8:  
      drift();  
      break;
    default:
      stopMotors(); 
      break;
  }

  delay(100); 
}

// Function to move forward
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 255);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  analogWrite(ENC, 255);

  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  analogWrite(END, 255);
}


void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 255);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  analogWrite(ENC, 255);

  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  analogWrite(END, 255);
}

t
void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 200);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  analogWrite(ENC, 200);

  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  analogWrite(END, 200);
}


void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 200);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 200);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  analogWrite(ENC, 200);

  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  analogWrite(END, 200);
}

void backwardRightTurn() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 255);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  analogWrite(ENC, 255);

  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  analogWrite(END, 255);

  digitalWrite(IN1, HIGH);   
  digitalWrite(IN2, LOW);   
  analogWrite(ENA, 200);

  digitalWrite(IN3, LOW);    
  digitalWrite(IN4, HIGH); 
  analogWrite(ENB, 200);

  digitalWrite(IN5, LOW);    
  digitalWrite(IN6, HIGH);   
  analogWrite(ENC, 200);

  digitalWrite(IN7, HIGH); 
  digitalWrite(IN8, LOW); 
  analogWrite(END, 200);
}


void backwardLeftTurn() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 255);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  analogWrite(ENC, 255);

  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  analogWrite(END, 255);

  digitalWrite(IN1, LOW);  
  digitalWrite(IN2, HIGH);   
  analogWrite(ENA, 200);

  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW); 
  analogWrite(ENB, 200);

  digitalWrite(IN5, LOW);    
  digitalWrite(IN6, HIGH);   
  analogWrite(ENC, 200);

  digitalWrite(IN7, LOW);  
  digitalWrite(IN8, HIGH); 
  analogWrite(END, 200);
}


void drift() {

  digitalWrite(IN1, HIGH);   
  digitalWrite(IN2, LOW);   
  analogWrite(ENA, 255);

  digitalWrite(IN3, LOW);   
  digitalWrite(IN4, HIGH); 
  analogWrite(ENB, 255);

  digitalWrite(IN5, HIGH);   
  digitalWrite(IN6, LOW);    
  analogWrite(ENC, 255);
  digitalWrite(IN7, LOW);    
  digitalWrite(IN8, HIGH); 
  analogWrite(END, 255);
}


void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  analogWrite(ENC, 0);

  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);
  analogWrite(END,0);
}
