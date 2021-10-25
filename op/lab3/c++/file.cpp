#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int i = 1;
    int *iP = &i;
    *iP+=1;
    srand(time(NULL));
    cout << rand()%10; 
    
	return 0;
}