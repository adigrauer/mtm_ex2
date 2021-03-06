#include "Manager.h"

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

    Manager* Manager::clone () const
    {
        return new Manager(*this);
    }
    
    bool Manager::cheackIfEmployeeExist (int employee_id) 
    {
        if (employees.empty() == true) 
        {
            return false;
        }
        vector<Employee*>::iterator ptr;
        Employee temp_employee(employee_id, "temp", "temp", 0);
        for(ptr = employees.begin(); ptr != employees.end(); ++ptr){
            if(**ptr == temp_employee){
                return true;
            }
        }
        return false;
    }

    void Manager::addEmployee (Employee* employee)
    {
        int id =(*employee).getId();
        if((cheackIfEmployeeExist(id)) == true){
            throw EmployeeAlreadyHired();
        }
        employees.push_back(employee);
    }
    
    void Manager::removeEmployee (int employee_id) 
    {   
        vector<Employee*>::iterator ptr; 
        if((cheackIfEmployeeExist(employee_id)) == false){
            throw EmployeeIsNotHired();
        }
        for(ptr = employees.begin(); ptr != employees.end(); ++ptr){
            if((**ptr).getId() == employee_id){
                employees.erase(ptr);
                return;
            }
        }
    }

    void Manager::fireAllEmployees ()
    {
        employees.clear();
    }

    void Manager::ChangeAllEmployeesSalary (int employee_salary_to_change)
    { 
        if(employees.empty() == true){
            return;
        }
        vector<Employee*>::iterator ptr_employee;
        for(ptr_employee = employees.begin(); ptr_employee != employees.end(); ++ptr_employee){
            (*ptr_employee)->setSalary(employee_salary_to_change);
        }
    }

    void Manager::ChangeEmployeeSalary (int employee_id, int salary_to_decrese)
    { 
        vector<Employee*>::iterator ptr_employee;
        for(ptr_employee = employees.begin(); ptr_employee != employees.end(); ++ptr_employee){
            if (((*ptr_employee)->getId()) == employee_id){
            (*ptr_employee)->setSalary(salary_to_decrese);
            return;
            }
        }
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
        << "Salary: " << getSalary() << endl;
        return os;
    }

    ostream& Manager::printLong (ostream& os) const
    {
        Employee* print_ptr;
        os << getFirstName() << " " << getLastName() << endl;
        os << "id - " << getId() << " " << "birth_year - " << getBirthYear() << endl;
        os << "Salary: " << getSalary() << endl;
        if(employees.empty() == false){
            os << "Employees: " << endl;
            int how_many_to_print = employees.size();
            for (print_ptr = findMinimalIdEmployee(); how_many_to_print != 0; --how_many_to_print){
                (*print_ptr).printShort(os);
                print_ptr = findNextEmployeeToPrint(print_ptr);
            }
            return os;
        }
        return os;
    }

    Employee* Manager::findMinimalIdEmployee () const
    {
        vector<Employee*>::const_iterator iterator;
        Employee* current_minimal(*(employees.begin()));
        for (iterator = employees.begin(); iterator != employees.end(); ++iterator)
        {
            if ((**iterator).getId() < (*current_minimal).getId()){
                current_minimal = *iterator;
            }
        }
        return current_minimal;
    }

    Employee* Manager::findNextEmployeeToPrint (Employee* last_printed) const
    {
        vector<Employee*>::const_iterator iterator = employees.begin();
        Employee* current_next(last_printed);
        while (iterator != employees.end()){
            if ((**iterator) <= *last_printed){
                ++iterator;
                continue;
            }
            if((**iterator) < *current_next) {
                current_next = *iterator;
                ++iterator;
                continue;
            }
            if((*last_printed) == *current_next) {
                current_next = *iterator;
                ++iterator;
                continue;
            }
            return current_next;
        }   
        return current_next;
    }


}
