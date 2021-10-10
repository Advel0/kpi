#include<iostream>
#include<math.h>
using namespace std; 



int main(){
    float x, Ln=0, e = 0.000001;
    int n=1;
    cout << "Enter valou of the \'x\': ";
    cin >> x;

    while ( abs(pow(-1,(n-1)) * float(pow(x,n))/n) > e) {
        Ln += pow(-1,(n-1)) * float(pow(x,n))/n;
        cout << Ln << endl;
        n++;
    }
    cout << Ln;
    return 0;
}
