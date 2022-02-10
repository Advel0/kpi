#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum writingMode;

string getFileName();

string getInput();

writingMode getWritingMode();

void writeToFile(string _fileName, string _content, writingMode _wm);

void exportData(string _fileName);

void showFileContent(string _fileName, string _message);

enum writingMode {
    writeFile,
    extendFile
};
