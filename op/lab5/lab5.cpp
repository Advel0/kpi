#include <iostream>

using namespace std;


int main() {
    int p, q;
    int a, biggestCommonDivisor, b,pDivisor;
    cout << "Enter value of the p variable: ";
    cin >> p;
    cout << "Enter value of the q variable: ";
    cin >> q;
    cout << "Divisors of p, which are coprime with q:"<< endl;
    for (int i = 1; i < p+1; i++) {
        if (p % i == 0) {
            pDivisor = i ;
            a = pDivisor;
            b = q;
            // Euclid algorithm
            while (a != 0 && b != 0) {
                if (a > b) {
                    a %= b;
                }
                else {
                    b %= a;
                }
            }
            biggestCommonDivisor = a+b;
            if ( biggestCommonDivisor == 1){
                cout <<pDivisor << endl;
                }
             
        }
    }
    return 0;
}