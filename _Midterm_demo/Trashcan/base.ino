// Base Conditions
void baseConditions(){
      // Base rotation conditions
  if (digitalRead(WIO_5S_LEFT) == LOW){
    setBaseCesto1();
    tft.fillScreen(TFT_BLUE);
  }  
  else if (digitalRead(WIO_5S_UP) == LOW){
    setBaseCesto2();
    tft.fillScreen(TFT_BLUE);
  }  
  else if (digitalRead(WIO_5S_RIGHT) == LOW){
    setBaseCesto3();
      tft.fillScreen(TFT_BLUE);
  }
}
// Base Funtions
int getBasePosition(){
  int valor = myservo_base.read();
  Serial.print("base loaded with value: ");
  Serial.println(valor);
  delay(10);
  return(valor);
}

void setBaseCesto1 (){
  int pos2 = base_position;

  for (pos2; pos2 > 0; pos2 -= 1) {
    Serial.print("going to cesto 1: ");
    Serial.println(pos2);
    myservo_base.write(pos2);
    delay(10);
  }
  base_position = 0;
}

void setBaseCesto2 (){
  int pos2 = base_position;
  if (pos2 > 90){
    for (pos2; pos2 > 90; pos2 -= 1) {
      Serial.print("going to cesto 2: ");
      Serial.println(pos2);
      myservo_base.write(pos2);
      delay(10);
    }
  }
  else {
    for (pos2; pos2 < 90; pos2 += 1) {
      Serial.print("going to cesto 2: ");
      Serial.println(pos2);
      myservo_base.write(pos2);
      delay(10);
    }
  }
  base_position = 90;
}

void setBaseCesto3(){
  int pos2 = base_position;
  
  for (pos2; pos2 < 180; pos2 += 1) {
    Serial.print("going to cesto 3: ");
    Serial.println(pos2);
    myservo_base.write(pos2);
    delay(10);
  }
    base_position = 180;
}

