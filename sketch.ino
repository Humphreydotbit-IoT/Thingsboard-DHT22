#include <DHTesp.h>
// #include <WiFi.h>
// #include <ThingsBoard.h>
// #include <Arduino_MQTT_Client.h>

#define pinDht 15
DHTesp dhtSensor;

// #define WIFI_AP "Wokwi-GUEST"
// #define WIFI_PASS ""

// #define TB_SERVER "thingsboard.cloud"
// #define TOKEN "mrat4FDOlyjuocB08l4g"

// constexpr uint16_t MAX_MESSAGE_SIZE = 256U;

// WiFiClient espClient;
// Arduino_MQTT_Client mqttClient(espClient);
// ThingsBoard tb(mqttClient, MAX_MESSAGE_SIZE);

// void connectToWiFi() {
//   Serial.println("Connecting to WiFi...");
//   int attempts = 0;
  
//   while (WiFi.status() != WL_CONNECTED && attempts < 20) {
//     WiFi.begin(WIFI_AP, WIFI_PASS, 6);
//     delay(500);
//     Serial.print(".");
//     attempts++;
//   }
  
//   if (WiFi.status() != WL_CONNECTED) {
//     Serial.println("\nFailed to connect to WiFi.");
//   } else {
//     Serial.println("\nConnected to WiFi");
//   }
// }

// void connectToThingsBoard() {
//   if (!tb.connected()) {
//     Serial.println("Connecting to ThingsBoard server");
    
//     if (!tb.connect(TB_SERVER, TOKEN)) {
//       Serial.println("Failed to connect to ThingsBoard");
//     } else {
//       Serial.println("Connected to ThingsBoard");
//     }
//   }
// }

// void sendDataToThingsBoard(float temp, int hum) {
//   String jsonData = "{\"tempIn\":" + String(temp) + ", \"humIn\":" + String(hum) + ", \"tempOut\":" + "0" + ", \"humOut\":" + "0"+ ", \"pressure\":" + "0"+ ", \"rainfall\":" + "0"+ ", \"windSpeed\":" + "0"+ ", \"windDirection\":" + "0" + ", \"windAVG\":" +"0"+"}";
//   tb.sendTelemetryJson(jsonData.c_str());
//   Serial.println("Data sent");
// }

void setup() {
  Serial.begin(115200);
  dhtSensor.setup(pinDht,DHTesp::DHT22);
  // connectToWiFi();
  // connectToThingsBoard();
}

void loop() {
  // connectToWiFi();

  TempAndHumidity data =dhtSensor.getTempAndHumidity();
  float temp = data.temperature;
  int hum = data.humidity;

  Serial.println(temp);
  Serial.println(hum);

  // if (!tb.connected()) {
  //   connectToThingsBoard();
  // }

  // sendDataToThingsBoard(temp, hum);

  delay(3000);

  // tb.loop();
}
