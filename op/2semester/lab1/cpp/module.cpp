#include <iostream>
#include <fstream>
#include <string>
#include "module.h"

using namespace std;

string getFileName() {
    string _fileName;

    cout << "Enter file name: ";
    cin >> _fileName;

    return _fileName;
}

string getInput() {
    string _content, line;

    cout << "Write your text ( to end enter Ctrl + X ): " << endl;
    cin.ignore();
    getline(cin, line);

    while (int(line[0]) != 24) {  //
        _content += line + '\n';
        getline(cin, line);
    }

    return _content;
}

writingMode getWritingMode() {
    writingMode _wm = writeFile;
    string _input;

    cout << "Please chose a writing mode ( W - rewrite/write | E - extend) : ";
    cin >> _input;

    if (_input == "W") {

    }
    else if (_input == "E") {
        _wm = extendFile;
    }
    else {
        cout << "Incorrent mode, writing mode set to default (Write file)";
    }

    return _wm;
};

void writeToFile(string _fileName, string _content, writingMode _wm) {
    ofstream file(_fileName, _wm == writingMode::writeFile ? ios::trunc | ios::out : ios::app );
    file << _content;

    file.close();

}

void exportData(string _fileName) {
    string line;
    ifstream file(_fileName, ios::in);
    ofstream fileExp(_fileName.substr(0, _fileName.length() - 4) + "_exp.txt", ios::trunc | ios::out);

    while (!file.eof()) {
        getline(file, line);

        if (line == "") continue;

        int counter = 0;

        while (line[counter] != ' ' && counter < line.length())
        {
            counter++;
        }

        line += line[counter - 1];

        fileExp << line << endl;
    };

    file.close();
    fileExp.close();
}


void showFileContent(string _fileName, string _message) {
    string line;
    ifstream file(_fileName, ios::in);
    cout << endl << _message << endl;

    while (!file.eof()) {
        getline(file, line);
        cout << line <<endl; 
    }
    file.close();

}