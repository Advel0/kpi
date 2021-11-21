// Умова задачі має помилку: розклад за формулой Тейлора записаний неправильно 
// (не вистачає множника (-1)^(n-1), без якого значення натурального логарифма обчислюється неправильно ), тому я вирішив додати цей множник. 

#include <iostream>
#include <cmath>        

using namespace std;

double Ln(double x, double e);
void output(double x, double y);

int main() {
    double e, x = 0, step = 0.5, max=3;
    cout << "Please, enter the value of \"e\": ";
    cin >> e;

    while (x <= max) {
        output(x,e);
        x += step;
    }

    return 0;
}

double Ln(double x, double e) {

    double r=0;
    int n = 1;
    while (abs(pow((x - 1), n) / n) > e) {

        r += pow(-1,n-1) * pow((x - 1), n) / n;
        n++;

    }
    return r;
}
void output(double x, double e) {
    cout << endl   << "------------------" << endl
         << "x = " << x                    << endl
         << "y = " ;
    if (x < 2 && x>0) {
        cout << (Ln(x, e) + Ln(x / 2, e));

    }
    else if (x>2){
        cout << Ln(x / 2 - 1, e);
    } else {
        cout << "doesn't exist";
    }
}