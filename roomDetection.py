

#https://qiita.com/RS2324/items/0deae3931272936bca5e
import subprocess as spc



class WifiRouter:
    def __init__(self, address, quality, ssid):
        self.address = address 
        self.quality = quality
        self.ssid = ssid


res=spc.check_output("getsi")
lis=res.splitlines()
targetSSIDIndexList = [i for i,s in enumerate(lis) if "DUCRB-LAB" in s]

for t in targetSSIDIndexList:
    print(t,"  ", lis[t])

routerList = [WifiRouter(lis[i-2],lis[i-1],lis[i]) for i in targetSSIDIndexList]

for tmp in routerList:
    print tmp.address, "  ",tmp.ssid, "  ", tmp.quality