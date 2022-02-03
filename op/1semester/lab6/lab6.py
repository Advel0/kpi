# Умова задачі має помилку: розклад за формулой Тейлора записаний неправильно 
# (не вистачає множника (-1)^(n-1), без якого значення натурального логарифма обчислюється неправильно ), тому я вирішив додати цей множник. 

def main():
    x = 0
    step = 0.5
    maxValue = 3
    e = float(input("Enter the value of \"e\": "))
    while x <= maxValue:
        output(x,e)
        x += step
    
def Ln(x,e):
    r = 0
    n = 1
    while ( abs((-1)**(n-1) * (x - 1)**n / n ) > e ):
        r += (-1)**(n-1) * (x - 1)**n / n 
        n+=1
    return r 

def output(x,e):
    print("\n------------------"+
        "\n x = " + str(x) +
        "\n y = ", 
        end = ""
        )
    if x < 2 and x>0:
        print(Ln(x, e) + Ln(x / 2, e))
    elif x>2:
        print(Ln(x / 2 - 1, e))
    else:
        print("doesn't exist")

main()