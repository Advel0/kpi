import math

triangleSide1 = float(input('Enter first side: '))
triangleSide2 = float(input('Enter second side: '))
triangleAngle = float(input('Enter angle: ')) /180 * math.pi

print('Answer: ',0.5 * triangleSide1 * triangleSide2 * math.sin(triangleAngle)) 