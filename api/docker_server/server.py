# -*- coding: utf-8 -*-
from flask import request, Flask, Response
import mysql.connector
from mysql.connector import MySQLConnection, Error
from flask import Flask
from flask import request
from flask import render_template
import json
import ConfigParser
from flask_cors import CORS

app = Flask(__name__)
CORS(app)


conn = mysql.connector.connect(host='mysql.server',
                                       database='gps_wifi',
                                       user='gps_admin',
                                       password='pass')

def getAllWifi():
    try:
        cursor = conn.cursor()
        cursor.execute("SELECT LATITUDE, LONGITUDE, signal_intensity FROM data")
        list_wifi = []
        rows = cursor.fetchall()
        for row in rows:
            wifi = {"latitude":row[0],"longitude":row[1],"signal_strenght":row[2]}
            list_wifi.append(wifi)
        print list_wifi

    except:
        pass
        list_wifi = []
    return list_wifi

@app.route('/current_wifi')
def getCurrentWifiHandler():
    with open("./files/signal.json") as dataset:
            data = json.load(dataset)
    if data != 0:
        ret = {
            'status':'ok',
            'data' : data
        }
    else:
        ret = {
            'status':'no data',
            'data': []
        }

    return Response(json.dumps(ret), mimetype="application/json")

@app.route('/retrieve_all_wifi')
def getAllWifiHandler():
    data = getAllWifi()
    if data != 0:
        ret = {
            'status':'ok',
            'data' : data
        }
    else:
        ret = {
            'status':'no data',
            'data': []
        }

    return Response(json.dumps(ret), mimetype="application/json")


if __name__ == '__main__':
    app.run(debug=False, threaded=True, port=5000, host='0.0.0.0')
