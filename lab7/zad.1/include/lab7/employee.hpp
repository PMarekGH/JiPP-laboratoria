#pragma once

#include <string>

class Employee
{
    public:
    // Constructors
    Employee();
    Employee(std::string id, std::string name, std::string surname, std::string departmentId, std::string position);

    // Methods
    std::string GetId() const;
    void SetId(std::string);
    std::string GetName() const;
    void SetName(std::string);
    std::string GetSurname() const;
    void SetSurname(std::string);
    std::string GetDepartmentId() const;
    void SetDepartmentId(std::string);
    std::string GetPosition() const;
    void SetPosition(std::string);

    private:
    std::string id;
    std::string name;
    std::string surname;
    std::string departmentId;
    std::string position;

};