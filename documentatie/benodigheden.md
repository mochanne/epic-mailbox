# Benodigheden

- [Antenne                        1x](https://www.tinytronics.nl/shop/nl/communicatie-en-signalen/draadloos/antennes/2.4ghz/2.4ghz-wifi-antenne-met-sma-naar-ufl-connector)
- [ESP8266 ESP01                  1x](https://www.tinytronics.nl/shop/nl/communicatie-en-signalen/draadloos/wi-fi/modules/esp8266-wifi-module-esp-01-1mb)
- [Arduino nano/uno               1x](https://www.tinytronics.nl/shop/nl/development-boards/microcontroller-boards/arduino-compatible/nano-v3.0-compatible)
- [Breadboard/prototyping board   1x](https://www.tinytronics.nl/shop/nl/gereedschap-en-montage/prototyping-toebehoren/breadboards/breadboard-830-points)
- [Ultrasonische sensor           5x](https://www.tinytronics.nl/shop/nl/sensoren/afstand/ultrasonische-sensor-hc-sr04)
- [Kabels                           ](https://www.tinytronics.nl/shop/nl/kabels-en-connectoren/kabels-en-adapters/prototyping-draden/dupont-compatible-en-jumper/dupont-jumper-draad-male-male-20cm-10-draden) 
- [3.3v naar 5v converter         1x](https://www.tinytronics.nl/shop/nl/communicatie-en-signalen/level-converters/spi-i2c-uart-bi-directionele-logic-level-converter-4-kanaals)
- [Breadboard voeding                    1x](https://www.tinytronics.nl/shop/nl/power/spanningsconverters/spanningsregelaars/breadboard-voeding-5v-en-3.3v)
- [LCD Display                    1x](https://www.tinytronics.nl/shop/en/displays/lcd/lcd-display-16*2-characters-with-white-text-and-blue-backlight-with-i2c-backpack)

## Waar zijn de benodigdheden voor nodig?

De Wi-Fi antenne wordt gebruikt om het signaal van de Wi-Fi module in de brievenbus te versterken omdat de brievenbus van metaal is en dit het signaal kan blokkeren. De antenne kan aangesloten worden op de ESP8266.

De Wi-Fi module (ESP8266 ESP01) is nodig om verbinding te maken met een Wi-Fi netwerk zodat er gecommuniceerd kan worden met het domotica-systeem/de laravel backend. Via deze module kan de Arduino in de brievenbus data versturen, waarbij de backend update.

De Arduino is belangrijk om te zorgen dat alles aangesloten wordt, de juiste functie uitvoert, en om de nieuwe data naar de backend te sturen via de Wi-Fi module. Het is het beste om gebruik te maken van een Arduino nano, sinds deze in dit project gebruikt wordt. Een Arduino uno inplaats van de Arduino nano zou ook moeten werken maar deze is een stuk groter en past niet op het breadboard.

Het breadboard is nodig om te zorgen dat alle kabels en modules goed met elkaar verbonden zijn, en dat de nodige modules genoeg elektriciteit hebben. We gebruiken voor dit project een breadboard met 830 punten zodat er voor alle componenten genoeg ruimte is.

De ultrasonische sensor zorgt voor het detecteren van de beweging van brieven, waardoor er updates en notificaties kunnen worden gestuurd naar het domotica systeem. Om te zorgen dat er geen brieven gemist worden zijn er minimaal 5 sensoren nodig. 

De kabels zijn belangrijk om alles goed aan elkaar aan te sluiten. Ook zijn er minimaal 20 kabels nodig, omdat er veel dingen zullen moeten worden aangesloten. Voor op het breadboard gebruiken we male-male kabels en om de verschillende modules aan te sluiten gebruiken we male-female kabels.

De 3.3v naar 5v converter is nodig, omdat de wifi module op 3.3v draait en de communicatie van de Arduino via 5V gaat.

De breadboard voeding is nodig om de ESP8266 van stroom te voorzien omdat de Arduino Nano zelf niet genoeg stroom kan leveren.

De LCD display wordt gebruikt om de status van de Arduino te tonen en eventueel andere informatie over het systeem. 
