#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
float Ax;
float Ay;
float Az;

float Gx;
float Gy;
float Gz;
/*
float xMax = 1.02;
float xMin = -0.97;
float xScale = 2/(xMax - xMin);
float xOffset = (xMax + xMin)/2;


float yMax = 0.99;
float yMin = -1.02;
float yScale = 2/(yMax - yMin);
float yOffset = (yMax + yMin)/2;

float zMax = 0.96;
float zMin = -1.08;
float zScale = 2/(zMax - zMin);
float zOffset = (zMax + zMin)/2;
float roll = 0;
float pitch = 0;
float pitchRAW;
float rollRAW;
*/
float gyroScale;
unsigned long timeNow, prevTime;
unsigned long dt;

float gx;
float gy;
float gz;
float deltaAngleX;
float deltaAngleY;
float deltaAngleZ;
float angleX;
float angleY;
float angleZ;
float xDegrees;

Adafruit_MPU6050 mpu;
void setup() {
  Serial.begin(115200);
  mpu.begin();
  Serial.println("MPU6050 started...");
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  gyroScale = 131.0; // For 250 deg/s, adjust if different range
}

void loop() {
  timeNow = micros();
  dt = timeNow - prevTime;
  prevTime = timeNow;

  sensors_event_t a, g , temp;
  mpu.getEvent(&a, &g, &temp);
  
  Gx = g.gyro.x;
  Gy = g.gyro.y;
  Gz = g.gyro.z;

  // Convert to degrees/second
  gx = Gx / gyroScale;
  gy = Gy / gyroScale;
  gz = Gz / gyroScale;

  // Calculate angle change (degrees)
  deltaAngleX = gx * dt / 100.0;
  deltaAngleY = gy * dt / 100.0;
  deltaAngleZ = gz * dt / 100.0;

  // Accumulate angles
  angleX += deltaAngleX;
  angleY += deltaAngleY;
  angleZ += deltaAngleZ;


  Serial.print("X: "); Serial.print(angleX);
  Serial.print(" Y: "); Serial.print(angleY);
  Serial.print(" Z: "); Serial.print(angleZ);
  Serial.println(" degrees");
  
  delay(10);
}
