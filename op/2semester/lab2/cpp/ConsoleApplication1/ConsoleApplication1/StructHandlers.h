#pragma once
#include <iostream>
#include "Structs.h"

using namespace std;

class DateHandler 
{

public:
	Date getDate();
	bool isOlderThen(Date younger, Date older);
};

class EmployeeHandler {
public:
	void showEmployeeInfo(Employee employee);
};

