

#https://qiita.com/RS2324/items/0deae3931272936bca5e
import subprocess as spc
import time



class WifiRouter:
    def __init__(self, address, quality, ssid):
        self.address = address 
        self.quality = quality
        self.ssid = ssid


def getRouterList():
    res=spc.check_output("getsi")
    lis=res.splitlines()
    targetSSIDIndexList = [i for i,s in enumerate(lis) if "ESSID" in s]
    routerList = [WifiRouter(lis[i-2].split()[4],lis[i-1].strip(),lis[i].strip()) for i in targetSSIDIndexList]
    return routerList


routerDict = {}
counter = 0

while(True):
    routerList = getRouterList()
    for tmp in routerList:
        if tmp.address in routerDict:
            routerDict[tmp.address][0].append(tmp)
        else:
            routerDict[tmp.address] = [[tmp],[]]

        quality = tmp.quality.split("=")[1].split("/")[0]
        signalLebel = tmp.quality.split("  ")[1].split("=")[1].split(" ")[0]
        '''
        if "C0:25:5C:96:AD:D2" in tmp.address:
            print "305:", quality," ", signalLebel
        elif "64:E9:50:71:B6:52" in tmp.address:
            print "306:", quality," ", signalLebel
        elif "34:DB:FD:E1:D1:B2 " in tmp.address:
            print "307:", quality," ", signalLebel
            '''
    #print("")

    counter = counter + 1
    if counter == 2:
        break

print("----------")
t = raw_input()
print("----------")


counter = 0
while(True):
    routerList = getRouterList()
    for tmp in routerList:
        if tmp.address in routerDict:
            routerDict[tmp.address][1].append(tmp)
        else:
            routerDict[tmp.address] = [[],[tmp]]

    counter = counter + 1
    if counter == 2:
        break


for address in routerDict:
    if len(routerDict[address]) == 2:
        mean1 = sum(routerDict[address][0])/len(routerDict[address][0])
        mean2 = sum(routerDict[address][0])/len(routerDict[address][0])
        print(mean1, "  ", mean2,"  ", address, "  ", routerDict[address][0][0].ssid)

