#include<iostream>
#include<math.h>
using namespace std; 



int main(){
    float x, lnPrevious=0,ln=0, e = 0.000001;
    int n=1;
    cout << "Enter value of the \'x\': ";
    cin >> x;
    ln = lnPrevious +  pow(-1,(n-1)) * float(pow(x,n))/n;
    cout << ln<<endl;
    n++;
    while ( abs(ln - lnPrevious) > e) {
        lnPrevious = ln;
        ln +=  pow(-1,(n-1)) * float(pow(x,n))/n;
        n++;
    }  
    cout << ln; 
    return 0;
    }