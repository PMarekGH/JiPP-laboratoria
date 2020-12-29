#include <lab7/HRMS.hpp>
#include <algorithm>


bool valueSort(const std::pair<std::string, double> &fst, 
               const std::pair<std::string, double> &snd) 
{ 
    return (fst.second > snd.second); 
} 

void HRMS::add(Employee employee, std::string departmentID, double salary)
{
    employees.push_back(employee);
    std::pair<std::string, std::string> tempPair;
    tempPair.first = departmentID;
    tempPair.second = employee.GetId();
    departmentEmployee.insert(tempPair);
    salaries.insert({employee.GetId(), salary});
}

void HRMS::printDepartment(std::string departmentId)
{
    std::cout << "Department: " << departmentId << std::endl;
    std::pair<std::multimap<std::string, std::string>::iterator, std::multimap<std::string, std::string>::iterator> range = departmentEmployee.equal_range(departmentId);
    std::for_each(range.first, range.second, [](const auto &mapPair){
        std::cout << mapPair.second << std::endl;
    });

}

void HRMS::changeSalary(std::string employeeId, double salary)
{
    auto employee = salaries.find(employeeId);
    employee->second = salary;
}

void HRMS::printSalaries()
{
    for(Employee employee : employees)
    {
        std::cout << employee.GetId() << ", ";
        auto it = salaries.find(employee.GetId());
        std::cout << it->second << std::endl;
    }
}

void HRMS::printSalariesSorted(){
    std::vector<std::pair<std::string,double>> tempVector;
    for(auto itr=salaries.begin();itr!=salaries.end();itr++)
    {
        tempVector.push_back(std::make_pair(itr->first,itr->second));
    }
    std::sort(tempVector.begin(),tempVector.end(), valueSort);
    for(int i=0;i<tempVector.size();i++)
    {
        std::cout << tempVector[i].first << ", " << tempVector[i].second << std::endl;
    }
 }