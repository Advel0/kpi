#pragma once
#include <string>

using namespace std;

struct Date 
{
	int year;
	int month;
	int day;
};

struct Employee 
{
	char fullName[40];
	Date birthDate;
	Date employmentDate;
};
