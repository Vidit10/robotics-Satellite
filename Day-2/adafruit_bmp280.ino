#include <Wire.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // Create an instance of the BMP280 sensor

void setup()
{
    Serial.begin(115200);
    Serial.println(F("BMP280 test"));

    // Initialize the BMP280 sensor
    if (!bmp.begin())
    {
        Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
        while (1)
            ;
    }

    // Configure the sensor with default settings
    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,   /* Operating Mode */
                    Adafruit_BMP280::SAMPLING_X2,   /* Temperature oversampling */
                    Adafruit_BMP280::SAMPLING_X16,  /* Pressure oversampling */
                    Adafruit_BMP280::FILTER_X16,    /* Filtering */
                    Adafruit_BMP280::STANDBY_MS_500 /* Standby time */
    );
}

void loop()
{
    // Read and print temperature
    Serial.print(F("Temperature = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

    // Read and print pressure in hPa
    Serial.print(F("Pressure = "));
    Serial.print(bmp.readPressure() / 100.0);
    Serial.println(" hPa");

    // Read and print altitude (adjust sea-level pressure as needed)
    Serial.print(F("Approx altitude = "));
    Serial.print(bmp.readAltitude(1013.25)); // Default sea-level pressure in hPa
    Serial.println(" m");

    Serial.println();
    delay(2000); // Wait for readability
}
