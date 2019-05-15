
import subprocess as spc

alias getsi="sudo iwlist wlan0 scan | grep -e ESSID -e Quality"
res=spc.check_output(getsi)
lis=res.split()
ss=lis.index("DUCRB-LAB")
ss=ss-2
ra=lis[ss].split("=")
RSSI=abs(int(ra[1]))
print RSSI