#include "WorkPlace.h"

namespace mtm {
    Workplace::Workplace (int workplace_id, string workplace_name, int workers_salary, int managers_salary):
        workplace_id(workplace_id),
        workers_salary(workers_salary),
        managers_salary(managers_salary),
        workplace_name(workplace_name),
        managers()
    {
    }

     Workplace::Workplace (const Workplace& workplace):
        workplace_id(workplace.workplace_id),
        workers_salary(workplace.workers_salary),
        managers_salary(workplace.managers_salary),
        workplace_name(workplace.workplace_name)
    {
        unsigned int size = workplace.managers.size();
        for (unsigned int i = 0; i < size ; ++i){
            Manager* manager = new Manager(*(workplace.managers[i]));
            managers.push_back(manager);
        }
    }

    Workplace& Workplace::operator=(const Workplace& workplace) 
    {
        if (this == &workplace) {
		    return *this;
	    }
        if(managers.empty() == false){
            unsigned int size = managers.size();
            for (unsigned int i = 0; i < size ; ++i){
                if(managers[i]->need_to_delete){
                    delete managers[i];
                }
            }
        }
        managers.clear();
        if(workplace.managers.empty() == false){
            unsigned int size_temp = workplace.managers.size();
            for (unsigned int i = 0; i < size_temp ; ++i){
                Manager* manager = new Manager(*(workplace.managers[i]));
                managers.push_back(manager);
            }
        }
        //need_to_delete = true;
	    return *this;
    }
    
    Workplace::~Workplace () 
    {
        if(managers.empty() == false){
            unsigned int size = managers.size();
            for (unsigned int i = 0; i < size ; ++i){
                if(managers[i]->need_to_delete){
                    delete managers[i];
                }
            }
        }
    }

    int Workplace::getId () const
    {
        return workplace_id;
    }

    int Workplace::getWorkersSalary() const
    {
        return workers_salary;
    }

    int Workplace::getManagersSalary() const
    {
        return managers_salary;
    } 

    string Workplace::getName () const
    {
        return workplace_name;
    }

    bool Workplace::checkIfManagerExist (int manager_id)
    {
        if (managers.empty() == true){
            return false;
        }
        vector<Manager*>::iterator ptr;
        Manager temp_manager(manager_id, "temp", "temp", 0);
        for(ptr = managers.begin(); ptr != managers.end(); ++ptr){
            if(**ptr == temp_manager){
                return true;;
            }
        }
        return false;
    }

    void Workplace::hireManager (Manager* manager)
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
            
    void Workplace::fireEmployee (int worker_id, int manager_id)
    {
        Manager temp_manager(manager_id, "temp", "temp", 0);
        Employee temp_employee(worker_id, "temp", "temp", 0); 
        if(((*this).checkIfManagerExist(manager_id)) == false){
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

    void Workplace::fireManager (int manager_id)
    {
        Manager temp_manager(manager_id, "temp", "temp", 0);
        if(((*this).checkIfManagerExist(manager_id)) == false){
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

    bool Workplace::checkIfTwoEmployeesWorkTogther (int worker_a_id, int worker_b_id)
    {
        bool cheack_if_employee_a_is_hired = false;
        bool cheack_if_employee_b_is_hired = false;
        vector<Manager*>::iterator ptr_manager_a;
        for(ptr_manager_a = managers.begin(); ptr_manager_a != managers.end(); ++ptr_manager_a){
            if(((**ptr_manager_a).cheackIfEmployeeExist)(worker_a_id) == true){
                cheack_if_employee_a_is_hired = true;
            }
            if(((**ptr_manager_a).cheackIfEmployeeExist)(worker_b_id) == true){
                cheack_if_employee_b_is_hired = true;
            }
        }
        if((cheack_if_employee_a_is_hired == true) && (cheack_if_employee_b_is_hired == true)){
            return true;
        }
        return false;
    }

    bool operator< (const Workplace& workplace_a, const Workplace& workplace_b)
    {
        return workplace_a.getName() < workplace_b.getName();
    }

    bool operator== (const Workplace& workplace_a, const Workplace& workplace_b)
    {
        return workplace_a.getName() == workplace_b.getName();
    }



    ostream& operator<< (ostream& os, const Workplace& workplace) 
    {
        workplace.printLong(os);
        return os;
    }

    Manager* Workplace::findMinimalIdManager () const
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

    Manager* Workplace::findNextManagerToPrint (Manager* last_printed) const
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

    ostream& Workplace::printLong (ostream& os) const
    {
        Manager* print_ptr;
        if(managers.empty() == false){
            os << "Workplace name - " <<getName() << " Groups:" << endl;
            int how_many_to_print = managers.size();
            for(print_ptr = findMinimalIdManager(); how_many_to_print != 0; --how_many_to_print){
                os << "Manager" << " ";
                (*print_ptr).printLong(os);
                print_ptr = findNextManagerToPrint(print_ptr);
            }
            return os;
        }
        os << "Workplace name - " << getName() << endl;
        return os;
    }

}
