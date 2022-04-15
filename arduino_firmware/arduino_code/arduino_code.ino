#include "DistanceSensor.h"
#include <SoftwareSerial.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Upload deze code naar de arduino
// Bekijk het bouwplan om te checken dat alles goed is!

// vvv verander deze waardes voor uploaden vvv



// Gebruik je meer of minder dan 5 sensoren? verander dan de array hieronder en zet sensor_count naar het aantal sensoren
// DistanceSensor(trig_pin, echo_pin)
DistanceSensor sensoren[] = {DistanceSensor(A0,A1), DistanceSensor(A2,A3), DistanceSensor(6,5), DistanceSensor(10,11), DistanceSensor(7,8)};
const int sensor_aantal = 5;


const String SSID = "VRV951796F6D2";
// SSID van het netwerk waar het backend op draait
const String password = "FVTKcUq6CqAg";
// wachtwoord van het netwerk waar het backend op draait
const String backend_ip = "192.168.2.175";
// Het (lokale) ip van het backend



// ^^^ verander deze waardes voor uploaden ^^^


// Zet op true om de sensoren te debuggen; er zal dan niks naar de esp verzonden worden
const bool no_wifi = false;


// pins gebruikt voor de ESP serial
const int rx_pin = 3;
const int tx_pin = 4;


// Hoe vaak een heartbeat naar het backend word verstuurd
// standaard elke 30 seconden
const int heartbeat_rate = 20000;

// Baude rate van de USB serial voor debugging en de ESP serial
// let op: de ESP word automatisch op 9600 gezet, maar het kan zijn dat de eerste keer dat je de esp gebruikt de baudrate op 115200 staat
// Dus zet dit naar 115200 op de 1e run, zet de arduino uit, en wissel het weer terugn naar 9600
const int baud_rate = 9600;

// Esp serial object voor communicatie
SoftwareSerial ESPserial(rx_pin, tx_pin); // RX | TX

// Het display object
LiquidCrystal_I2C lcd(0x27,16,2);

// standaard waardes
bool initialrun = false;
int ms_since = 0;
int curr_obstruct = 0;






// vvv lcd scherm functies vvv

void schermprint(String in, int line=0) {
  lcd.setCursor(0,line);
  lcd.print("                ");
  lcd.setCursor(0,line);
  lcd.print(in);
}


// vvv mainloop functies


void loop()

{
  Serial.print("current ms: ");
  Serial.println(ms_since);
    if (ms_since > heartbeat_rate) {
      heartbeat();
      ms_since = 0;
   }
  
   if (!initialrun) {
      run_initialisation();
  } else {
      mainloop();
  }

  


  if ( ESPserial.available() ) {
    Serial.write( ESPserial.read() );
  }

  if ( Serial.available() ) {
    ESPserial.write( Serial.read() );
  }
  countdelay(150);

}


void setup() {
  Serial.begin(baud_rate);
  ESPserial.begin(baud_rate);
  calibrate_all();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
}


void mainloop() {
  Serial.println("");
  Serial.println("Mainloop!");
  int new_obstruct = get_obstructed_count();
  schermprint("Bedekte sensoren");
  String sob = (String)new_obstruct;
  String sa = (String)sensor_aantal;
  Serial.println("Obstructed sensors: "+sob+"/"+sa);
  schermprint(sob+"/"+sa, 1);
  if (new_obstruct != curr_obstruct) {
    if (new_obstruct == 0) {
      stuur_status(false);
     } else if (curr_obstruct == 0 && new_obstruct > 0) {
      stuur_status(true); 
     }
  }
  curr_obstruct = new_obstruct;
}




void run_initialisation() {
  Serial.println("Debug start");


  ESPserial.write("AT+UART_DEF=9600,8,1,0,0\r\n");
  // zet de esp baudrate naar 9600

  Serial.println("connecting to " + SSID);
  connect_ap(SSID, password);

  Serial.println("Ready");
  curr_obstruct = get_obstructed_count();
  initialrun = true;
  heartbeat();
}





