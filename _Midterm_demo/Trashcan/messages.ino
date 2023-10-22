  // Display menu status servos
  void statusServosDisplay(){
    thisDraw("DoorPos  : " + (String) door_position, 10, 10, 2) ;
    thisDraw("BasePos  : " + (String) base_position, 10, 30, 2) ;
    thisDraw("DoorRead : " + (String) myservo_door.read(), 10, 50, 2);
    thisDraw("BaseRead : " + (String) myservo_base.read(), 10, 70, 2);

    // Doo status
    thisDraw("Door estatus : " + (String) myservo_base.read(), 10, 90, 2);
    thisDraw("Cesto Number : " + (String) myservo_base.read(), 10, 110, 2);

    // thisDraw("DoorSec  : " + (String)myservo_door.readMicroseconds(), 10, 70);
    // thisDraw("BaseSec  : " + (String)myservo_base.readMicroseconds(), 10, 110);
  }

  // Status on console:
void statusServosConsole(){
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
}