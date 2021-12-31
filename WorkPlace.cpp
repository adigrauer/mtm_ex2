#include "WorkPlace.h"

namespace mtm {
    WorkPlace::WorkPlace (int workplace_id, string workplace_name, int workers_salary, int managers_salary):
        workplace_id(workplace_id),
        workers_salary(workers_salary),
        managers_salary(managers_salary),
        workplace_name(workplace_name),
        managers()
    {
    }

    int WorkPlace::getID () const
    {
        return workplace_id;
    }

    int WorkPlace::gerWorkersSalary() const
    {
        return workers_salary;
    }

    int WorkPlace::getManagersSalary() const
    {
        return managers_salary;
    } 

    string WorkPlace::getName () const
    {
        return workplace_name;
    }

    bool WorkPlace::checkIfManagerExist (int manager_id)
    {
        vector<Manager*>::iterator ptr;
        Manager temp_manager(manager_id, "temp", "temp", 0);
        for(ptr = managers.begin(); ptr != managers.end(); ++ptr){
            if(**ptr == temp_manager){
                return true;;
            }
        }
        return false;
    }

    void WorkPlace::hireManager (Manager* manager)
    {
        if(checkIfManagerExist((*manager).getId()) == true){
            throw ManagerAlreadyHired();
        }
        if (manager->getSalary() != 0) {
            throw CanNotHireManager();
        }
        manager->setSalary(getManagersSalary());
        //Manager* manager1 = new Manager(*manager);
        //shared_ptr<Manager> manager_to_add(manager);
        //managers.push_back(manager_to_add);
        managers.push_back(manager);
    }
            
    void WorkPlace::fireEmployee (int worker_id, int manager_id)
    {
        Manager temp_manager(manager_id, "temp", "temp", 0);
        Employee temp_employee(worker_id, "temp", "temp", 0); 
        if(checkIfManagerExist((manager_id) == false)){
            throw ManagerIsNotHired();
        }
        vector<Manager*>::iterator ptr;
        for(ptr = managers.begin(); ptr != managers.end(); ++ptr){
            if(**ptr == temp_manager){
                if((*ptr)->cheackIfEmployeeExist(worker_id) == false){
                        throw EmployeeIsNotHired();
                }
                vector<shared_ptr<Employee>>::iterator ptr_to_employee;
                (**ptr).ChangeEmployeeSalary(worker_id, -workers_salary);
                (**ptr).removeEmployee(worker_id);
                return;
            }
        }
    }

    void WorkPlace::fireManager (int manager_id)
    {
        Manager temp_manager(manager_id, "temp", "temp", 0);
        if(checkIfManagerExist((manager_id) == false)){
            throw ManagerIsNotHired();
        }
        vector<Manager*>::iterator ptr_manager;
        for(ptr_manager = managers.begin(); ptr_manager != managers.end(); ++ptr_manager){
            if((**ptr_manager) == temp_manager){
                (**ptr_manager).setSalary(-managers_salary);
                (**ptr_manager).ChangeAllEmployeesSalary(-workers_salary);
                managers.erase(ptr_manager);
                return;
            }
        }
    }

    bool WorkPlace::checkIfTwoEmployeesWorkTogther (int worker_a_id, int worker_b_id)
    {
        vector<Manager*>::iterator ptr_manager;
        for(ptr_manager = managers.begin(); ptr_manager != managers.end(); ++ptr_manager){
            if((**ptr_manager).cheackIfEmployeeExist(worker_a_id) == true){
                if((**ptr_manager).cheackIfEmployeeExist(worker_b_id) == true){
                    return true;
                }
            }
        }
        return false;
    }

    bool operator< (const WorkPlace& workplace_a, const WorkPlace& workplace_b)
    {
        return workplace_a.getName() < workplace_b.getName();
    }

    bool operator== (const WorkPlace& workplace_a, const WorkPlace& workplace_b)
    {
        return workplace_a.getName() == workplace_b.getName();
    }


    ostream& operator<< (ostream& os, const WorkPlace& workplace) 
    {
        workplace.printLong(os);
        return os;
    }

    Manager* WorkPlace::findMinimalIdManager () const
    {
        vector<Manager*>::const_iterator iterator;
        Manager* current_minimal(*(managers.begin()));
        for (iterator = managers.begin(); iterator != managers.end(); ++iterator){
            if ((**iterator).getId() < (*current_minimal).getId()){
                current_minimal = *iterator;
            }
        }
        return current_minimal;
    }

    Manager* WorkPlace::findNextManagerToPrint (Manager* last_printed) const
    {
        vector<Manager*>::const_iterator iterator = managers.begin();
        Manager* current_next(last_printed);
        while (iterator != managers.end()){
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

    ostream& WorkPlace::printLong (ostream& os) const
    {
        Manager* print_ptr;
        if(managers.empty() == false){
            os << "Workplace name - " <<getName() << " Groups:" << endl;
            os << "Manager" << " ";
            int how_many_to_print = managers.size();
            for(print_ptr = findMinimalIdManager(); how_many_to_print != 0; --how_many_to_print){
                (*print_ptr).printLong(os);
                print_ptr = findNextManagerToPrint(print_ptr);
            }
            return os;
        }
        os << "Workplace name - " << getName() << endl;
        return os;
    }

}
