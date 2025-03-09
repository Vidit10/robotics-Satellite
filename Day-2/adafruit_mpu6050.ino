#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

void setup()
{
    Serial.begin(115200);
    while (!Serial)
        delay(10); // Wait for Serial Monitor to open (useful for boards like Zero or Leonardo)

    Serial.println("Adafruit MPU6050 test!");

    // Initialize MPU6050
    if (!mpu.begin())
    {
        Serial.println("Failed to find MPU6050 chip");
        while (1)
        {
            delay(10);
        }
    }
    Serial.println("MPU6050 Found!");

    // Set accelerometer range
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    Serial.print("Accelerometer range set to: ");
    switch (mpu.getAccelerometerRange())
    {
    case MPU6050_RANGE_2_G:
        Serial.println("+-2G");
        break;
    case MPU6050_RANGE_4_G:
        Serial.println("+-4G");
        break;
    case MPU6050_RANGE_8_G:
        Serial.println("+-8G");
        break;
    case MPU6050_RANGE_16_G:
        Serial.println("+-16G");
        break;
    }

    // Set gyroscope range
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    Serial.print("Gyroscope range set to: ");
    switch (mpu.getGyroRange())
    {
    case MPU6050_RANGE_250_DEG:
        Serial.println("+-250 deg/s");
        break;
    case MPU6050_RANGE_500_DEG:
        Serial.println("+-500 deg/s");
        break;
    case MPU6050_RANGE_1000_DEG:
        Serial.println("+-1000 deg/s");
        break;
    case MPU6050_RANGE_2000_DEG:
        Serial.println("+-2000 deg/s");
        break;
    }

    // Set filter bandwidth
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
    Serial.print("Filter bandwidth set to: ");
    switch (mpu.getFilterBandwidth())
    {
    case MPU6050_BAND_260_HZ:
        Serial.println("260 Hz");
        break;
    case MPU6050_BAND_184_HZ:
        Serial.println("184 Hz");
        break;
    case MPU6050_BAND_94_HZ:
        Serial.println("94 Hz");
        break;
    case MPU6050_BAND_44_HZ:
        Serial.println("44 Hz");
        break;
    case MPU6050_BAND_21_HZ:
        Serial.println("21 Hz");
        break;
    case MPU6050_BAND_10_HZ:
        Serial.println("10 Hz");
        break;
    case MPU6050_BAND_5_HZ:
        Serial.println("5 Hz");
        break;
    }
}

void loop()
{
    // Create sensor event objects
    sensors_event_t accel, gyro, temp;

    // Get sensor events
    mpu.getEvent(&accel, &gyro, &temp);

    // Print accelerometer data
    Serial.print("Accel X: ");
    Serial.print(accel.acceleration.x);
    Serial.print(" m/s^2, ");
    Serial.print("Y: ");
    Serial.print(accel.acceleration.y);
    Serial.print(" m/s^2, ");
    Serial.print("Z: ");
    Serial.print(accel.acceleration.z);
    Serial.println(" m/s^2");

    // Print gyroscope data
    Serial.print("Gyro X: ");
    Serial.print(gyro.gyro.x);
    Serial.print(" rad/s, ");
    Serial.print("Y: ");
    Serial.print(gyro.gyro.y);
    Serial.print(" rad/s, ");
    Serial.print("Z: ");
    Serial.print(gyro.gyro.z);
    Serial.println(" rad/s");

    // Print temperature data
    Serial.print("Temp: ");
    Serial.print(temp.temperature);
    Serial.println(" C");

    delay(500); // Delay for readability
}
