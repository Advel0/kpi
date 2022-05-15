from dataTypes import *

class DateHandler:
    def get_date(self):
        year = int(input('Year: '))
        month = int(input('Month: '))
        day = int(input('Day: '))
        date = Date(year, month, day)

        return date 
    def get_string(self, emp):
        return '{}/{}/{}'.format(emp.year, emp.month, emp.day)

class EmployeeHandler:
    def show_employee_info(self, employee):
        dh = DateHandler()
        print('Full Name: {} | Birth Date: {}| Employment Date: {}'.format(employee.full_name, dh.get_string(employee.birth_date), dh.get_string(employee.employment_date) ))

class Application:
    def get_input(self):
        dh = DateHandler()
        emps = []
        state = 'Y'

        while (state == 'Y'):
            print('Add new employee: ')
            full_name = input('Enter full name: ')
            print('Enter birth date: ')
            birth_date = dh.get_date()
            print('Enter employment date: ')
            employment_date = dh.get_date()

            emp = Employee(full_name, birth_date, employment_date)
            emps.append(emp)

            state = input('Add another employee (Y/Any other input): ')

        return emps
    