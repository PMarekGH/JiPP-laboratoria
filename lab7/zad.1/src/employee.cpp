#include <lab7/employee.hpp>

    Employee::Employee(std::string _id, std::string _name, std::string _surname, std::string _departmentId, std::string _position)
    {
        id = _id;
        name = _name;
        surname = _surname;
        departmentId = _departmentId;
        position = _position;
    }

    std::string Employee::GetId() const {
    return id;
    }

    void  Employee::SetId(std::string _id) {
    id = _id;
    }

    std::string Employee::GetName() const {
        return name;
    }

    void Employee::SetName(std::string _name) {
        name = _name;
    }

    std::string Employee::GetSurname() const {
        return surname;
    }

    void Employee::SetSurname(std::string _surname) {
        surname = _surname;
    }

    std::string Employee::GetDepartmentId() const {
        return departmentId;
    }

    void Employee::SetDepartmentId(std::string _departmentId) {
        departmentId = _departmentId;
    }

    std::string Employee::GetPosition() const {
        return position;
    }

    void Employee::SetPosition(std::string _position) {
        position = _position;
    }