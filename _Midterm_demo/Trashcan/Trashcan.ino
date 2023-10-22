#include <Servo.h> 
#include"TFT_eSPI.h" // Wio Display

/*----------------------------------------------------------------------------
 *        Global Variables
 *----------------------------------------------------------------------------*/
Servo myservo_door;
Servo myservo_base;

#define servo_door_pin D6
#define servo_base_pin D2

int door_position = 0; // 0 - 180
int base_position = 0; // 0 - 180

// Menu boolean flow
bool finishLoadingScreen = false;
bool idleStatus = false;

// Display object manager.
TFT_eSPI tft;
TFT_eSprite spr = TFT_eSprite(&tft);  // Sprite 

/*----------------------------------------------------------------------------
 *        Seting up environment
 *----------------------------------------------------------------------------*/
void setup() {
  // Print messages in the console
  Serial.begin(9600); // open the serial port at 9600 bps:

  // Attach servos to GPIO Digital
  myservo_door.attach(servo_door_pin); 
  myservo_base.attach(servo_base_pin); 

  // Wio Buttons
    // door
    pinMode(WIO_KEY_C, INPUT); // close door
    pinMode(WIO_KEY_B, INPUT); // open door
    pinMode(WIO_KEY_A, INPUT); // drop trash
    // base
    pinMode(WIO_5S_LEFT, INPUT); // Go to trashcan 1
    pinMode(WIO_5S_UP, INPUT);   // Go to trashcan 2
    pinMode(WIO_5S_RIGHT, INPUT);// Go to trashcan 3

  // initializer
  door_position = getDoorPosition(); // Get started door position
  base_position = getBasePosition(); // Get started base position
  setDoorClose();  // set door to close
  setBaseCesto1(); // set base to trashcan 1
  
  // Wio Display initialiter
  tft.begin();
  tft.setRotation(3);
  spr.createSprite(TFT_HEIGHT,TFT_WIDTH);
  tft.fillScreen(TFT_BLACK);

  // welcome Login
  welcomeLogin(); // first menu flow start
}

/*----------------------------------------------------------------------------
 *        Main loop 
 *----------------------------------------------------------------------------*/
void loop() {

  if (finishLoadingScreen) {
    idleDisplay();
  }
  led();
  
  doorConditions();
  
  baseConditions();
  
}