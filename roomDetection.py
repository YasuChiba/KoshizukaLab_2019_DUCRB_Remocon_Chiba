

#https://qiita.com/RS2324/items/0deae3931272936bca5e
import subprocess as spc



class WifiRouter:
    def __init__(self, address, quality, ssid):
        self.address = address 
        self.quality = quality
        self.ssid = ssid


res=spc.check_output("getsi")
print res
lis=res.splitlines()
targetSSIDList = [i for i,s in enumerate(lis) if "DUCRB-LAB" in s]

routerList = []

routerList = [WifiRouter(lis[i-2],lis[i-1],lis[i]) for i in targetSSIDList]

for tmp in routerList:
    print tmp.ssid