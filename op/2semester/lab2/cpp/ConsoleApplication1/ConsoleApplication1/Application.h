#pragma once
#include <vector>
#include "Structs.h"

enum removeMode {
	age,
	experience
};

class Application
{
public:
	vector<Employee> getInput();
	int readFile(string fileName, vector<Employee>& employees);
	void showEmployees(vector<Employee> employees);
	int writeFile(string fileName, vector<Employee> employees);
	vector<Employee> removeEmployees(vector<Employee> employees, Date today, int timeSpan, removeMode rmMode);
	string start();
};

