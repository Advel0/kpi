#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main() {
	string path = "file.txt";
	string temp_data = "";

	
	ofstream fout;
	fout.open(path, ofstream::app);
	

	if (!fout.is_open())
	{
		cout << "Failed to open/write the file";
	}
	else
       	{	
		cout << "to stop adding new data enter \".quit\"" << endl;
		while (temp_data != ".quit\n")
	       	{
			fout << temp_data;
			cout << "enter a new line: ";
			cin >> temp_data;
			temp_data += '\n';
		}
	}

	fout.close();

	return 0;

}
