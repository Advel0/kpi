#include <iostream>
#include "module.h"

using namespace std;


int main()
{
    
    string fileName, content;

    fileName = getFileName();
    content = getInput();
    writingMode wm = getWritingMode();

    writeToFile(fileName, content, wm);
    exportData(fileName);
    showFileContent(fileName, "Initial Text Data: ");
    showFileContent(fileName.substr(0, fileName.length() - 4) + "_exp.txt", "Processed Text Data:");
   

    return 0;
}