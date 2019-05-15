
import subprocess as spc
res=spc.check_output("getsi")
print res
lis=res.split()
ss=lis.index("DUCRB-LAB")
ss=ss-2
ra=lis[ss].split("=")
RSSI=abs(int(ra[1]))
print RSSI