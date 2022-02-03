import math 

X = float(input( "Enter value of the X variable: "))

if X>0 and X<math.pi:
    Y = math.cos(X)
else:
    if X>0:
        Y = -1
    else:
        Y = 1
    
print("Y: ",Y)