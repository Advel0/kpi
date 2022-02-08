#include <iostream>
#include <fstream>


using namespace std;

void export_data(string file_name) {
    char ch;
    string line;
    fstream file(file_name, ios::in);
    fstream file_exp( (file_name.substr(0, file_name.length()-4) + "_exp.txt"),ios::out | ios::trunc);

    while ( !file.eof() )
    {
        getline( file, line );

        if( line == "" ) continue;

        int counter = 0;

        while( line[counter] != ' ' && counter < line.length() )
        {
            counter++;
        }

        ch = line[counter-1];
        line += ch;

        file_exp << line << endl;

    }

    file.close();
    file_exp.close();
}



void export_data( string path, string path_exp )
{
	fstream file, file_exp;
	string line;
	char ch;
	
	file.open( path, ios::in );
	file_exp.open( path_exp, ios::out | ios::trunc );


	while ( !file.eof() )
	{
		getline( file, line );
		
		if( line == "" ) continue;
		
		int counter = 0;

		while( line[counter] != ' ' && counter < line.length() ) 
		{
			counter++;
		}
		
		ch = line[counter-1];
		line += ch;

		file_exp << line << endl;

	}

	file.close();
	file_exp.close();
}

void save_file(string file_name, string content, string mode){
    fstream file(file_name, mode == "W" ? ios::out | ios::trunc : ios::app);
    file << content;
    file.close();
}

string get_input(){
    string inp, line;
    cout << "Enter you text (:q to end):" << endl;
    cin.ignore();

    getline(cin, line);
    while ( line != ":q" )
    {
        inp += line + '\n';
        getline(cin, line);
    }

    return inp;
}

string get_file_cont(string file_name){
    fstream file(file_name, ios::in);
    string cont, line;

    while ( !file.eof() )
    {
        getline(file, line );
        cont += line + '\n';
    }
    return cont;
}