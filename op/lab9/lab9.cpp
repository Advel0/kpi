#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

#define SIZE 100

//Removes all the leters that are repeating in a line
int removeRepeat(char[]);

// Deletes all the elements that are present in the second array from the first array 
int delElements(char[], char[]);

// Checks if a symbol is present in a line
bool contains(char[], char);


int main() {

    char line[SIZE];
    int deletedAmount;
    cout << "Enter your line: ";

    cin.get(line, SIZE);
    deletedAmount = removeRepeat(line);

    cout << "Line witout repetitions: " <<line<<endl;
    cout << "Number of deleted letters: "<< deletedAmount;
    return 0;
}


int removeRepeat(char line[]) {
    int counter = 0;
    char checked[SIZE];
    char toDel[SIZE];
    int i = 0;

    while (line[i] != '\0'){
        if (contains(checked, line[i]) && !contains(toDel,line[i]) ) {
            toDel[counter] = line[i];
            counter++;
        }
        checked[i] = line[i];
        i++;
    }
    toDel[i+1] = '\0';

    return delElements(line, toDel);
}

int delElements(char initialLine[], char toDelElements[]) {
    int counter=0;
    int i = 0 ;

    while (toDelElements[i] != '\0'){
        int j = 0;
        while (initialLine[j] != '\0') {
            if (initialLine[j] == toDelElements[i]) {
                initialLine[j] = 32;
                counter++;
            }
            j++;
        }
        i++;
    }
}

bool contains(char line[], char symbol) {
    bool status = false;
    int i = 0;

    while (line[i] != '\0' ) {
        if (line[i] == symbol) {
            status = true;
        }
        i++;
    }
    return status;
}