#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <lab7/employee.hpp>

class HRMS
{
    public:
    // Constructors
    // HRMS();

    // Methods
    void add(Employee employee, std::string str, double salary);
    void printDepartment(std::string departmentId);
    void changeSalary(std::string employeeId, double salary);
    void printSalaries();
    void printSalariesSorted(); //std::algorithm


    private:

    std::vector<Employee> employees;
    std::multimap<std::string, std::string> departmentEmployee;
    std::map<std::string, double> salaries;

};