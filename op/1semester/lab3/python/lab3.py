import math

lnPrevious = 0 
ln = 0
e = 0.000001
n=1
x=float(input("Enter value of the \'x\': "))

while True :
    lnPrevious = ln
    ln += (-1)**(n-1) * (((x)**n)/n)
    n+=1
    if abs(ln-lnPrevious) < e:
        break
print(ln)