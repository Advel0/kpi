#include "StructHandlers.h"
#include "Structs.h"

using namespace std;




	Date DateHandler::getDate()
	{
		Date date;
		int year, month, day;

		cout << "Year: ";
		cin >> year;
		cout << "Month: ";
		cin >> month;
		cout << "Day: ";
		cin >> day;

		date.year = year;
		date.month = month;
		date.day = day;

		return date;
	}
	bool DateHandler::isOlderThen(Date younger, Date older) {
		bool isOlder = false;
		if (younger.year - older.year > 0)
		{
			isOlder = true;
		}
		else if (younger.year - older.year == 0)
		{
			if (younger.month - older.month > 0)
			{
				isOlder = true;
			}
			else if (younger.month - older.month == 0)
			{
				if (younger.day - older.day >= 0)
				{
					isOlder = true;
				}
			}

		}
		return isOlder;
	}



	void EmployeeHandler::showEmployeeInfo(Employee employee)
	{
		cout << "Full Name : " << employee.fullName << " | ";
		cout << "Birdth Date : " << employee.birthDate.day << '/' << employee.birthDate.month << '/' << employee.birthDate.year << " | ";
		cout << "Employment Date : " << employee.employmentDate.day << '/' << employee.employmentDate.month << '/' << employee.employmentDate.year;
	}

