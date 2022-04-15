#include <SoftwareSerial.h>
#include "esp8266_AT.h"



// wifi SSID
#define SSID "VRV951796F6D2"
// wifi password
#define password "FVTKcUq6CqAg"


// IP of laravel backend
const String backend_ip = "192.168.2.171";

/// Send heartbeat every 30000 seconds to backend to make sure it knows we're online
const int heartbeat_rate = 3000;







// pin numbers of helper debug software serial
#define rx_pin 3
#define tx_pin 4

#define SERIAL_SPEED 115200
#define SERIAL_TIMEOUT 8000

SoftwareSerial ESPserial(rx_pin, tx_pin);
Esp8266AT esp8266AT(&ESPserial, &Serial);

// SoftwareSerial ESPserial(rx_pin, tx_pin); // RX | TX

bool initialrun = false;
int ms_since = 0;
bool connected = false;

void setup()

{

  Serial.begin(SERIAL_SPEED);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.setTimeout(SERIAL_TIMEOUT);

  // set the data rate for the SoftwareSerial port
  ESPserial.begin(SERIAL_SPEED);

  // Serial.begin(baud_rate);
  // ESPserial.begin(baud_rate);
}

void heartbeat() {
  Serial.println("sending heartbeat!");
  if (!esp8266AT.post(backend_ip, 80, "/api/heartbeat", "application/x-www-form-urlencoded","", "200")) {
    Serial.println("Last GET was failed");
  }

}

void mainloop() {}

void loop() {

  if (!connected) {
    if (!esp8266AT.setup(SSID, password)) {
      Serial.println("Connection failed, will repeat in 5 sec");
    } else {
      connected = true;
    }
  }

  mainloop();

  if (ms_since > heartbeat_rate) {
    heartbeat();
    ms_since = 0;
  }

  delay(50);
  ms_since += 50;
}
