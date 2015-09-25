# IRTank
Távirányítós Lánctalpas modell

TV távirányítóval kezelhető, a két külön lánctalp (két motor) sebssége külön állítható.
Van egy LED lámpája is
Hardware: 
- Arduino Leonardo mikrokontroller 
- Adafruit MotorShield v2
- IR vevő 
- fehér Led
 

https://cloud.githubusercontent.com/assets/14834120/10111056/76525408-63d1-11e5-874d-1ad4d3a7b75f.jpg

az IR vevő a 7-es lábra van kötve a Leonardo-n
Össze van dugva a motor shield-del a Leonardo
A soros portra mindig kiírja a kódját a távirányítónak, azaz a gomb kódját, amit lenyomtál

tutorial IR vevőről:
http://www.instructables.com/id/The-Easiest-Way-to-Use-Any-IR-Remote-with-Ardiuno/#step0

Az IR vevő bekötése (a pléldaprogram ebben nagyon rossz , azt ne nézd, de az IR vavő működésénekl leírása az jó:
https://learn.adafruit.com/ir-sensor/overview

Így kell könyvtárat telepíteni:
https://learn.adafruit.com/adafruit-all-about-arduino-libraries-install-use/arduino-libraries

A könyvtár:
Innen lehet letölteni:
https://github.com/z3t0/Arduino-IRremote/releases
vagy itt lehet megnézni/letölteni:
https://github.com/z3t0/Arduino-IRremote
