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

Mise en route du serveur Mosquito

```
Give the example
```

And repeat

```
until finished
```

Une fois le serveur node.js lancé, vous devriez pouvoir accéder à l'interface de visualisation 

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

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Development

### [front](front)

The web application is a [Vue.js application](https://vuejs.org/).

To run it locally, you need [NodeJs](https://nodejs.org/en/).

To install all dependencies :

`cd front && npm i`

To start a development environment :

`npm run serve`

## Authors

* **Julien Sarrazin** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

Participants au projet
[contributors](https://github.com/your/project/contributors)


## Sources

https://www.xarg.org/2016/06/neo6mv2-gps-module-with-arduino/
