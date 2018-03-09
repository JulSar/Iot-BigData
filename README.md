# Iot-BigData

Ce projet a pour but de fournir en temps réel un indicateur de la qualité des réseaux wifi environnants. Pour ce faire nous utiliserons seulement un module ESP8266 disposant d'un module WIFI et une barre à LED. Le module doit pouvoir se connecter à un réseau pour transmettre les données requeuillis à un serveur Mosquito.
Dans le projet initial nous comptions utiliser un composant GPS mais le composant etant défectueux nous nous sommes rabbatu vers les API google de géolocalisation.

![Architecture](https://github.com/JulSar/Iot-BigData/raw/master/assets/archi.PNG)

### Prérequis et liens utiles

Matériel :
![Wemos](https://github.com/JulSar/Iot-BigData/raw/master/assets/esp8266-Wemos.jpg)
![GPS](https://github.com/JulSar/Iot-BigData/raw/master/assets/neo-6m1.jpg)

L'ensemble des librairies utilisées sont dans le dossier lib.
Documentation MQTT:
http://docs.oasis-open.org/mqtt/mqtt/v3.1.1/csprd02/mqtt-v3.1.1-csprd02.html

### Installing

Plusieurs installations sont possibles. Avec le code fournit un simple module ESP8266 seul suffit à aquérir les données.
Il est possible de récupérer les données par un module GPS externe branché sur le module ou un arduino.

Installation avec module GPS :
![Arduino Setup](https://github.com/JulSar/Iot-BigData/raw/master/assets/arduino_setup.png)

L'infrastructure (serveur, mysql, mosquito) tourne avec [docker compose](https://docs.docker.com/compose/).

Il suffit de taper `docker-compose up` pour la lancer.

Nous avons une application web pour visualiser l'application.

![](https://puu.sh/zDYQS/32b257049b.jpg)

L'application web est une [application Vue.js](https://vuejs.org/).

Pour la lancer, vous aurez besoin de [NodeJs](https://nodejs.org/en/).

Pour installer les dependances :

`cd front && npm i`

Pour lancer l'application :

`npm run serve`

## Running the tests

Voici comment tester le module GPS pour vérifier qu'il récupère bien des données.
```C++
#include <SoftwareSerial.h>
#include <TinyGPS.h>

SoftwareSerial mySerial(3, 4); // RX, TX
TinyGPS gps;

void setup()  {
  mySerial.begin(9600);
}

void loop() {
  bool ready = false;
  if (mySerial.available()) {
    char c = mySerial.read();
    if (gps.encode(c)) {
      ready = true;
    }
  }

  // Use actual data
  if (ready) {
    // Use `gps` object
  }
}
```

## Auteurs

* **Julien Sarrazin**
* **Pascal Luttgens**
* **Mauranne Costier**
* **Bastien Brunod**


## Sources

https://www.xarg.org/2016/06/neo6mv2-gps-module-with-arduino/