// vvv esp functies vvv


void espsend(String in, int wait = 1500) {
  if (no_wifi) {
  Serial.println("Early return! no command sent");
  return;
  }

  // verstuurt direct een string naar de esp en wacht een paar seconden
  // \r\n word automatisch toegevoegd
  in += "\r\n";
  ESPserial.print(in);
  countdelay(wait);
}

void heartbeat() {
  // vertsuurt een request naar het backend om te laten weten dat de arduino verbonden is
  // dit moet elke `heartbeat_rate` seconden gebeuren, anders zal de status op het frontend
  // naar offline worden gezet
  Serial.println("Heartbeat word verzonden");
  schermprint("Heartbeat naar",0);
  schermprint(backend_ip,1);
  connect(backend_ip, "80");
  make_get("/api/heartbeat/");  
}


void connect(String ip, String port) {
  // Maakt een TCP verbinding met een computer op het huidige netwerk
  // dit moet uigevoerd worden voordat een GET verstuurd kan worden
  String out = "AT+CIPSTART=\"TCP\",\""+ip+"\","+port;
  espsend(out);
}


void make_get(String url) {
  // Maak een HTTP GET request naar een specifieke URL op de verbonden host
  // let op: eerst moet connect() uitgevoerd worden met een host
  // let op: om de code simpel en consistent te houden word er geen data van het backend
  // naar de arduino verstuurd, en worden de api requests als GETs verstuurd.
  // Deze functie returned dus ook geen data.
  String out = "GET "+url+" HTTP/1.0\r\n";
  String fullout = out+"\r\n";
  String amount = (String) fullout.length();
  String cipsend = "AT+CIPSEND="+amount+"\r\n";
  
  espsend(cipsend);
  // de grootte van het bericht word eerst verstuurd
  espsend(out, 3500);
  // dan het bericht zelf
}


void connect_ap(String SSID, String password) {
  // verbind met een access point (netwerk)
  schermprint("Verbinden met");
  schermprint(SSID, 1);
  espsend("AT+CIPMUX=0");
  espsend("AT+CWMODE=1");
  espsend("AT+CWJAP_CUR=\"" + SSID + "\",\"" + password + "\"", 5000);
}



void stuur_status(bool wel_post) {
  // Stuur een status update naar het backend
  // let op: stuur alleen als het ook echt geupdate is, anders word de database volgespammed
  schermprint("update post naar");
  schermprint(backend_ip, 1);
  Serial.print("Status api call: ");
  Serial.println(wel_post);
  connect(backend_ip, "80");
  if (wel_post) {
    make_get("/api/welpost");
  } else {
    make_get("/api/geenpost");
  }
}


void countdelay(int ms) {
  for (int mydelay = 0; mydelay < ms; mydelay += 10) {
    delay(10);
    if ( ESPserial.available() ) {
      Serial.write( ESPserial.read() );
    }
  }
  ms_since += ms;
}



// vvv sensor functies vvv

void calibrate_all() {
    schermprint("Calibratie...");
    // calibreert alle sensoren voor een paar seconden
    // hierdoor weten we hoe hoog het plafond van de brievenbus is
    for (int i = 0; i < sensor_aantal; i++) {
        schermprint((String)i + "/" + (String)sensor_aantal);
        Serial.println("Calibrating #"+(String)i);
        sensoren[i].calibrate();
    }
}



int get_obstructed_count() {
    // dit returned het aantal bedekte sensoren
    // hierdoor kunnen we meten of er post is, en of er meer of minder post bij gekomen is
    int obstructed_count = 0;
    Serial.print("Checking sensor obstruction..");
    for (int i = 0; i < sensor_aantal; i++) {
        if (sensoren[i].is_obstructed()) {
            Serial.print(i);
            Serial.println(" obstructed!");
            obstructed_count++;
        }
    }
    Serial.println("");
    Serial.println("Done");
    return obstructed_count;
}
