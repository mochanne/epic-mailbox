import mysql.connector
import time

import serial
import os

mydb = mysql.connector.connect(
    host="localhost",
    user="laravel_user",
    passwd="1971",
    database="mail_database"
)

port = serial.Serial("COM3", baudrate=9600, timeout=3.0)


mycursor = mydb.cursor()
while True:
    rcv = port.readline().strip()
    ls = [char for char in rcv]
    print(rcv)
    if len(ls) == 1:

        if(ls[0] == 98):
            print("post")
            mycursor.execute("UPDATE letters SET Brief_in_bus = 1;")
        elif(ls[0] == 97):
            print("geen post")
            mycursor.execute("UPDATE letters SET Brief_in_bus = 0;")

    time.sleep(1)
    mydb.commit()

mydb.close()