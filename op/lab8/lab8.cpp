#include <iostream>
#include <iomanip>
#include <cmath>
#include <float.h>

// Function for displaying data
void displayArr(double** ,int);

// Functions for working with arrays
void fillArr(double** ,int);
double calcSquareDist(double*, double*);
int* findMinDistPoints(double**, int);

using namespace std;
int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    // Initializing 2 dimensional array to represent points, and filling it with random values (from -100 to 100)
    double** arr = new double*[n];
    for ( int i = 0; i < n; i++){
        arr[i] = new double[2];
    }
    fillArr(arr,n);

    //Searching for two points with the least possible distance between them
    int* minDistP = findMinDistPoints(arr,n);

    //Displaying data
    displayArr(arr,n);
    printf("\nMin dist is between point number \"%i\" and point number \"%i\"",minDistP[0],minDistP[1] );


    //Clearing memory
    for ( int i = 0; i < n; i++){
        delete[] arr[i];
    }
    delete[] arr;
    delete[] minDistP;
    return 0;
}

void displayArr(double** arr, int n) {
    cout << "X:  Y:" ;
    for (int i = 0; i < n; i++ ){
        cout << endl <<setw(3)<< arr[i][0] << "|";
        cout << setw(3) << arr[i][1];
    }
}


void fillArr(double** arr,int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++ ){
        arr[i][0]=rand()%201 - 100;
        arr[i][1]=rand()%201 - 100;
    }
}

double calcSquareDist(double* p1, double* p2){
    double sqDist;
    sqDist = pow ( (p2[0] - p1[0]), 2) + pow ( (p2[1] - p1[1]), 2);
    return sqDist;
}

int* findMinDistPoints(double** arr, int n) { 
    
    int* minDistPoints = new int[2];  
    double minDist=DBL_MAX, currentDist=0;

    int j ;

    // Searching through all the point to find two with the least distance between them
    for (int i=0; i<n; i++) { 
        j=i+1;
        while(j<n) {
                currentDist = calcSquareDist(arr[i],arr[j]);
                if(minDist > currentDist) {
                    minDist = currentDist;
                    minDistPoints[0]=i;
                    minDistPoints[1]=j;
                }
            j++;
        };
    } 
    return minDistPoints;
}