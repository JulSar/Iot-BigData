from __future__ import print_function
from datetime import date, datetime, timedelta
import mysql.connector



conn = mysql.connector.connect(host='localhost',
                                       database='gps_wifi',
                                       user='gps_admin',
                                       password='pass')
def insert_data(data):
    query = "INSERT INTO data(LATITUDE, LONGITUDE, signal_intensity) " \
            "VALUES(%s,%s,%s)"
        
    cursor = conn.cursor()
    cursor.executemany(query, data)
    conn.commit()

data = [('-21.805149', '-49.089977','1'),
        ('48.825183', '2.1985795','5'),
        ('-18.529225', '-70.25002','2')]

insert_data(data)
