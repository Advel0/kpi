#include <iostream>
#include <math.h>
using namespace std; 

int main() {
    float X,Y;
    const float PI = 3.14;
    cout << "Enter value of the X variable: ";
    cin >> X;
    if (X<PI && X>0) {
        Y = cos(X);
    } else {
        if (X>=0) {
            Y = -1;
        } else {
            Y = 1;
        }
    }
    cout << "Y: " << Y;
    return 0;
}                                  