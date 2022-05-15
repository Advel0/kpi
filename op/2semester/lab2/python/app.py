from site import enablerlcompleter
from dateHandlers import *
from dataTypes import *

def main():
#     app = Application()
#     eh = EmployeeHandler()
#     file_name = 'file.dat'
#     list = app.get_input()

#    # print([eh.show_employee_info(emp) for emp in list])
#     for emp in list:
#         eh.show_employee_info(emp)

    file_name = 'file.dat'
    app = Application()
    emps = app.get_input()

    with open(file_name, 'wb') as file:
        for emp in emps:
            file.write('444')
        file.close()

main()
