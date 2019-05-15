

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


routerList = [WifiRouter(lis[i-2].split()[4],lis[i-1].strip(),lis[i].strip()) for i in targetSSIDIndexList]

for tmp in routerList:
    #print tmp.ssid, tmp.quality,"    ",  tmp.address
    quality = tmp.quality.split("=")[1].split("/")[0]
    signalLebel = tmp.quality.split(" ")[1].split("=")[1].split(" ")[0]

    if "C0:25:5C:96:AD:D2" in tmp.address:
        print "305:", quality," ", signalLebel
    elif "64:E9:50:71:B6:52" in tmp.address:
        print "306:", quality," ", signalLebel
    elif "34:DB:FD:E1:D1:B2 " in tmp.address:
        print "307:", quality," ", signalLebel

    

