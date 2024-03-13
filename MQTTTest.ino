#include <WiFi.h>
#include <PubSubClient.h>

const char *ssid = "MultilaserPRO_ZTE_2.4G_TDEDEd";
const char *password = "PSRMFKfR";

const char *mqttServer = "test.mosquitto.org";
const int mqttPort = 1883;

const char* mqtt_user = "";
const char* mqtt_password = "";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
	Serial.begin(115200);
	WiFi.begin(ssid, password);

	while(WiFi.status() != WL_CONNECTED){
		delay(500);
		Serial.println("Conectando...");
	}
	Serial.println("Conectado a rede!");

	client.setServer(mqttServer, mqttPort);
}

void loop() {
	
	if(client.connect("Esp32", mqtt_user, mqtt_password)){
		client.publish("teste/l", "Everything alright");
	}

	delay(500);
}
