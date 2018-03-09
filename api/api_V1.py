import paho.mqtt.client as mqtt
from flask import request, Flask, Response
from flask_cors import CORS
import json
import uuid
import os
import errno
import mysql.connector
from mysql.connector import MySQLConnection, Error


conn = mysql.connector.connect(host='localhost',
                                       database='gps_wifi',
                                       user='gps_admin',
                                       password='pass')

def insert_bdd(data):
    data = data.split(",")

    query = "INSERT INTO data(LATITUDE, LONGITUDE, signal_intensity) " \
            "VALUES(%s,%s,%s)"
    args = (data[0], data[1], data[2])

    try:

        cursor = conn.cursor()
        cursor.execute(query, args)
        print("data inserted")
        conn.commit()
    except Error as error:
        print(error)

def get_current_wifi(data):
    data = data.split(",")
    data = {"latitude":data[0],"longitude":data[1],"signal_strenght":data[2]}
    print data
    with open("files/signal.json", 'w') as outfile:
        json.dump(data, outfile)




# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))

    # Subscribing in on_connect() means that if we lose the connection and
    # reconnect then subscriptions will be renewed.
    client.subscribe("topic/wifi")

# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):
    data = msg.payload.decode("utf-8")
    try:
        insert_bdd(data)
        get_current_wifi(data)
    except:
        print "error"


client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect("localhost", 1883, 60)
client.loop_forever()
