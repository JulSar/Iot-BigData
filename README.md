# Iot-BigData

Ce projet a pour but de fournir en temps réel un indicateur de la qualité des réseaux wifi environnants. Pour ce faire nous utiliserons seulement un module ESP8266 disposant d'un module WIFI et une barre à LED. Le module doit pouvoir se connecter à un réseau pour transmettre les données requeuillis à un serveur Mosquito.
Dans le projet initial nous comptions utiliser un composant GPS mais le composant etant défectueux nous nous sommes rabbatu vers les API google de géolocalisation.

![Architecture](https://github.com/JulSar/Iot-BigData/raw/master/assets/archi.PNG)

### Prérequis et liens utiles

Matériel :
![Wemos](https://github.com/JulSar/Iot-BigData/raw/master/assets/esp8266-Wemos.jpg)
![GPS](https://github.com/JulSar/Iot-BigData/raw/master/assets/neo-6m1.jpg)

Mise en place du serveur node.js

L'ensemble des librairies utilisées sont dans le dossier lib.
Documentation MQTT:
http://docs.oasis-open.org/mqtt/mqtt/v3.1.1/csprd02/mqtt-v3.1.1-csprd02.html

### Installing

Plusieurs installations sont possibles. Avec le code fournit un simple module ESP8266 seul suffit à aquérir les données.
Il est possible de récupérer les données par un module GPS externe branché sur le module ou un arduino.

Installation avec module GPS :
![Arduino Setup](https://github.com/JulSar/Iot-BigData/raw/master/assets/arduino_setup.png)

A step by step series of examples that tell you have to get a development env running

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo

## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
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

## Authors

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone who's code was used
* Inspiration
* etc
