#include "Manager.h"
#include "Employee.h"
#include "exception.h"
namespace mtm {
    
    Manager::Manager (int id_citizen, string first_name, string last_name, int birth_year) :
        Citizen(id_citizen, first_name, last_name, birth_year),
        salary(STARTING_SALARY)
    {
        vector<shared_ptr<Employee>> employees;
    }
    
    Manager::Manager (const Manager& manager) :
        Citizen(manager),
        salary(manager.salary)
    {
        for (int it = 0 ; it != manager.employees.size() ; ++it){
            shared_ptr<Employee> ptr_to_add (employees[it]);
            employees.push_back(ptr_to_add);
        }
    }
    Manager:: ~Manager (){
        employees.clear();
    }

    int Manager::getSalary ()
    {
        return salary;
    }

    Citizen* Manager::clone () const
    {
        return new Manager(*this);
    }
    
    bool Manager::cheackIfEmployeeExist (Employee employee)
    {
        for(int it = 0 ; it != employees.size() ; ++it){
            if(*(employees[it]) == (employee))
                return true;
        }
        return false;
    }

    void Manager::addEmployee (Employee* employee)
    {
        if(cheackIfEmployeeExist(*employee) == true){
            throw EmployeeAlreadyHired();
        }
        shared_ptr<Employee> ptr_to_add (employee);
        employees.push_back(ptr_to_add);
    }
    
    void Manager::removeEmployee (const unsigned int employee_id)
    {   
        Employee temp_employee(employee_id, "temp", 0, 0); 
        if(cheackIfEmployeeExist(temp_employee) == false){
            throw EmployeeNotHired();
        }
        for(vector<shared_ptr<Employee>>::iterator iterator = employees.begin() ; iterator != employees.end() ; ++iterator){
            if((**iterator) == temp_employee){
                employees.erase(iterator);
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
        os << getFirstName() << " " << getLastName() << endl
        << "salary: " << salary << endl;
        return os;
    }

    ostream& Manager::printLong (ostream& os)
    {
        os << getFirstName() << " " << getLastName() << endl;
        os << "id - " << getId() << " " << "birth_year - " << getBirthYear() << endl;
        os << "salary: " << salary << endl;
        os << "Employees:" << endl;
        for(int it = 0 ; it != employees.size() ; ++it){
            (*employees[it]).printShort(os);
        }
        return os;
    }
}
