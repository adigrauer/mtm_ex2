#include "Manager.h"
#include "Employee.h"

namespace mtm {
    
    Manager::Manager (int id_citizen, string first_name, string last_name, int birth_year) :
        Citizen(id_citizen, first_name, last_name, birth_year),
        salary(STARTING_SALARY), employees()
    {
    }
    
    Manager::Manager (const Manager& manager) :
        salary(manager.salary),
        Citizen(manager)
    {
        for (int it = 0 ; it != manager.employees.size() ; ++it){
            shared_ptr<Employee> ptr_to_add (employees[it]);
            employees.push_back(ptr_to_add);
        }
    }
    
    int Manager::getSalary ()
    {
        return salary;
    }

    Citizen* Manager::clone () const
    {
        return new Manager(*this);
    }
    
    bool Manager::cheackIfEmployeeExist (const Employee* employee)
    {
        for(int it = 0 ; it != employees.size() ; ++it){
            if(*(employees[it]) == *(employee))
                return true;
        }
        return false;
    }

    void Manager::addEmployee (Employee* employee)
    {
        /*if(cheackIfEmployeeExist(employee) == true){
            thorw EmployeeAlreadyHired;
        }*/
        shared_ptr<Employee> ptr_to_add (employee);
        employees.push_back(ptr_to_add);
    }
    
    void Manager::removeEmployee (const unsigned int employee_id)
    {
        for(int it = 0 ; it != employees.size() ; ++it){
            if(*(employees[it]) == employee_id){
                employees.push_back(employees[it]);
                return;
            }
        }
    }
    
    void Manager::setSalary (unsigned int salary_to_add)
    {
        salary += salary_to_add;
        return;
    }

    ostream& Manager::printShort (ostream& os)
    {
        os << "Short_print" << endl 
        << getFirstName() << " " << getLastName() << endl
        << "salary: " << this->salary << endl;
        return os;
    }

    ostream& Manager::printLong (ostream& os)
    {
        os << "Long_print" << endl;
        os << getFirstName() << " " << getLastName() << endl;
        os << "id - " << getId() << " " << "birth_year - " << getBirthYear() << endl;
        os << "salary: " << this->salary << endl;
        os << "Employees:" << endl;
        for(int it = 0 ; it != employees.size() ; ++it){
            (employees[it])->printShort(os);
        }
        return os;
    }
}
