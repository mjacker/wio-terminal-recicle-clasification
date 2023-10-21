#include <Servo.h>
/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/
void led();
int getDoorPosition();
int getBaseRotation();

int servo_base_pin = D8;

// door
Servo myservo_door;
int door_pos_position = 0; // 0 - 18
int pos1 = 0;

// base
Servo myservo_base;
/* MG995, 90 = stop,
          0 = CW full speed,
          180 = anti CW full speed 
*/
int base_rotation = 1500; // 0 - 360
int angle = 0;

void setup() {
  // Print messages in the console
  Serial.begin(9600); // open the serial port at 9600 bps:

  myservo_door.attach(D6); // Connet servo 
  myservo_base.attach(servo_base_pin); //Connect servo to Grove Digital Port
  //myservo_base.writeMicroseconds(base_rotation);

  // led
  pinMode(D0, OUTPUT);
  
  // door
  pinMode(WIO_KEY_C, INPUT);
  pinMode(WIO_KEY_B, INPUT);
  
  // base
  pinMode(WIO_5S_LEFT, INPUT);
  pinMode(WIO_5S_RIGHT, INPUT);
  
  // initializer
  door_pos_position = getDoorPosition();

}

void loop() {
  led();

  // Print current values:
  Serial.print("\n\n\n\n\n\n------------------\n");
  Serial.print("Door position: ");
  Serial.println(door_pos_position);
  Serial.print("Base rotation: ");
  Serial.println(base_rotation);
  Serial.print("------------------\n");
  Serial.print("-reading door read: ");
  Serial.println(myservo_door.read());
  Serial.print("-reading door readMicroseconds: ");
  Serial.println(myservo_door.readMicroseconds());
  Serial.print("------------------\n");
  Serial.print("-reading servo motor read: ");
  Serial.println(myservo_base.read());
  Serial.print("-reading servo motor read microseconds: ");
  Serial.println(myservo_base.readMicroseconds());

  // Door conditions; 
  if (digitalRead(WIO_KEY_C) == LOW){
    setDoorOpen();
  }
  
  if (digitalRead(WIO_KEY_B) == LOW){
    setDoorClose();
  }

  // Base rotation conditions
  if (digitalRead(WIO_5S_LEFT) == LOW){
    setBaseRight();
  }
  
  if (digitalRead(WIO_5S_RIGHT) == LOW){

    setBaseLeft();
  }
}

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
  int pos1 = door_pos_position;

  for (pos1; pos1 > 0; pos1 -= 1) {
    Serial.print("closing: ");
    Serial.println(pos1);
    myservo_door.write(pos1);
    delay(5);
  }
  door_pos_position = 0;
}

void setDoorOpen(){
  int pos1 = door_pos_position;
  
  for (pos1; pos1 < 180; pos1 += 1) {
    Serial.print("opening: ");
    Serial.println(pos1);
    myservo_door.write(pos1);
    delay(5);
  }
    door_pos_position = 180;
}

// Rotation base Funtions
int getBaseRotation(){
  int valor = myservo_base.read();
  Serial.print(" base loaded with value: ");
  Serial.println(valor);
  delay(1000);
  return(valor);
}

void setBaseLeft (){
  base_rotation -= 10;
  //myservo_base.attach(servo_base_pin);
  myservo_base.write(base_rotation);
  //myservo_base.writeMicroseconds(base_rotation);

  //delay(3000);
  /*angle = base_rotation;

  for (angle; angle > 0; angle -= 1) {
    Serial.print("rotating to lower: ");
    Serial.println(angle);
    myservo_base.write(angle);
    delay(100);
  }
  base_rotation = 0 ;*/
}

void setBaseRight (){
  /*
  myservo_base.attach(servo_base_pin);
  myservo_base.writeMicroseconds(1500);
  Serial.println("SET 0");
  myservo_base.write(0); // stop rotating
  delay(3000);
  Serial.println("SET 90");
  myservo_base.write(90); // stop rotating
  delay(3000);
  Serial.println("SET 180");
  myservo_base.write(180); // full speed counter-clockwise
  delay(3000);
  Serial.println("SET 360");
  myservo_base.write(360); // full speed counter-clockwise
  delay(3000);
  myservo_base.detach();
*/


  // wrong concep
  /*
  angle = base_rotation;
  
  for (angle = 0; angle < 180; angle += 1) {
    Serial.print("rotating to bigger: ");
    Serial.println(angle);
    myservo_base.write(angle);
    delay(100);
  }
  myservo_base.write(90);
  */

  // testing continour servo motor 
  base_rotation += 10;
  //myservo_base.attach(servo_base_pin);
  myservo_base.write(base_rotation);

  //myservo_base.writeMicroseconds(base_rotation);
  //delay(3000);

}
