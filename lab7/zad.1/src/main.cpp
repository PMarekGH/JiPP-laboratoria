#include <iostream>
#include <random>
#include <lab7/employee.hpp>
#include <lab7/HRMS.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    
    Employee emp1("1", "Jan", "Kowalski", "DEP1", "Starszy Inżynier");
    Employee emp2("2", "Piotr", "Szczerbik", "DEP2", "Księgowy");
    Employee emp3("3", "Mikołaj", "Jurek", "DEP1", "Programista c++");
    Employee emp4("4", "Barbara", "Jaśkowska", "DEP3", "Front End Developer");
    Employee emp5("5", "Kazimierz", "Marek", "DEP3", "Programista Baz Danych");
    Employee emp6("6", "Aleksander", "Mozgała", "DEP2", "Inżynier Oprogramowania");
    Employee emp7("7", "Ignacy", "Krasicki", "DEP1", "Ochroniarz");
    Employee emp8("8", "Zofia", "Michalska", "DEP3", "Specjalistka ds. Marketingu");
    Employee emp9("9", "Aleksandra", "Czerwińska", "DEP2", "Tester Oprogramowania");
    Employee emp10("10", "Bogdan", "Kot", "DEP1", "Pracownik Biurowy");

    HRMS hrms;
    hrms.add(emp1, emp1.GetDepartmentId(), 4000);
    hrms.add(emp2, emp2.GetDepartmentId(), 5060);
    hrms.add(emp3, emp3.GetDepartmentId(), 4240);
    hrms.add(emp4, emp4.GetDepartmentId(), 2900);
    hrms.add(emp5, emp5.GetDepartmentId(), 3020);
    hrms.add(emp6, emp6.GetDepartmentId(), 8040);
    hrms.add(emp7, emp7.GetDepartmentId(), 9090);
    hrms.add(emp8, emp8.GetDepartmentId(), 9990);
    hrms.add(emp9, emp9.GetDepartmentId(), 2898);
    hrms.add(emp10, emp10.GetDepartmentId(), 7540);

    std::cout << "printDepartment(\"DEP1\")" << std::endl;
    hrms.printDepartment("DEP1");
    std::cout << "printDepartment(\"DEP3\")" << std::endl;
    hrms.printDepartment("DEP3");
    std::cout  << "printSalaries()" << std::endl;
    hrms.printSalaries();
    std::cout << "changeSalary(emp1.GetId(), 10000)" << std::endl;
    hrms.changeSalary(emp1.GetId(), 10000);
    std::cout << "printSalaries()" << std::endl;
    hrms.printSalaries();

    std::cout << "printSalariesSorted()" << std::endl;
    hrms.printSalariesSorted();

    return 0;
}
