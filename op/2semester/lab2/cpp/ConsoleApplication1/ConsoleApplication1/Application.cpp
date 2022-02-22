#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Structs.h"
#include "StructHandlers.h"
#include "Application.h"


using namespace std;

	string Application::start()
	{
		string fileName;

		cout << "Enter the name of existing employees list : ";
		cin >> fileName;
		return fileName;
	}

	vector<Employee> Application::getInput()
	{
		vector<Employee> employees;
		string state = "Y";
		cout << "Add new employees: " << endl;
		DateHandler dh;


		while (state == "Y")
		{
			Employee emp;
			cout << "----------" << endl;
			cout << "Enter fulll name: ";
			cin.get(emp.fullName, 40);

			cout << "==========" << endl;
			cout << "Enter birth date: " << endl;
			Date birthDate = dh.getDate();

			cout << "==========" << endl;
			cout << "Enter employment date: " << endl;
			Date employmentDate = dh.getDate();

			emp.birthDate = birthDate;
			emp.employmentDate = employmentDate;

			employees.push_back(emp);

			cout << "Continue ? (Y/any other input): ";
			cin >> state;
			cin.ignore();
		}
		cout << "----------" << endl;
		return employees;
	}

	void Application::showEmployees(vector<Employee> employees)
	{
		EmployeeHandler eh;

		
		for (auto emp : employees)
		{
			eh.showEmployeeInfo(emp);
			cout << endl;
		}
	}

	int Application::readFile(string fileName, vector<Employee> &employees)
	{
		Employee emp;
		EmployeeHandler eh;
		ifstream fin;

		fin.open(fileName, ios::binary | ios::in);

		if (!fin.is_open())
		{
			cout << "Could not read a file";
						return 1;
		}

		while (fin.read((char*)&emp, sizeof(Employee)))
		{
			employees.push_back(emp);
		}

		fin.close();

		return 0;
	}

	int Application::writeFile(string fileName, vector<Employee> employees)
	{
		ofstream fout;
		fout.open(fileName, ios::binary | ios::out);

		if (!fout.is_open())
		{
			cout << "Could not write a file";
			return 1;
		}

		for (auto employee : employees)
		{
			fout.write((char*)&employee, sizeof(Employee));
		}

		fout.close();
		return 0;
	}
	

	vector<Employee> Application::removeEmployees(vector<Employee> employees, Date today, int timeSpan , removeMode rmMode)
	{
		DateHandler dh;
		EmployeeHandler eh;
		Date nYearsAgo = today;

		nYearsAgo.year -= timeSpan;


		vector<Employee>::iterator currentEmp = employees.begin();

		if (rmMode == removeMode::experience)
		{
			while (currentEmp != employees.end())
			{

				if (dh.isOlderThen((*currentEmp).employmentDate, nYearsAgo))
				{

					currentEmp = employees.erase(currentEmp);
				}
				else
				{
					currentEmp++;
				}

			}
		}
		else
		{
			while (currentEmp != employees.end())
			{

				if (dh.isOlderThen((*currentEmp).birthDate, nYearsAgo))
				{

					currentEmp = employees.erase(currentEmp);
				}
				else
				{
					currentEmp++;
				}

			}
		}

		return employees;
	}



