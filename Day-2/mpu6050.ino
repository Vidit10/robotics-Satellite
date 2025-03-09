#include <Wire.h>

const int MPU = 0x68;      // I2C address of the MPU6050
float AccX, AccY, AccZ;    // Accelerometer values
float GyroX, GyroY, GyroZ; // Gyroscope values

void setup()
{
    Serial.begin(115200); // Initialize Serial Monitor
    Wire.begin();         // Initialize I2C communication
    Wire.beginTransmission(MPU);
    Wire.write(0x6B); // Power management register
    Wire.write(0x00); // Wake up the MPU6050
    Wire.endTransmission(true);
}

void loop()
{
    // Read accelerometer data
    Wire.beginTransmission(MPU);
    Wire.write(0x3B); // Starting register for accelerometer data
    Wire.endTransmission(false);
    Wire.requestFrom(MPU, 6, true); // Request 6 bytes of accelerometer data

    AccX = (Wire.read() << 8 | Wire.read()) / 16384.0; // X-axis value
    AccY = (Wire.read() << 8 | Wire.read()) / 16384.0; // Y-axis value
    AccZ = (Wire.read() << 8 | Wire.read()) / 16384.0; // Z-axis value

    // Read gyroscope data
    Wire.beginTransmission(MPU);
    Wire.write(0x43); // Starting register for gyroscope data
    Wire.endTransmission(false);
    Wire.requestFrom(MPU, 6, true); // Request 6 bytes of gyroscope data

    GyroX = (Wire.read() << 8 | Wire.read()) / 131.0; // X-axis value
    GyroY = (Wire.read() << 8 | Wire.read()) / 131.0; // Y-axis value
    GyroZ = (Wire.read() << 8 | Wire.read()) / 131.0; // Z-axis value

    // Print data to Serial Monitor
    Serial.print("AccX: ");
    Serial.print(AccX);
    Serial.print(" | AccY: ");
    Serial.print(AccY);
    Serial.print(" | AccZ: ");
    Serial.println(AccZ);

    Serial.print("GyroX: ");
    Serial.print(GyroX);
    Serial.print(" | GyroY: ");
    Serial.print(GyroY);
    Serial.print(" | GyroZ: ");
    Serial.println(GyroZ);

    delay(500); // Delay for readability
}
