import serial
import pandas as pd
from datetime import datetime

# Replace 'COMX' with the correct COM port where your Bluetooth device is connected
ser = serial.Serial('COM4', 9600)

# Create an empty list to store the data
try:
    existing_data = pd.read_csv('sensor_data.csv')
    data_list = existing_data.to_dict(orient='records')
except FileNotFoundError:
    data_list = []

while True:
    try:
        soil_condition, humidity, temperature = None, None, None

        while not (soil_condition and humidity is not None and temperature is not None):
            data = ser.readline().decode('utf-8').strip()
            print("Received Data: " + data)

            if data.startswith("Soil Condition"):
                soil_condition = data.replace("Received Data: Soil Condition: ", "")
            elif data.startswith("Humidity"):
                humidity = float(data.split(":")[1].strip().replace("%", ""))
            elif data.startswith("Temperature"):
                temperature = float(data.split(":")[1].strip().replace("°C", ""))

        # Get the current timestamp
        timestamp = datetime.now()

        # Extract date and time from the timestamp
        date = timestamp.strftime("%Y-%m-%d")
        time = timestamp.strftime("%H:%M:%S")

        # Append the data to the list
        data_list.append({
            "Date": date,
            "Time": time,
            "Temperature": temperature,
            "Humidity": humidity,
            "SoilCondition": soil_condition
        })

        # Save the data to a CSV file (update the file with the new data)
        df = pd.DataFrame(data_list)
        df.to_csv('sensor_data.csv', index=False)

    except Exception as e:
        print(f"Error: {e}")

# Close the serial port when done (you can add this after a certain condition or key press)
# ser.close()