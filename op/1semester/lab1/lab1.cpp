#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>


int main()
{
    float triangleSide1, triangleSide2, triangleAngle, temp = 0;
    std::cout << "Enter first side: ";
    std::cin >> triangleSide1;
    std::cout << "Enter second side: ";
    std::cin >> triangleSide2;
    std::cout << "Enter angle: ";
    std::cin >> temp;
    triangleAngle = (temp / 180) * M_PI;

    std::cout << "Answer: " << 0.5 * triangleSide1 * triangleSide2 * sin(triangleAngle) << '\n';
}

