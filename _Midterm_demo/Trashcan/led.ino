// just a led
void led (){
  digitalWrite(D0, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(100);                      // wait for a second
  digitalWrite(D0, LOW);   // turn the LED off by making the voltage LOW
  delay(100);   
}