#include "Workplace.h"

namespace mtm {
    Workplace::Workplace (int workplace_id, string workplace_name, int workers_salary, int managers_salary):
        workplace_id(workplace_id),
        workers_salary(workers_salary),
        managers_salary(managers_salary),
        workplace_name(workplace_name),
        managers()
    {
    }

    int Workplace::getID () const
    {
        return workplace_id;
    }

    int Workplace::gerWorkersSalary() const
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
        vector<shared_ptr<Manager>>::iterator ptr;
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
        //bool cheackIfManagerWorkInOtherPlace (Workplace workplace, unsigned int id_manager)-
        //meed to check if dont need to be in city and not in Worplace class!!!!!!
        //because need access to set<Workplace> workplaces
        manager->setSalary(getManagersSalary());
        Manager* manager1 = new Manager(*manager);
        shared_ptr<Manager> manager_to_add(manager1);
        managers.push_back(manager_to_add);
    }
            
    void Workplace::fireEmployee (int worker_id, int manager_id)
    {
        Manager temp_manager(manager_id, "temp", "temp", 0);
        Employee temp_employee(worker_id, "temp", 0, 0); 
        if(checkIfManagerExist((manager_id) == false)){
            throw ManagerIsNotHired();
        }
        vector<shared_ptr<Manager>>::iterator ptr;
        for(ptr = managers.begin(); ptr != managers.end(); ++ptr){
            if(**ptr == temp_manager){
                if((*ptr)->cheackIfEmployeeExist(worker_id) == false){
                        throw EmployeeIsNotHired();
                }
                vector<shared_ptr<Employee>>::iterator ptr_to_employee;
                (**ptr).setSalary(-workers_salary);
                (**ptr).removeEmployee(worker_id);
                return;
            }
        }
    }

    void Workplace::fireManager (int manager_id)
    {
        Manager temp_manager(manager_id, "temp", "temp", 0);
        if(checkIfManagerExist((manager_id) == false)){
            throw ManagerIsNotHired();
        }
        vector<shared_ptr<Manager>>::iterator ptr;
        for(ptr = managers.begin(); ptr != managers.end(); ++ptr){
            if((**ptr) == temp_manager){
                (**ptr).setSalary(-managers_salary);
                managers.erase(ptr);
                return;
            }
        }
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

    shared_ptr<Manager> Workplace::findMinimalIdManager () const
    {
        vector<shared_ptr<Manager>>::const_iterator iterator;
        shared_ptr<Manager> current_minimal(*(managers.begin()));
        for (iterator = managers.begin(); iterator != managers.end(); ++iterator){
            if ((**iterator).getId() < (*current_minimal).getId()){
                current_minimal = *iterator;
            }
        }
        return current_minimal;
    }

    shared_ptr<Manager> Workplace::findNextManagerToPrint (shared_ptr<Manager> last_printed) const
    {
        vector<shared_ptr<Manager>>::const_iterator iterator = managers.begin();
        shared_ptr<Manager> current_next(last_printed);
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
            else {
                current_next = *iterator;
            }
            return current_next;
        }   
        return current_next;
    }

    ostream& Workplace::printLong (ostream& os) const
    {
        shared_ptr<Manager> print_ptr;
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