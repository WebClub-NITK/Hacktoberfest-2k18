# -*- coding: utf-8 -*-
"""
Created on Mon Oct  8 15:36:27 2018

@author: Rajat
"""

import socket
import random

client_data = random.randint(0,500)

# create an ipv4 (AF_INET) socket object using the tcp protocol (SOCK_STREAM)
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# connect the client
# client.connect((target, port))
client.connect(('127.0.0.1', 9999))

# send some data (in this case a HTTP GET request)
client.send(str(client_data))

# receive the response data (4096 is recommended buffer size)
response = client.recv(4096)

print (response)