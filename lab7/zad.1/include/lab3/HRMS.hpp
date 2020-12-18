#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <lab3/employee.hpp>

using namespace std;

class HRMS
{
    public:
    // Constructors
    HRMS();

    // Methods
    add(Employee, string, double);
    printDepartment(string);
    changeSalary(string, double);
    printSalaries();
    printSalariesSorted(); //std::algorithm


    private:

    vector<Employee> employees;
    map<string, vector<string>> departmentEmployee;
    map<Employee, double> salaries;

};