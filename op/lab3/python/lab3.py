
#include <iostream>
#include <math.h>

"""using namespace std;

int main(){
    float x;
    long y = 0;
    int n=1;
    cout << "Enter value of the \"x\" variable: ";
    cin >> x;
    while (int(y % 10 == 0 ) ){
        e=0;
        y+= pow(1,n-1)*(pow(x,n)/n) * pow(10,6);
        n++;    
    }

    cout << y/long(pow(10,6)) << "." << abs(y% long(pow(10,6))) << endl;

    return 0;
}"""

import math

y = 0
n = 1
x = float(input("Enter value of the \"x\" variable: "))
while y % 10 == 0 :
    y+= int(((-1)**(n-1))*((x**n)/n)*(10**6))
    n+=1

print(str(y//10**6) + "." + str(y%10**6))