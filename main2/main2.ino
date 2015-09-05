#include "Button.h"

int code[4];
int prova;
int count = 0;
int code_correct[4] = {1,1};
int countCorrects;

//Llista 
Button btn[2] = {
  Button(1, 0, 50, 100),
  Button(2, 0, 750, 850)
};
void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 2; i++){
      if(btn[i].check() == true){
        code[count] = btn[i].getNumber();
        count++;
      }
  }
    
  countCorrects = 0;
  for(int i = 0; i < 2; i++){
    for(int i = 0; i < 2; i++){
    Serial.println(code[i]);
    }
    if(code[i] == code_correct[i]){
      countCorrects++;
    }
    else{
      break;
    }  
  }
  if(count > 1){
      count = 0;
      for(int i = 0; i < 2; i++){
        code[i] = 0;
      }
  }  
  if(countCorrects == 2){
    countCorrects = 0;
    digitalWrite(13,HIGH);
  }
}
