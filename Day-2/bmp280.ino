#include <Wire.h>

#define BMP280_ADDRESS 0x76 // I2C address of BMP280 (can also be 0x77)
#define TEMP_PRESS_CALIB_DATA_START 0x88
#define TEMP_PRESS_DATA_START 0xF7

int32_t t_fine;

// Function to read a register from the sensor
uint16_t read16(uint8_t reg)
{
    Wire.beginTransmission(BMP280_ADDRESS);
    Wire.write(reg);
    Wire.endTransmission();

    Wire.requestFrom(BMP280_ADDRESS, (uint8_t)2);
    return (Wire.read() << 8) | Wire.read();
}

// Function to read temperature and pressure data
void readTemperatureAndPressure()
{
    uint32_t raw_temp = ((uint32_t)read16(0xFA) << 12) | ((uint32_t)read16(0xFB) << 4);
    uint32_t raw_press = ((uint32_t)read16(0xF7) << 12)
