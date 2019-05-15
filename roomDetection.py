

#https://qiita.com/RS2324/items/0deae3931272936bca5e
import subprocess as spc



class WifiRouter:
    def __init__(self, address, quality, ssid):
        self.address = address 
        self.quality = quality
        self.ssid = ssid


res=spc.check_output("getsi")
lis=res.splitlines()
targetSSIDIndexList = [i for i,s in enumerate(lis) if "ESSID" in s]


routerList = [WifiRouter(lis[i-2].split()[4],lis[i-1].strip(),lis[i].strip()) for i in targetSSIDIndexList]

for tmp in routerList:
    if "C0:25:5C:96:AD:D2" in tmp.address:
        print "305", tmp.quality
    elif "64:E9:50:71:B6:52" in tmp.address:
        print "306", tmp.quality
    elif "34:DB:FD:E1:D1:B2 " in tmp.address:
        print "307", tmp.quality   

