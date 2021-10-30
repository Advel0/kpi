import math

lnPrevious = 0 
ln = 0
e = 0.000001
n=1
x=float(input("Enter value of the \'x\': "))
lnPrevious=(-1)**(n-1) * ((x**n)/n)
n+=1
ln = lnPrevious +  (-1)**(n-1) * (((x)**n)/n)
n+=1
while abs(ln-lnPrevious) > e :
    lnPrevious = ln
    ln += (-1)**(n-1) * (((x)**n)/n)
    n+=1
print(ln)