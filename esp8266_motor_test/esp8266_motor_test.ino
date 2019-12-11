
int PWMA=5;//Right side 
int PWMB=4;//Left side 
int DA=0;//Right reverse 
int DB=2;//Left reverse 

void setup(){ 
 // Debug console 
 Serial.begin(9600); 
 pinMode(PWMA, OUTPUT); 
 pinMode(PWMB, OUTPUT); 
 pinMode(DA, OUTPUT); 
 pinMode(DB, OUTPUT); 
}

void loop(){ 
  tr();  
}

void fr(){
  digitalWrite(PWMA, HIGH); 
  digitalWrite(DA, LOW); 
     
  digitalWrite(PWMB, LOW); 
  digitalWrite(DB, LOW);
}

void br(){
  digitalWrite(PWMA, HIGH); 
  digitalWrite(DA, HIGH); 
     
  digitalWrite(PWMB, LOW); 
  digitalWrite(DB, LOW); 
}

void fl(){
  digitalWrite(PWMA, LOW); 
  digitalWrite(DA, LOW); 
    
  digitalWrite(PWMB, HIGH); 
  digitalWrite(DB, LOW);
}

void b(){
  digitalWrite(PWMA, HIGH); 
  digitalWrite(DA, HIGH); 
     
  digitalWrite(PWMB, HIGH); 
  digitalWrite(DB, HIGH);
}

void f(){
  digitalWrite(PWMA, HIGH); 
  digitalWrite(DA, LOW); 
    
  digitalWrite(PWMB, HIGH); 
  digitalWrite(DB, LOW); 
}

void s(){
  digitalWrite(PWMA, LOW); 
  digitalWrite(DA, LOW); 
     
  digitalWrite(PWMB, LOW); 
  digitalWrite(DB, LOW); 
}


void bl(){
  digitalWrite(PWMA, LOW); 
  digitalWrite(DA, LOW); 
     
  digitalWrite(PWMB, HIGH); 
  digitalWrite(DB, HIGH); 
}

void tl(){
  digitalWrite(PWMA, 450); 
  digitalWrite(DA, HIGH); 
  
  digitalWrite(PWMB, 450); 
  digitalWrite(DB, LOW);
}

void tr(){
  digitalWrite(PWMA, 450); 
  digitalWrite(DA, LOW); 
     
  digitalWrite(PWMB, 450); 
  digitalWrite(DB, HIGH);
}

/*/ Handling Joystick data 
BLYNK_WRITE(V1){ 
int x = param[0].asInt(); 
int y = param[1].asInt();  
if(x==-1 && y==-1){             //Backward and Left     
     digitalWrite(PWMA, LOW); 
     digitalWrite(DA, LOW); 
     
     digitalWrite(PWMB, HIGH); 
     digitalWrite(DB, HIGH); 
}else if(x==-1 && y==0){        //Left Turn 
     digitalWrite(PWMA, 450); 
     digitalWrite(DA, HIGH); 
    
     digitalWrite(PWMB, 450); 
     digitalWrite(DB, LOW); 
}else if(x==-1 && y==1){        //Forward and Left     
     digitalWrite(PWMA, LOW); 
     digitalWrite(DA, LOW); 
    
     digitalWrite(PWMB, HIGH); 
     digitalWrite(DB, LOW); 
}else if(x==0 && y==-1){        //Backward     
     digitalWrite(PWMA, HIGH); 
     digitalWrite(DA, HIGH); 
     
     digitalWrite(PWMB, HIGH); 
     digitalWrite(DB, HIGH);
}else if(x==0 && y==0){        //Stay 
     digitalWrite(PWMA, LOW); 
     digitalWrite(DA, LOW); 
     
     digitalWrite(PWMB, LOW); 
     digitalWrite(DB, LOW); 
}else if(x==0 && y==1){        //Forward 
     digitalWrite(PWMA, HIGH); 
     digitalWrite(DA, LOW); 
    
     digitalWrite(PWMB, HIGH); 
     digitalWrite(DB, LOW); 
}else if(x==1 && y==-1){        //Backward and Right     
     digitalWrite(PWMA, HIGH); 
     digitalWrite(DA, HIGH); 
     
     digitalWrite(PWMB, LOW); 
     digitalWrite(DB, LOW); 
}else if(x==1 && y==0){        //Right turn 
     digitalWrite(PWMA, 450); 
     digitalWrite(DA, LOW); 
     
     digitalWrite(PWMB, 450); 
     digitalWrite(DB, HIGH); 
}else if(x==1 && y==1){        //Forward and Right 
     digitalWrite(PWMA, HIGH); 
     digitalWrite(DA, LOW); 
     
     digitalWrite(PWMB, LOW); 
     digitalWrite(DB, LOW);
 } 
} */
