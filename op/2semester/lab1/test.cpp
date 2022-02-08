#include <iostream>
#include <fstream>

using namespace std;


int main() {

	string path = "file.txt";

	ifstream fin;
	fin.open(path);
	
	if ( !fin.is_open() ) 
	{
		cout << "Failed to open the file";
	}
	else 
	{
		cout << "File opened succesfully" << endl;
		char ch;

		while(fin.get.oef()) 
		{
			cout << ch;
		}


	}

	fin.close();	

	return 0;
}
