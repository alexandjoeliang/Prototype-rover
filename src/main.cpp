//water level



void setup()
{
  // Used to display information
  Serial.begin(9600);

  // Wait for Serial Monitor to be opened
  while (!Serial)
  {
    //do nothing
  }
}

void loop()
{

  // Tell the motor to go forward (may depend by your wiring)
  motor.forward();

  // Alternative method:
  // motor.run(L298N::FORWARD);

  //print the motor status in the serial monitor
  Serial.print("Is moving = ");
  Serial.println(motor.isMoving());

  delay(3000);

  // Stop
  motor.stop();

  // Alternative method:
  // motor.run(L298N::STOP);

  Serial.print("Is moving = ");
  Serial.println(motor.isMoving());

  delay(3000);

  // Tell the motor to go back (may depend by your wiring)
  motor.backward();

  // Alternative method:
  // motor.run(L298N::BACKWARD);

  Serial.print("Is moving = ");
  Serial.println(motor.isMoving());

  delay(3000);

  // Stop
  motor.stop();

  Serial.print("Is moving = ");
  Serial.println(motor.isMoving());

  delay(3000);
}