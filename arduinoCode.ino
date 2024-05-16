#include <DHT.h> 
#include <SoftwareSerial.h> 
#define DHTPIN 2 // Pin where the DHT11 sensor is connected 
#define DHTTYPE DHT11 // Change to DHT22 if you're using a DHT22 sensor 

DHT dht(DHTPIN, DHTTYPE); 
const int sensorPin = A0;  // Soil Moisture Sensor Pin 
const int relayPin = 7;    // Relay Pin 
SoftwareSerial BTSerial(10, 11); 

void setup() { 
    Serial.begin(9600); 
    pinMode(sensorPin, INPUT); 
    pinMode(relayPin, OUTPUT); 
    dht.begin(); 
    BTSerial.begin(9600); 
} 

void loop() { 
    int soilMoisture = analogRead(sensorPin); 
    Serial.print("Soil Moisture: "); 
    Serial.println(soilMoisture); 

    if (soilMoisture > 650) { 
        Serial.println("No moisture, Soil is dry"); 
        digitalWrite(relayPin, LOW);  // Turn off the relay 
    } 
    
    else if (soilMoisture >= 300 && soilMoisture <= 650) { 
        Serial.println("There is some moisture, Soil is medium"); 
        digitalWrite(relayPin, HIGH);  // Turn on the relay 
    } 
    
    else { 
        Serial.println("Soil is wet"); 
        digitalWrite(relayPin, HIGH);  // Turn on the relay 
    } 

    float humidity = dht.readHumidity(); 
    float temperature = dht.readTemperature();

    if (!isnan(humidity) && !isnan(temperature)) { 
        Serial.print("Humidity: "); 
        Serial.print(humidity); 
        Serial.println("%"); 
        Serial.print("Temperature: "); 
        Serial.print(temperature); 
        Serial.println("°C"); 
        BTSerial.print("Soil Condition: "); 

        if (soilMoisture > 650) { 
            BTSerial.println("No moisture, Soil is dry"); 
        } 
        else if (soilMoisture >= 300 && soilMoisture <= 650) { 
            BTSerial.println("There is some moisture, Soil is medium"); 
        } 
        else { 
            BTSerial.println("Soil is wet"); 
        } 

        BTSerial.print("Humidity: "); 
        BTSerial.print(humidity); 
        BTSerial.println("%"); 
        BTSerial.print("Temperature: "); 
        BTSerial.print(temperature); 
        BTSerial.println("°C"); 
    } 
    
    else { 
        Serial.println("Failed to read from DHT sensor!"); 
    } 
    
    delay(1000);  // Wait a moment before the next DHT reading 
}