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


void countdelay(int ms) {
  for (int mydelay = 0; mydelay < ms; mydelay += 10) {
    delay(10);
    if ( ESPserial.available() ) {
      Serial.write( ESPserial.read() );
    }
  }
  ms_since += ms;
}


void setup()

{

  Serial.begin(baud_rate);
  ESPserial.begin(baud_rate);
 

}

void espsend(String in, int wait = 2500) {
  in += "\r\n";
//  Serial.println("Sending>>"+in);
  ESPserial.print(in);
  countdelay(wait);
}

void heartbeat() {
  Serial.println("HEARTBEAT GO!!!!!!! NU!!! WEKR!!!! GAMING 2022 REAL WORKING!!!");
  connect(backend_ip, "80");
  make_get("/api/heartbeat/");  
}

void connect(String ip, String port) {
  String out = "AT+CIPSTART=\"TCP\",\""+ip+"\","+port;
//  out +="\"TCP\",";
//  out +="\"";
//  out += ip;
//  out +="\",";
//  out += port;
  espsend(out);
}



void make_get(String url) {
  String out = "GET "+url+" HTTP/1.0\r\n";

  String gaming = out+"\r\n";
  String amount = (String) gaming.length();
  //Serial.println("sizeof: "+amount);
  Serial.println("length: "+amount);
  String cipsend = "AT+CIPSEND="+amount+"\r\n";
  espsend(cipsend, 5000);
  espsend(out, 5000);
}


void mainloop() {
//  Serial.println(ms_since);
  //heartbeat();
  //countdelay(5000);
}


void connect_ap(String SSID, String password) {
  espsend("AT+CIPMUX=0");
  espsend("AT+CWMODE=1");
  espsend("AT+CWJAP_CUR=\"" + SSID + "\",\"" + password + "\"", 5000);
}

void stuur_status(bool wel_post) {
  connect(backend_ip, "80");
  if (wel_post) {
    make_get("/api/welpost");
  } else {
    make_get("/api/geenpost");
  }
}

void run_initialisation() {
  Serial.println("Debug start");

    ESPserial.write("AT+UART_DEF=9600,8,1,0,0\r\n");

  if (baud_rate > 9600) {
    Serial.println("Changing ESP8266 bauderate to 9600 if it hasn't already.");
    ESPserial.write("AT+UART_DEF=9600,8,1,0,0\r\n");
    Serial.println("If you haven't run this before, please change the bauderate in the sketch file & reflash");
  }

  Serial.println("connecting to " + SSID);
  connect_ap(SSID, password);
//  Serial.println("Waiting on connection...");
//  ESPserial.print("AT+CWJAP_CUR=\"" + SSID + "\",\"" + password + "\"");
//  Serial.println("ESP >> ");
//  countdelay(500);
//  while (ESPserial.available()) {
//    Serial.print(ESPserial.read());
//  }

  Serial.println("Ready");
  initialrun = true;
  heartbeat();
}



void loop()

{
   if (!initialrun) {
      run_initialisation();
  } else {
    mainloop();
  }

  if (ms_since > heartbeat_rate) {
    heartbeat();
    ms_since = 0;
  }
  

  // listen for communication from the ESP8266 and then write it to the serial monitor

  if ( ESPserial.available() ) {
    Serial.write( ESPserial.read() );
  }

  // listen for user input and send it to the ESP8266

  if ( Serial.available() ) {
    ESPserial.write( Serial.read() );
  }
  countdelay(50);

}
