// Conditions
void doorConditions (){
  // Door conditions; 
  if (digitalRead(WIO_KEY_C) == LOW){
    idleStatus = false;
    setDoorOpen();
  }
  else if (digitalRead(WIO_KEY_B) == LOW){
    idleStatus = false;
    setDoorClose();

  }
  else if (digitalRead(WIO_KEY_A) == LOW){
    idleStatus = false;
    setDoorOpen();
    delay(500);
    setDoorClose();
  }
}


// Door Funtions
int getDoorPosition(){
  int valor = myservo_door.read();  
  Serial.print("door loaded with value: ");
  Serial.println(valor);
  delay(5);
  return(valor);
}

void setDoorClose (){
  int pos1 = door_position;

  for (pos1; pos1 > 0; pos1 -= 1) {
    Serial.print("closing door: ");
    Serial.println(pos1);
    myservo_door.write(pos1);
    delay(5);
  }
  door_position = 0;
  tft.fillScreen(TFT_BLUE);
}

void setDoorOpen(){
  int pos1 = door_position;
  
  for (pos1; pos1 < 180; pos1 += 1) {
    Serial.print("opening door: ");
    Serial.println(pos1);
    myservo_door.write(pos1);
    delay(5);
  }
    tft.fillScreen(TFT_DARKGREEN);
    door_position = 180;
}