# Benodigheden

- [Pin headers                    1x](https://www.tinytronics.nl/shop/nl/kabels-en-connectoren/connectoren/pin-headers/male/40-pins-header-male-rood)
- [Multiplexer                    1x](https://www.tinytronics.nl/shop/nl/communicatie-en-signalen/io-converters/hc4067-16-kanaals-analoge-multiplexer)
- [Antenne                        1x](https://www.tinytronics.nl/shop/nl/communicatie-en-signalen/draadloos/antennes/2.4ghz/2.4ghz-wifi-antenne-met-sma-naar-ufl-connector)
- [ESP8266 ESP01                  1x](https://www.tinytronics.nl/shop/nl/communicatie-en-signalen/draadloos/wi-fi/modules/esp8266-wifi-module-esp-01-1mb)
- [Arduino nano/uno               1x](https://www.tinytronics.nl/shop/nl/development-boards/microcontroller-boards/arduino-compatible/nano-v3.0-compatible)
- [Breadboard/prototyping board   1x](https://www.tinytronics.nl/shop/nl/gereedschap-en-montage/prototyping-toebehoren/breadboards/breadboard-400-points)
- [Ultrasonische sensor           5x](https://www.tinytronics.nl/shop/nl/sensoren/afstand/ultrasonische-sensor-hc-sr04)
- [Kabels                           ](https://www.tinytronics.nl/shop/nl/kabels-en-connectoren/kabels-en-adapters/prototyping-draden/dupont-compatible-en-jumper/dupont-jumper-draad-male-male-20cm-10-draden) 
- [Resistors                        ](https://www.tinytronics.nl/shop/nl/componenten/weerstanden/weerstanden/10k%CF%89-weerstand-standaard-pull-up-of-pull-down-weerstand)
- [3.3v naar 5v converter         1x](https://www.tinytronics.nl/shop/nl/communicatie-en-signalen/level-converters/spi-i2c-uart-bi-directionele-logic-level-converter-4-kanaals)

## Waar zijn de benodigdheden voor nodig?

De pin header is nodig om te solderen aan de multiplexer en de wifimodule zodat deze op een breadbord gezet kunnen worden en kunnen worden aangesloten op andere componenten. Wij maken gebruik van een pin header met 40 pins.

De analoge multiplexer nodig om de 5 sensoren op de Arduino nano aan te sluiten, aangezien de Arduino anders niet genoeg pins heeft. Omdat er 5 sensoren zijn, is er een minimale multiplexer nodig van 16 pinnen. 

De Wi-Fi antenne is belangrijk om te zorgen dat de Arduino, samen met de brievenbus, verbinding kan maken met het wifi netwerk. Op deze manier kan de brievenbus data ontvangen en versturen, waarbij de backend update. Zorg voor een goede antenne, rond de 2,4Ghz. De Wi-Fi antenne dient aangesloten te worden op de ESP Wi-Fi module om het signaal te versterken wanneer de ESP module in een brievenbus zit.

De Wi-Fi module (ESP8266 ESP01) is nodig om te communiceren met het domotica-systeem/de laravel backend via een wifi netwerk. 

De arduino is belangrijk om te zorgen dat alles aangesloten wordt, de juiste functie uitvoert, en de backend altijd geupdate wordt na veranderingen. Het is het beste om gebruik te maken van een Arduino nano, sinds deze in dit project gebruikt wordt. Een Arduino uno inplaats van de Arduino nano zou ook moeten werken.

Het breadboard is nodig om te zorgen dat alle kabels en modules goed met elkaar verbonden zijn, en dat de nodige modules genoeg elektriciteit hebben. Het is belangrijk dat er tenminste 400 pins in het breadboard zitten zodat er genoeg ruimte is voor alles wat aangesloten moet worden. Meer is altijd beter, maar is niet nodig.

De ultrasonische sensor zorgt voor het detecteren van de beweging van brieven, waardoor er updates en notificaties kunnen worden gestuurd naar het domotica systeem. Om te zorgen dat er geen brieven gemist worden zijn er minimaal 5 sensoren nodig.

De kabels zijn belangrijk om alles goed aan elkaar aan te sluiten. Wij raden kabels aan met een minimale lengte van 20 cm. Ook zijn er minimaal 20 kabels nodig, omdat er veel dingen zullen moeten worden aangesloten.

De resistors zijn nodig om te zorgen dat er niet te veel spanning op modules komt te staan. We raden er minimaal 5 aan, zodat de spanning nergens te veel wordt. Ook moeten deze resistors tenminste 10kΩ zijn.

De 3.3v naar 5v converter is nodig, omdat de wifi module op 3.3v draait en de Arduino 5v geeft. Door de converter zorgen wij ervoor dat er via de Arduino 3.3v bij de wifi module terecht komt.