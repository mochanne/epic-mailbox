#include <SoftwareSerial.h>


const String SSID = "gamerzone";
const String password = "12345678";
const String backend_ip = "192.168.0.1";

const int rx_pin = 3;
const int tx_pin = 4;


/// Default esp baudrate. this is too fast for the arduino, so the new baudrate is flashed to the ESP8266 on first run
/// Comment out the first line and uncomment the second line after first run, then reupload
const int baud_rate = 115200;
//const int baud_rate = 9600;/


SoftwareSerial ESPserial(rx_pin, tx_pin); // RX | TX

 




void setup()

{

  Serial.begin(9600);
  ESPserial.begin(9600);

  Serial.println("Debug start");

  Serial.print("Waiting on serial");
  while (not ESPserial.available() ) {
    ESPserial.write("AT");
    delay(100);
    Serial.print("."); 
  }
  Serial.println();
  Serial.println("Serial connected.");

  Serial.println("Changing ESP8266 bauderate to 9600 if it hasn't already.");
  ESPserial.write("AT+UART_DEF=9600,8,1,0,0");
  Serial.println("If you haven't run this before, please change the bauderate");
  
  Serial.println("connecting to "+SSID);
  Serial.println("Waiting on connection...");
  ESPserial.print("AT+CWJAP_CUR=\""+SSID+"\",\""+password+"\"");
    Serial.println("ESP >> ");
  while (ESPserial.available()) {
    Serial.print(ESPserial.read());
  }
 
  Serial.println("Ready");
}




void loop()

{
  
  // listen for communication from the ESP8266 and then write it to the serial monitor
 
  if ( ESPserial.available() ) {

    
    Serial.write( ESPserial.read() );
  }

  // listen for user input and send it to the ESP8266

  if ( Serial.available() ) {
    ESPserial.write( Serial.read() );
  }

}
