int captor()
  {
    int sensorValue = analogRead(A4);
    float voltage = sensorValue * (5.0 / 1023.0);
    int d = 0;
if (voltage>1.66 && voltage<1.70)
  {
    d=1; // Up
  }
  else if (voltage>2.20 && voltage<2.26)
    {
     d=2; // down
    }
Serial.println(voltage);
return b;
}
