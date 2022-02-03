q=a=biggestCommonDivisor=b=pDivisor=0
p = int(input("Enter value of the p variable: "))
q = int(input("Enter value of the q variable: "))
for i in range(1,p+1):
    if p%i==0:
        pDivisor = i
        a = pDivisor
        b = q
        while (a != 0 and b != 0):
            if a>b:
                a%=b 
            else:
                b%=a
        biggestCommonDivisor = a+b
        if biggestCommonDivisor==1:
            print(pDivisor)
