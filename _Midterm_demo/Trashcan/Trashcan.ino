#include <Servo.h>
#include"TFT_eSPI.h"

TFT_eSPI tft;
TFT_eSprite spr = TFT_eSprite(&tft);  // Sprite 
/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/
// void led();
// int getDoorPosition();
// int getBasePosition();
// void setDoorClose();
// void setDoorOpen();
// int getDoorPosition();

/*----------------------------------------------------------------------------
 *        end Headers
 *----------------------------------------------------------------------------*/

// door
Servo myservo_door;
Servo myservo_base;

int door_position = 0; // 0 - 180
int base_position = 0; // 0 - 180

bool finishLoadingScreen = false;
bool idleStatus = false;
void setup() {
  // Print messages in the console
  Serial.begin(9600); // open the serial port at 9600 bps:

  myservo_door.attach(D6); // Connet servo 
  myservo_base.attach(D2); //Connect servo 

  // door
  pinMode(WIO_KEY_C, INPUT); // close door
  pinMode(WIO_KEY_B, INPUT); // open door
  pinMode(WIO_KEY_A, INPUT); // drop trash
   
  // base
  pinMode(WIO_5S_LEFT, INPUT);
  pinMode(WIO_5S_UP, INPUT);
  pinMode(WIO_5S_RIGHT, INPUT);
  
  // initializer
  door_position = getDoorPosition();
  base_position = getBasePosition();
  setDoorClose();
  setBaseCesto1();
  
  // Sprite for the display
  tft.begin();
  tft.setRotation(3);
  spr.createSprite(TFT_HEIGHT,TFT_WIDTH);
  tft.fillScreen(TFT_BLUE);

  // welcome Login
  welcomeLogin();
}

void loop() {

  if (finishLoadingScreen) {
    idleDisplay();
  }
  led();
  
  doorConditions();
  
  baseConditions();
  
}






