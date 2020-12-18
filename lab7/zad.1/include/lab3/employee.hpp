#pragma once

#include <string>

using namespace std;

class Employee
{
    public:
    // Constructors
    Employee();
    Employee(string, string, string, string, string);

    // Methods
    string GetId() const;
    void SetId();
    string GetName() const;
    void SetName();
    string GetSurname() const;
    void SetSurname();
    string GetDepartmentId() const;
    void SetDepartmentId();
    string GetPosition() const;
    void SetPosition() const;

    private:
    string id;
    string name;
    string surname;
    string departmentId;
    string position;

};