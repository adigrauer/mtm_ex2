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
    
    Manager::Manager (const Manager& manager):
        Citizen(manager),
        salary(manager.getSalary())
    {
        employees = manager.employees;
    }

    Manager::~Manager ()
    {
        employees.clear();
    }

    int Manager::getSalary () const
    {
        return salary;
    }

    Citizen* Manager::clone () const
    {
        return new Manager(*this);
    }
    
    bool Manager::cheackIfEmployeeExist (int employee_id) 
    {
        if (employees.empty() == true) 
        {
            return false;
        }
        vector<shared_ptr<Employee>>::iterator ptr;
        Employee temp_employee(employee_id, "temp", "temp", 0);
        for(ptr = employees.begin(); ptr != employees.end(); ++ptr){
            if(**ptr == temp_employee){
                return true;;
            }
        }
        return false;
        
        /*
        vector<shared_ptr<Employee>>::iterator ptr;
        if (employees.empty() == true) 
        {
            return false;
        }
        for(ptr = employees.begin(); ptr != employees.end(); ++ptr){
            if(**ptr == (*employee)){
                return true;
            }
        }
        return false;
        */
    }

    void Manager::addEmployee (Employee* employee)
    {
        int id =(*employee).getId();
        if((cheackIfEmployeeExist(id)) == true){
            throw EmployeeAlreadyHired();
        }
        //workd_1
        //vector<shared_ptr<Employee>>::iterator it = employees.begin();
        //employees.insert(it, employee_to_add);
        
        ///worked_2_last- dont print the employees
        /*
        Employee employee_to_add(*employee);
        shared_ptr<Employee> employee_to_add_ptr(&employee_to_add); 
        employees.push_back(employee_to_add_ptr);
        */
        shared_ptr<Employee> employee_to_add(employee);
        employees.push_back(employee_to_add);
    }
    
    void Manager::removeEmployee (int employee_id) 
    {   
        vector<shared_ptr<Employee>>::iterator ptr;
        Employee temp_employee(employee_id, "temp", 0, 0); 
        if((cheackIfEmployeeExist(employee_id)) == false){
            throw EmployeeNotHired();
        }
        for(ptr = employees.begin(); ptr != employees.end(); ++ptr){
            if(**ptr == temp_employee){
                employees.erase(ptr);
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
        << "salary: " << salary << endl;
        return os;
    }

    ostream& Manager::printLong (ostream& os) const
    {
        shared_ptr<Employee> print_ptr;
        os << getFirstName() << " " << getLastName() << endl;
        os << "id - " << getId() << " " << "birth_year - " << getBirthYear() << endl;
        os << "salary: " << salary << endl;
        if(employees.empty() == false){
            os << "Employees:" << endl;
            int how_many_to_print = employees.size();
            for (print_ptr = findMinimalIdEmployee(); how_many_to_print != 0; --how_many_to_print){
                (*print_ptr).printShort(os);
                print_ptr = findNextEmployeeToPrint(print_ptr);
            }
            return os;
        }
        return os;
    }

    shared_ptr<Employee> Manager::findMinimalIdEmployee () const
    {
        vector<shared_ptr<Employee>>::const_iterator iterator;
        shared_ptr<Employee> current_minimal(*(employees.begin()));
        for (iterator = employees.begin(); iterator != employees.end(); ++iterator)
        {
            if ((**iterator).getId() < (*current_minimal).getId()){
                current_minimal = *iterator;
            }
        }
        return current_minimal;
    }

    shared_ptr<Employee> Manager::findNextEmployeeToPrint (shared_ptr<Employee> last_printed) const
    {
        vector<shared_ptr<Employee>>::const_iterator iterator = employees.begin();
        shared_ptr<Employee> current_next(last_printed);
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
            else {
                current_next = *iterator;
            }
            return current_next;
        }   
        return current_next;
    }


}
