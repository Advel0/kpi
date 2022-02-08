#include <iostream>
#include "module.h"
#include <fstream>

using namespace std;

int main(){

    string file_name,content ,mode;

    cout << "Enter file name (.txt only) : " ;
    cin >> file_name;

    content = get_input();
    cout << endl << "Entered text : " << endl;
    cout << content;

    cout << "Wrtire or extend file? W/E : ";
    cin >> mode;

    save_file(file_name,content, mode);

    export_data(file_name);

    cout << endl << "Content of file " + file_name.substr(0, file_name.length()-4) + "_exp.txt (text changed as asked in the task) : "  << endl;
    cout << get_file_cont(file_name.substr(0, file_name.length()-4) + "_exp.txt" );
    return 0;
}