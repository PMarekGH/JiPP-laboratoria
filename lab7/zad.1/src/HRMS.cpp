#include <lab3/HRMS.hpp>
#include <algorithm>

using namespace std;

HRMS::HRMS()
{

}

HRMS::add(Employee employee, string departmentID, double salary)
{
    employees.push_back(employee);

    auto it = departmentEmployee.find(employee.getDepartmentId()); 
    if (it != departmentEmployee.end())
    {
        it->second.push_back(employee.GetId());
    }
    else
    {
        departmentEmployee.insert({employee.GetDepartmentId(), employee.getId()});
    }
    
    salaries.insert({employee.GetId(), salary});
}

HRMS::printDepartment(string departmentId)
{
    auto employeeIds = departmentEmployee.find(departmentId);
    if(employeeIds != departmentEmployee.end())
    {
        for_each(employeeIds->second.front(), employeeIds->second.back(), [](string employeeId){
            cout << employeeId << endl;
        });
    }
}

HRMS::changeSalary(string employeeId, double salary)
{
    auto employee = salary.find(employeeId);
    employee->second = salary;
}

HRMS::printSalaries()
{
    cout << "Employee: {Id, name, surname, departmentId, position}, salary" << endl;
    for_each(employees.front(), employees.end(), [](Employee employee){
        cout << "Employee: {" << employee.GetId() << ", " << employee.GetName() << ", " << employee.GetSurname() << ", " << employee.GetDepartmentId() << ", " << employee.GetPosition() << "}, ";
        auto it = salaries.find(employee.GetId());
        cout << it->second << endl;
    });
}

HRMS::printSalariesSorted()
{

}