#include <iostream>
#include <iomanip>  
#include <cmath>
#define RANGE 40
#define SPACE 7
using namespace std;

//display finctions
int input(); 
void showArr(int* arr,int size, string message);

//functions connected with processing arrays
int* generateArrayA(int size);
int* generateArrayB(int* arr,int size, int aMax);
void alterArrayWithD(int* arr, int size, int d);

//functions that work with elements of an array
int findMax(int* arr,int size);
int calulateD(int* arrA, int* arrB, int size);


int main() {
    int size;
    size = input();

    int *arrA = generateArrayA(size);
    showArr(arrA,size,"The initial \"A\" array: ");

    int aMax = findMax(arrA,size);
    
    int *arrB = generateArrayB(arrA, size,aMax);
    showArr(arrB,size, "The \"B\" array: ");

    int d = calulateD(arrA, arrB, size);
    cout << "The value of \"d\": " << d << "\n\n";
    alterArrayWithD(arrA, size, d);

    showArr(arrA,size,
    "The altered(each element that is divisible by 7 is increased by \"d\") \"A\" array: ");
}

int input() {
    int size;
    cout << "Please, enter size of the array: ";
    cin >> size;
    cout << endl;
    return size;
}
//shows elements of an array with formatting, and a message describing type of the array
void showArr(int* arr,int size, string message) {
    cout << message << endl;
    for(int i=0; i < size; i++){
        cout << setw(SPACE) << arr[i];
    }
    cout << "\n\n";
}


int* generateArrayA(int size) {
    srand(time(NULL));
    int *arr = new int[size];
    for (int i=0;i<size;i++) {
        arr[i] = rand()%(2*RANGE) - RANGE; 
    }
    return arr;
}
int* generateArrayB(int* arr,int size, int aMax) {
    int* arrB = new int[size];
    for (int i=0;i<size;i++) {
        arrB[i] = aMax - arr[i];
    }
    return arrB;
}
// increases by d each element that is divisible by 7 "
void alterArrayWithD(int* arr, int size, int d) {
    for(int i=1; i < size; i++){
        if (arr[i] % 7 == 0 )
            arr[i]+=d; 
    }
}


//find max value of an array
int findMax(int* arr,int size){
    int Max=arr[0];
    for(int i=1; i < size; i++){
        if (arr[i] > Max)
            Max = arr[i]; 
    }
    return Max;
}
int calulateD(int* arrA, int* arrB, int size) {
    int d=0;
    for(int i=1; i < size; i++){
          d+=  pow( abs(arrA[i] - arrB[i]) , 2 );
    }
    return d;
}

