#include <fstream>
#include <iostream>
#include <vector>
#include "Structs.h"
#include "Application.h"
#include "StructHandlers.h"


using namespace std;

int main()
{
	string add, fileName;
	Application app;
	EmployeeHandler eh;
	DateHandler dh;
	vector <Employee> emps;

	fileName = app.start();

	if (app.readFile(fileName, emps) != 0) {
		string temp;
		cout << "File does not exist! Want to create ?(Y/N): ";
		cin >> temp;

		if (temp == "Y")
		{
			emps = app.getInput();
			app.writeFile(fileName, emps);
			app.showEmployees(emps);
		}

		return 0;
	}

	cout << "All employees :" << endl;
	app.showEmployees(emps);
	cout << endl;

	cout << "Add employees?(Y/N) : ";
	cin >> add;
	if (add == "Y")
	{
		cin.ignore();
		vector<Employee> newEmps = app.getInput();
		for (auto emp : newEmps)
		{
			emps.push_back(emp);
		}
		app.writeFile(fileName, emps);

		cout << "All (renewed) employees :" << endl;
		app.showEmployees(emps);
		cout << endl;
	}

	cout << "-----" << endl;
	cout << "Enter Current Date :" << endl;
	Date today = dh.getDate(); 
	cout << "-----" << endl;
	cout << endl;
	

	cout << "Employees older than 40 :" << endl;
	app.showEmployees(app.removeEmployees(emps,today, 40, removeMode::age));
	cout << "-----" << endl;

	cout << "Employees who work more than 20 years :" << endl;
	app.showEmployees(app.removeEmployees(emps, today, 20, removeMode::experience));
	cout << "-----" << endl;

	cout << "Employees who work more than a year :" << endl;
	app.showEmployees(app.removeEmployees(emps, today, 1, removeMode::experience));

	app.writeFile(fileName.substr(0, fileName.length() - 4) + "_filtered.dat", emps);
}
	
	
