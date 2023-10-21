#include <Servo.h>
#include"TFT_eSPI.h"

TFT_eSPI tft;
TFT_eSprite spr = TFT_eSprite(&tft);  // Sprite 
/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/
void led();
int getDoorPosition();
int getBasePosition();

// door
Servo myservo_door;
Servo myservo_base;

int door_position = 0; // 0 - 180
int base_position = 0; // 0 - 180

//int pos1 = 0;
//int pos2 = 0;

void setup() {
  // Print messages in the console
  Serial.begin(9600); // open the serial port at 9600 bps:

  myservo_door.attach(D6); // Connet servo 
  myservo_base.attach(D2); //Connect servo 

  // door
  pinMode(WIO_KEY_C, INPUT);
  pinMode(WIO_KEY_B, INPUT);
  pinMode(WIO_KEY_A, INPUT);
   
  // base
  pinMode(WIO_5S_LEFT, INPUT);
  pinMode(WIO_5S_RIGHT, INPUT);
  
  // initializer
  door_position = getDoorPosition();
  base_position = getBasePosition();
  setDoorClose();
  setBaseCesto3();
  
  // Sprite for the display
  tft.begin();
  tft.setRotation(3);
  spr.createSprite(TFT_HEIGHT,TFT_WIDTH);
  tft.fillScreen(TFT_RED);
}

void loop() {
  led();

  // Display menu status servos
  thisDraw("DoorPos  : " + (String) door_position, 10, 10) ;
  thisDraw("BasePos  : " + (String) base_position, 10, 30) ;
  thisDraw("DoorRead : " + (String) myservo_door.read(), 10, 50);
  thisDraw("BaseRead : " + (String) myservo_base.read(), 10, 70);

  // Doo status
  thisDraw("Door estatus : " + (String) myservo_base.read(), 10, 90);
  thisDraw("Cesto Number : " + (String) myservo_base.read(), 10, 110);

  // thisDraw("DoorSec  : " + (String)myservo_door.readMicroseconds(), 10, 70);
  // thisDraw("BaseSec  : " + (String)myservo_base.readMicroseconds(), 10, 110);

  // Print current values in console
  Serial.print("\n\n\n\n\n\n------------------\n");
  Serial.print("Door position: ");
  Serial.println(door_position);
  Serial.print("Base rotation: ");
  Serial.println(base_position);
  Serial.print("------------------\n");
  Serial.print("-reading door read: ");
  Serial.println(myservo_door.read());
  Serial.print("-reading servo motor read: ");
  Serial.println(myservo_base.read());
  // Serial.print("-reading door readMicroseconds: ");
  // Serial.println(myservo_door.readMicroseconds());
  Serial.print("------------------\n");
  // Serial.print("-reading servo motor read microseconds: ");
  // Serial.println(myservo_base.readMicroseconds());

  // Door conditions; 
  if (digitalRead(WIO_KEY_C) == LOW){
    setDoorOpen();
    tft.fillScreen(TFT_RED);
  }
  else if (digitalRead(WIO_KEY_B) == LOW){
    setDoorClose();
    tft.fillScreen(TFT_RED);
  }
  else if (digitalRead(WIO_KEY_A) == LOW){
    setDoorOpen();
    setDoorClose();
    tft.fillScreen(TFT_RED);
  }
  // Base rotation conditions
  else if (digitalRead(WIO_5S_LEFT) == LOW){
    setBaseCesto1();
    tft.fillScreen(TFT_RED);
  }  
  else if (digitalRead(WIO_5S_RIGHT) == LOW){
    setBaseCesto3();
      tft.fillScreen(TFT_RED);
  }
  
}

// just a led
void led (){
  digitalWrite(D0, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(100);                      // wait for a second
  digitalWrite(D0, LOW);   // turn the LED off by making the voltage LOW
  delay(100);   
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
}

void setDoorOpen(){
  int pos1 = door_position;
  
  for (pos1; pos1 < 180; pos1 += 1) {
    Serial.print("opening door: ");
    Serial.println(pos1);
    myservo_door.write(pos1);
    delay(5);
  }
    door_position = 180;
}



// Base Funtions
int getBasePosition(){
  int valor = myservo_base.read();
  Serial.print("base loaded with value: ");
  Serial.println(valor);
  delay(10);
  return(valor);
}

void setBaseCesto3 (){
  int pos2 = base_position;

  for (pos2; pos2 > 0; pos2 -= 1) {
    Serial.print("going to cesto 1: ");
    Serial.println(pos2);
    myservo_base.write(pos2);
    delay(10);
  }
  base_position = 0;
}

void setBaseCesto1(){
  int pos2 = base_position;
  
  for (pos2; pos2 < 180; pos2 += 1) {
    Serial.print("going to cesto 3: ");
    Serial.println(pos2);
    myservo_base.write(pos2);
    delay(10);
  }
    base_position = 180;
}

void thisDraw(String trash, int x, int y){
  tft.setTextColor(TFT_WHITE);          //sets the text colour to black
  tft.setTextSize(3);                   //sets the size of text
  tft.drawString(trash, x, y);
}