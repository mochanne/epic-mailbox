# python 3.6

import random
import time
import datetime

from paho.mqtt import client as mqtt_client

max_tries = 10
broker = 'broker.emqx.io'
port = 1883
topic = "brievenbus/post"
bericht = "Er is post"
# generate client ID with pub prefix randomly
client_id = f'python-mqtt-{random.randint(0, 1000)}'
username = 'emqx'
password = 'public'

def logme(*args):
    with open("../python/mqtt_log.txt", "a") as f:
        f.write(f'[{datetime.datetime.now()}]  '+''.join(args)+"\n")

def connect_mqtt():
    def on_connect(client, userdata, flags, rc):
        print("Er is post")
        logme("Verbonden!")
        
    logme(f"Verbinden met {broker}:{port}")
    logme("met client-id ",client_id)
    logme(f"en user+pw '{username}' '{password}'")
    client = mqtt_client.Client(client_id)
    client.username_pw_set(username, password)
    client.on_connect = on_connect
    client.connect(broker, port)
    return client



def run():
    logme("")
    logme("opgestart")  
    client = connect_mqtt()
    client.loop_start()
    for i in range(max_tries):
        logme("publishing naar ",topic,": '",bericht,"'")
        result = client.publish(topic, bericht)
        if result[0] == 0:
            logme("Resultaat OK")
            break
        else:
            logme("Resultaat BAD: ",result[0])
            time.sleep(0.5)
            logme("We proberen het opnieuw")


if __name__ == '__main__':
    run()