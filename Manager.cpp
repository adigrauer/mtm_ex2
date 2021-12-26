#include "Manager.h"
#include "Employee.h"
#include "exception.h"
namespace mtm {
    
    Manager::Manager (int id_citizen, string first_name, string last_name, int birth_year) :
        Citizen(id_citizen, first_name, last_name, birth_year),
        salary(STARTING_SALARY_MANAGER),
        employees()
    {
    }
    
    int Manager::getSalary () const
    {
        return salary;
    }

    Citizen* Manager::clone () const
    {
        return new Manager(*this);
    }
    
    //need to think if needs to be const
    bool Manager::cheackIfEmployeeExist (Employee employee) const
    {
        if (employee == *(employees.find(employee))){
            return true;
        }
        return false;
    }

    void Manager::addEmployee (Employee* employee)
    {
        if(cheackIfEmployeeExist(*employee) == true){
            throw EmployeeAlreadyHired();
        }
        employees.insert(*employee);
    }
    
    void Manager::removeEmployee (int employee_id) 
    {   
        Employee temp_employee(employee_id, "temp", 0, 0); 
        if(cheackIfEmployeeExist(temp_employee) == false){
            throw EmployeeNotHired();
        }
        employees.erase(employees.find(temp_employee));
    }
    
    void Manager::setSalary (int salary_to_add)
    {
        if ((salary+salary_to_add) <= STARTING_SALARY_MANAGER){
            salary = STARTING_SALARY_MANAGER;
            return;
        }
        salary += salary_to_add;
        return;
    }

    ostream& Manager::printShort (ostream& os) const 
    {
        os << getFirstName() << " " << getLastName() << endl
        << "salary: " << salary << endl;
        return os;
    }

    ostream& Manager::printLong (ostream& os) const
    {
        set<Employee>::iterator print_iterator;
        os << getFirstName() << " " << getLastName() << endl;
        os << "id - " << getId() << " " << "birth_year - " << getBirthYear() << endl;
        os << "salary: " << salary << endl;
        os << "Employees:" << endl;
        for (print_iterator = employees.begin(); print_iterator != employees.end(); ++print_iterator) {
            (*print_iterator).printShort(os);
        }
        return os;
    }
}
