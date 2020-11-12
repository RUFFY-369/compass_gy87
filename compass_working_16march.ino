#include <QMC5883L.h>
#include <Wire.h>

QMC5883L compass;

void setup()
{
  Wire.begin();
  Wire.beginTransmission(0x68);
Wire.write(0x37);
Wire.write(0x02);
Wire.endTransmission();

Wire.beginTransmission(0x68);
Wire.write(0x6A);
Wire.write(0x00);
Wire.endTransmission();

//Disable Sleep Mode
Wire.beginTransmission(0x68);
Wire.write(0x6B);
Wire.write(0x00);
Wire.endTransmission();

  compass.init();
  compass.setSamplingRate(50);

  Serial.begin(57600);
  Serial.println("QMC5883L Compass Demo");
  Serial.println("Turn compass in all directions to calibrate....");
}

void loop()
{
  int heading = compass.readHeading();
  if(heading==0) {
    /* Still calibrating, so measure but don't print */
  } else {
    Serial.println(heading);
    delay(100);
  }
}
