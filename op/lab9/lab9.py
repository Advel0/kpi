SIZE = 100

def main():
    line = list(input("Please, enter you line: "))

    deletedAmount = removeRepeat(line)

    print("Line witout repetitions: ", "".join(line))
    print("Number of deleted letters: ", deletedAmount)

# Removes all the leters that are repeating in a line
def removeRepeat(line):
    checked=[]
    toDel=[]

    for i in range(len(line)):
        if line[i] in checked and not line[i] in toDel:
            toDel.append(line[i])
        checked.append(line[i])

    return delElements(line,toDel)

# Deletes all the elements that are present in the second array from the first array 
def delElements(initialLine, toDelElements):
    counter = 0
    
    for i in range(len(toDelElements)):
        for j in range(len(initialLine)) :
            if initialLine[j] == toDelElements[i]:
                initialLine[j] = ' '
                counter += 1

    return counter

main()