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
            employees[it] = ((manager.employees[it]).clone());
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

    void Manager::addEmployee (const Employee* employee)
    {
        /*if(cheackIfEmployeeExist(employee) == true){
            thorw EmployeeAlreadyHired;
        }*/
        employees.push_back(*employee);
    }
    
    void Manager::removeEmployee (const unsigned int id_employee)
    {
        
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
        os << "Long_print" << endl
        << getFirstName() << " " << getLastName() << endl
        << "id - " << getId() << " " << "birth_year - " << getBirthYear() << endl
        << "salary: " << this->salary << endl;
        //print workers
        return os;
    }
}
