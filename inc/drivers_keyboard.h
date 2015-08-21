int keypad()
  {
    int sensorValue = analogRead(A5);
    float voltage = sensorValue * (5.0 / 1023.0);
    int b = 0;
if (voltage>1.66 && voltage<1.70)
  {
    b=1; // Left
  }
  else if (voltage>2.20 && voltage<2.26)
    {
     b=2; // Up
    }
    else if (voltage>2.47 && voltage<2.53)
      {
        b=3; // Down
      }
      else if (voltage>2.63 && voltage<2.69)
        {
          b=4; // Right
        }
Serial.println(voltage);
return b;
}
