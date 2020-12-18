#include <lab3/employee.hpp>

using namespace std;

    Employee::Employee(string _id, string _name, string _surname, string _departmentId, string _position)
    {
        id = _id;
        name = _name;
        surname = _surname;
        departmentId = _departmentId;
        position = _position;
    }

    Employee::string GetId() const {
    return id;
    }

    Employee::void SetId(string _id) {
    id = _id;
    }

    Employee::string GetName() const {
        return name;
    }

    Employee::void SetName(string _name) {
        name = _name;
    }

    Employee::string GetSurname() const {
        return surname;
    }

    Employee::void SetSurname(string _surname) {
        surname = _surname;
    }

    Employee::string GetDepartmentId() const {
        return departmentId;
    }

    Employee::void SetDepartmentId(string _departmentId) {
        departmentId = _departmentId;
    }

    Employee::string GetPosition() const {
        return position;
    }

    Employee::void SetPosition(string _position) {
        position = _position;
    }