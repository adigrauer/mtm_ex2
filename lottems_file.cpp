#include "Manager.h"
#include "Employee.h"
#include "exception.h"
#include <vector>
#include <memory>

using std::vector;

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
        shared_ptr<Employee> print_ptr;
        os << getFirstName() << " " << getLastName() << endl;
        os << "id - " << getId() << " " << "birth_year - " << getBirthYear() << endl;
        os << "salary: " << salary << endl;
        os << "Employees:" << endl;
        int how_many_to_print = employees.size();
        for (print_ptr = findMinimalIdEmployee(); how_many_to_print != 0; --how_many_to_print)
        {
            (*print_ptr).printShort(os);
            print_ptr = findNextEmployeeToPrint(print_ptr);
        }
        return os;
    }

    shared_ptr<Employee> Manager::findMinimalIdEmployee () {
        vector<shared_ptr<Employee>>::iterator iterator;
        shared_ptr<Employee> current_minimal(*(employees.begin()));
        for (iterator = employees.begin(); iterator != employees.end(); ++iterator)
        {
            if ((**iterator).getId() < (*current_minimal).getId()){
                current_minimal = *iterator;
            }
        }
        return current_minimal;
    }
    shared_ptr<Employee> Manager::findNextEmployeeToPrint (shared_ptr<Employee> last_printed)
    {
        vector<shared_ptr<Employee>>::iterator iterator;
        shared_ptr<Employee> current_next(last_printed);
        for (iterator = employees.begin(); iterator != employees.end(); ++iterator)
        {
            if ((*last_printed) < (**iterator) && (**iterator) < (*current_next)){
                current_next = (*iterator);
            }
        }
        return current_next;
    }
}
