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

    f = open("state.txt", "r")
    current_state = f.read()
    f.close()

    if len(ls) == 1:
    
        if(ls[0] == 98):
            print("post")
            mycursor.execute("UPDATE letters SET Brief_in_bus = 'Vol';")
            f = open("state.txt", "w")
            f.write("1")
            f.close()
            f = open("state.txt", "r")
            new_state = f.read()
            f.close()
        elif(ls[0] == 97):
            print("geen post")
            mycursor.execute("UPDATE letters SET Brief_in_bus = 'Leeg';")
            f = open("state.txt", "w")
            f.write("0")
            f.close()
            f = open("state.txt", "r")
            new_state = f.read()
            f.close()
        if new_state != current_state:
            if new_state == "1":
                mycursor.execute("INSERT INTO history VALUES (id, 'brief', CURRENT_TIMESTAMP)")

    mydb.commit()

mydb.close()