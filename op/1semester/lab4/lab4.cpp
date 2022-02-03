#include<iostream>
#include<math.h>
using namespace std; 



int main(){
    float x, currentMember,S=0;
    int n;
    cout << "Enter value of the \'x\': ";
    cin >> x;
    cout << "Enter value of the \'n\': ";
    cin >> n;
    for(int i=1;i<n+1; i++) {
        currentMember = pow(-1,i+1) * (pow(x,i)/i);
        S+=currentMember;
    }
    cout << "Sum: "<< S;
    return 0;
    }