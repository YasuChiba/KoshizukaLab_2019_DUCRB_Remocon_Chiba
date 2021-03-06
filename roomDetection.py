

#https://qiita.com/RS2324/items/0deae3931272936bca5e
import subprocess as spc
import time



class WifiRouter:
    def __init__(self, address, quality, ssid):
        self.address = address 
        self.quality = int(quality.split("=")[1].split("/")[0].strip())
        self.signalStrength = int(quality.split("  ")[1].split("=")[1].split(" ")[0].strip())
        self.ssid = ssid
    
def getRouterList():
    res=spc.check_output("getsi")
    lis=res.splitlines()
    targetSSIDIndexList = [i for i,s in enumerate(lis) if "DUCRB-PS" in s]
    routerList = [WifiRouter(lis[i-2].split()[4],lis[i-1].strip(),lis[i].strip()) for i in targetSSIDIndexList]
    return routerList



while(True):
    routerList = getRouterList()
    for tmp in routerList:
        print str(tmp.quality) + "  " + tmp.address
    time.sleep(5)


'''

routerDict = {}
counter = 0

while(True):
    routerList = getRouterList()
    for tmp in routerList:
        if tmp.address in routerDict:
            routerDict[tmp.address][0].append(tmp)
        else:
            routerDict[tmp.address] = [[tmp],[]]

    
    #print("")

    counter = counter + 1
    if counter == 4:
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
    if counter == 4:
        break


for address in routerDict:
    if len(routerDict[address]) == 2 and len(routerDict[address][0]) > 0 and len(routerDict[address][1]) > 0:
        mean1Quality = sum([t.quality for t in routerDict[address][0]])/len(routerDict[address][0])
        mean2Quality = sum([t.quality for t in routerDict[address][1]])/len(routerDict[address][1])

        mean1signalStrength = sum([t.signalStrength for t in routerDict[address][0]])/len(routerDict[address][0])
        mean2signalStrength= sum([t.signalStrength for t in routerDict[address][1]])/len(routerDict[address][1])

        qualityDif = mean1Quality - mean2Quality
        signalStrengthDif = mean1signalStrength - mean2signalStrength
        #print(mean1Quality,"   ", mean2Quality, "  ", mean1signalStrength, "  ",mean2signalStrength)
        print(str(qualityDif) +  "   "+ str(signalStrengthDif)+"  "+ address + "  " + routerDict[address][0][0].ssid)

'''