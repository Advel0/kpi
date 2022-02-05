#include <iostream>
#include <string>
#include <fstream>


using namespace std;

void manage_input( string ,string ); // fstream*
void export_data ( string ); // fstream* 

int main()
{
	
	string path;
	string path_export;
	string state;
//	fstream file;
	
	
	cout << "Enter file path/name: ";
	cin >> path;
	cout << "You want ro rewrite(W) or edit the file(E): ";
	cin >> state;
	
	manage_input( path, state ); // "&file"
	
	cout << "Want to export, process and place the contents of current file to another ?(N/<specify location>): ";

	cin >> path_export;

	if ( path_export != "N" )
	{
		export_data( path_export );
	}	

	return 0;
}

void export_data( string path )
{
	fstream file;
	file.open( path );
}

void manage_input( string path, string state ) // fstream* file
{	
	fstream file;
	string input;
	
	if ( state == "W" )
       	{

		(file).open(path, ios::out | ios::trunc );
		if ( !file.is_open() )
	       	{
			cout << "Failed to open a file for writing";
		}
		else
	       	{
			cout << "Succesfully opened a file for writing: \n";
			cout << "Enter \":q\" to stop writing a file: \n";
		
			cout << " -------- File --------- " << endl ;
			cin.ignore();
		
			while ( true )
			{
				getline(cin, input);
				if ( input == ":q" )
				{
					break;
				}
				file << input << endl;
			}
	
			cout << " ----- End of File ----- " << endl;
		}
	}
	else if ( state == "E" )
       	{
		string file_content;
		
		file.open(path, ios::app | ios::in );
	
		if ( !file.is_open() )
	       	{
			cout << "Failed to open a file for editing";
		}
		else
	       	{
			cout << "Succesfully opened a file for editing \n";	
			cout << "Enter \":q\" to stop editing a file: \n";
			
			cout << " -------- File --------- " << endl ;
			
			while ( !file.eof() )
			{
				getline(file, file_content );
				cout  << file_content << endl;
			}

			cout << "   --- Your edits ---- " << endl ;
			
			file.close();
			file.open(path, ios::app);	
		
			cin.ignore();
			while ( true )
			{
				getline(cin, input);
				if ( input == ":q" )
				{
					break;
				}
				file << input << endl;
			}

			cout << " ----- End of File ----- " << endl;
		}
	}
	else
	{
		cout << "ERROR. No such file managing operation";
	}

	file.close();
}
