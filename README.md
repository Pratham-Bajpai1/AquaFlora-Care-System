# Plant Monitoring & Watering System Using IoT 🌱💧

![Screenshot 2024-05-16 212300](https://github.com/Pratham-Bajpai1/AquaFlora-Care-System/assets/124435912/3983ca60-55aa-48d6-bca1-44b247bbd1e7)
![Screenshot 2024-05-16 212312](https://github.com/Pratham-Bajpai1/AquaFlora-Care-System/assets/124435912/f5d56f2a-b1b6-448d-8eb5-0b49b95dc504)

Welcome to the Plant Monitoring & Watering System Using IoT! This innovative project combines IoT technology with plant care to ensure optimal growth and health for your plants. Let's explore the exciting features and functionalities of this system:

---

## Project Overview 🚀

### Soil Moisture Monitoring:
- The Arduino Uno collects and processes data from the soil moisture sensor to determine the current soil moisture level.

### Temperature and Humidity Monitoring:
- Simultaneously, the DHT11 sensor measures the ambient temperature and humidity in the plant's environment.

### Control of Water Pump:
- When the soil moisture level falls below a preset threshold, the Arduino activates the relay module, which then controls the water pump to irrigate the plant.

### Battery-Powered Operation:
- Two separate batteries are used: a 9-volt battery for the Arduino and sensors, and a 12-volt battery to power the water pump through the relay.

### Data Transmission:
- The Arduino communicates with a Bluetooth module (HC-05) to transmit both soil moisture and DHT11 sensor data to a laptop.

### Data Logging with Python:
- A Python script running on the laptop logs the received data into a CSV file, continuously collecting and logging soil moisture data.

### Power BI Data Visualization:
- The CSV file with combined data is imported into Power BI, transforming it into an interactive dashboard presenting real-time data on soil moisture, temperature, and humidity.

### User Interaction:
- Users can access the Power BI dashboard to monitor plant conditions, customize soil moisture thresholds, and make informed decisions about watering and plant care based on environmental factors.

---

## Real-Time DashBoard 🌐

![Screenshot 2023-11-07 010511](https://github.com/Pratham-Bajpai1/AquaFlora-Care-System/assets/124435912/a58e2611-eedc-4c52-af44-57047ac3ce13)

**PowerBI DashBoard Link - https://app.powerbi.com/links/ISPKT9bBLy?ctid=866f7fb5-6d0d-4904-b9b4-2a8baf60b820&pbi_source=linkShare

---

## How It Works 🔄

1. **Data Collection:** The Arduino collects soil moisture, temperature, and humidity data.
2. **Threshold Check:** If soil moisture falls below a preset threshold, the water pump is activated.
3. **Data Transmission:** Data is transmitted to a laptop via Bluetooth.
4. **Data Logging:** Python script logs data into a CSV file.
5. **Data Visualization:** Power BI creates an interactive dashboard for real-time monitoring.
6. **User Interaction:** Users access the dashboard to customize settings and monitor plant conditions.

---

## Benefits 🌟

- Automates plant watering for optimal growth and health.
- Conserves water by watering plants only when necessary.
- Provides real-time monitoring and data-driven insights for informed decision-making.

---

## Get Started 🌿

1. **Hardware Setup:** Connect sensors, Arduino, relay module, water pump, and batteries as per the provided instructions.
2. **Software Installation:** Install Arduino IDE, Python, and Power BI on your laptop.
3. **Code Upload:** Upload Arduino code and run Python script on your laptop.
4. **Dashboard Access:** Access the Power BI dashboard to monitor plant conditions and customize settings.

---

Let's revolutionize plant care with IoT technology! Monitor, water, and nurture your plants for optimal growth and health! 🌿💦
