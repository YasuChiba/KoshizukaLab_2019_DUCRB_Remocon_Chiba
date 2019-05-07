import sys
import requests
import json
import time
import RPi.GPIO as GPIO


def lightControll(isOn: bool, roomNumber: str):
    url = “http://172.26.16.8/api/ducrbcontrol/light/”
    headers = {“Content-Type”: “application/json”}
    putdata = {
        ‘ucode’: "a"+roomNumber,
        instance’: "on" if isOn else "off"
    }
    req = requests.put(url, data=json.dumps(putdata), headers=headers, auth=(‘koshizukaLab’, ‘8TxgS73KmG’))
    print(req.status_code)
    

print("python called")
args = sys.argv

#args[1] == 0 => light
#args[1] == 1 => air conditioner?

#args[2] == 0 => turn off
#args[2] == 1 => turn on

#args[3] == 305  (room number)

if args[1] == '0':
    lightControll(args[2] == '0', args[3])







