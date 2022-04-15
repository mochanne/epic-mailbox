#include <SoftwareSerial.h>


const String SSID = "VRV951796F6D2";
const String password = "FVTKcUq6CqAg";
const String backend_ip = "192.168.2.175";

const int rx_pin = 3;
const int tx_pin = 4;

/// Send heartbeat every 30000 seconds to backend
const int heartbeat_rate = 30000;

/// Default esp baudrate. this is too fast for the arduino, so the new baudrate is flashed to the ESP8266 on first run
/// Comment out the first line and uncomment the second line after first run, then reupload
//const int baud_rate = 115200;/
const int baud_rate = 9600;//


SoftwareSerial ESPserial(rx_pin, tx_pin); // RX | TX


bool initialrun = false;
int ms_since = 0;


void setup()

{

  Serial.begin(baud_rate);
  ESPserial.begin(baud_rate);


}


void heartbeat() {

}


void mainloop() {

}


void run_initialisation() {
  Serial.println("Debug start");

  Serial.print("Waiting on serial");
  while (!ESPserial) {
    ESPserial.write("AT");
    delay(100);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Serial connected.");

  if (baud_rate > 9600) {
    Serial.println("Changing ESP8266 bauderate to 9600 if it hasn't already.");
    ESPserial.write("AT+UART_DEF=9600,8,1,0,0");
    Serial.println("If you haven't run this before, please change the bauderate in the sketch file & reflash");
  }

  Serial.println("connecting to " + SSID);
  Serial.println("Waiting on connection...");
  ESPserial.print("AT+CWJAP_CUR=\"" + SSID + "\",\"" + password + "\"");
  Serial.println("ESP >> ");
  delay(500);
  while (ESPserial.available()) {
    Serial.print(ESPserial.read());
  }

  Serial.println("Ready");
  initialrun = true;
}



void loop()

{
   if (initialrun) {
      run_initialisation();
  } else {
    mainloop();
  }
  

  // listen for communication from the ESP8266 and then write it to the serial monitor

  if ( ESPserial.available() ) {


    Serial.write( ESPserial.read() );
  }

  // listen for user input and send it to the ESP8266

  if ( Serial.available() ) {
    ESPserial.write( Serial.read() );
  }
  delay(50);

}
