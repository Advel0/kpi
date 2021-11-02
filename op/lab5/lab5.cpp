#include <iostream>

using namespace std;


int main() {
    int p, q;
    int a, biggestCommonDivisor, b,pDivisor;
    cout << "Enter value of the p variable: ";
    cin >> p;
    cout << "Enter value of the q variable: ";
    cin >> q;
    
    for (int i = 1; i < p+1; i++) {
  //      cout << "-------------" << endl << "iteration: " << i<<endl;
  //      cout << "(p % i == 0) = " << (p % i == 0) << endl; 
        if (p % i == 0) {
            pDivisor = i ;
     //       cout << "pDivisor = " << pDivisor<<endl;
            a = pDivisor;
            b = q;
  //          cout <<"a = " <<a<<endl<<"b = "<< b<<endl;
            // Euclid algorithm
      //      cout << "Euclid algorithm"<<endl;
            while (a != 0 && b != 0) {
                cout << "(a != 0 && b != 0) = " <<(a !=0 && b!=0) << endl;
        //        cout << "---" <<endl;
                if (a > b) {
                    a %= b;
        //            cout << "a<b =  "<< (a<b) << endl;
                }
                else {
                    b %= a;
       //             cout << "a<b = "<< (a<b) << endl;
                }
         //       cout <<"a = " << a << endl <<"b = "<< b <<endl;
            }
            biggestCommonDivisor = a+b;
     //       cout <<"biggestCommonDivisor = "<< biggestCommonDivisor<<endl;
            if ( biggestCommonDivisor == 1){
     //           cout << "( biggestCommonDivisor == 1) = " << ( biggestCommonDivisor == 1)<< endl;
                cout <<"виведення "<<pDivisor << endl;
                }
             
        }
    }
    return 0;
}
