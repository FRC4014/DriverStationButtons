/*
Driver Station Buttons
By Lucas LeVieux on behalf of FRC team 4014

A simple arduino program to relay button presses via the serial
port to the robot program.
*/

byte inputButtons[] = {2, 3, 4, 5}; //the port for each of the 
//buttons in use.  Will be refferred to by their position in this
//array.
boolean buttonState[] = {false, false, false, false}; 
//corresponds to the inputButtons.  The state of the button where
//false -> not depressed and true -> depressed

void setup() {
  Serial.begin(115200);
  
  for (int i=0; i<sizeof(inputButtons); i++) //set all input buttons to input
    pinMode(inputButtons[i], INPUT);

  Serial.println("ready");
}

void loop() {
  for (int i=0; i<sizeof(inputButtons); i++) {
    if (digitalRead(inputButtons[i]) == HIGH && buttonState[i] == false)
    {
      Serial.print(i);
      Serial.println(1);
      buttonState[i] = true; //change to on
    }
    else if (digitalRead(inputButtons[i]) == LOW && buttonState[i] == true)
    {
      Serial.print(i);
      Serial.println(0);
      buttonState[i] = false; //change to off
    }
  }
}
