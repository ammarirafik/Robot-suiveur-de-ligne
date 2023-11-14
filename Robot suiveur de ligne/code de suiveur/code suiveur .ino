int motA_pin1=2;
int motA_pin2=7;
int motB_pin1=8;
int motB_pin2=12;
int motA_EN=5;
int motB_EN=11;
int R_S=10;
int L_S=13;
int C_S=4;
int x;
int speed = 100;
void setup() {
  
  pinMode (R_S,INPUT);
  pinMode (L_S,INPUT);
  pinMode (C_S,INPUT);
  pinMode (motA_pin1,OUTPUT);      
  pinMode (motA_pin2,OUTPUT);
  pinMode (motA_EN,OUTPUT);
  pinMode (motB_pin1,OUTPUT);
  pinMode (motB_pin2,OUTPUT);
  pinMode (motB_EN,OUTPUT);
  digitalWrite(motA_EN ,HIGH);
  digitalWrite(motB_EN ,HIGH);
  Serial.begin(9600);
}
void RIGHT() {
digitalWrite(motA_pin1,HIGH);
digitalWrite(motA_pin2,LOW); 
analogWrite(motA_EN,speed);
digitalWrite(motB_pin1,HIGH);
digitalWrite(motB_pin2,LOW);
analogWrite(motB_EN,speed);

}

void LEFT() {
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,HIGH);
analogWrite(motA_EN,speed);
digitalWrite(motB_pin1,LOW); 
digitalWrite(motB_pin2,HIGH);
analogWrite(motB_EN,speed);
}
void FWD() {
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,HIGH);
analogWrite(motA_EN,speed);
digitalWrite(motB_pin1,HIGH); 
digitalWrite(motB_pin2,LOW);
analogWrite(motB_EN,speed);
}
void STOP() {
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,LOW);
digitalWrite(motA_EN,0);
digitalWrite(motB_pin1,LOW); 
digitalWrite(motB_pin2,LOW);
digitalWrite(motB_EN,0);
}

void loop() {
  x = digitalRead(L_S);
  Serial.println(x); ou Serial.println(digitalRead(L_S));
  if ((digitalRead(L_S)==1)&&(digitalRead(C_S)==1)&&(digitalRead(R_S)==1))
    LEFT();
  else if  ((digitalRead(L_S)==0)&&(digitalRead(C_S)==0)&&(digitalRead(R_S)==1))
    RIGHT();
  else if  ((digitalRead(L_S)==0)&&(digitalRead(C_S)==1)&&(digitalRead(R_S)==0))
    FWD();
  else if  ((digitalRead(L_S)==0)&&(digitalRead(C_S)==1)&&(digitalRead(R_S)==1))   
    RIGHT();
  else if  ((digitalRead(L_S)==1)&&(digitalRead(C_S)==0)&&(digitalRead(R_S)==0))     
    LEFT();
  else if  ((digitalRead(L_S)==1)&&(digitalRead(C_S)==1)&&(digitalRead(R_S)==0))
    LEFT();   
  else if   ((digitalRead(L_S)==0)&&(digitalRead(C_S)==0)&&(digitalRead(R_S)==0))  
    FWD();
  //else if  ((digitalRead(L_S)==1)&&(digitalRead(C_S)==1)&&(digitalRead(R_S)==1)) 
   // STOP();*/
   
}
