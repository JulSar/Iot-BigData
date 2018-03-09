# Iot-BigData

IOT Project to retrieve wifi signal intensity and location

### Description

Api flask retrieve:
- a list of all wifi with lat, long and signal intensity
- the current wifi

### Usage

Go in */mysql_bd*. Run:

`docker-compose up -d`

Go in  */api*. Run:

`python api_V1.py`
`python server.py`


### URL

list of all wifi:
`http://localhost:5000/retrieve_all_wifi`

The current wifi:
`http://localhost:5000/retrieve_all_wifi`
