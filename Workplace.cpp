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
        vector<shared_ptr<Manager>>::iterator ptr = managers.begin();
        shared_ptr<Manager> manager_to_add(manager);
        managers.insert(ptr, manager_to_add);
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
                if((*ptr)->cheackIfEmployeeExist(&temp_employee) == false){
                        throw EmployeeAlreadyHired();
                }
                (**ptr).removeEmployee(worker_id);
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
            if(**ptr == temp_manager){
                managers.erase(ptr);
            }
        }
    }

    bool operator< (const Workplace& workplace_a, const Workplace& workplace_b)
    {
        return workplace_a.getName() < workplace_b.getName();
    }

    ostream& operator<< (ostream& os, const Workplace& workplace) 
    {
        shared_ptr<Manager> print_ptr;
        if(workplace.managers.empty() == false){
            os << "Workplace name - " << workplace.getName() << " Groups:" << endl;
            os << "Manager" << " ";
            int how_many_to_print = workplace.managers.size();
            for(print_ptr = findMinimalIdManager(workplace); how_many_to_print != 0; --how_many_to_print){
                (*print_ptr).printShort(os);
                print_ptr = findNextManagerToPrint(print_ptr, workplace);
            }
            return os;
        }
        os << "Workplace name - " << workplace.getName() << endl;
        return os;
    }

    shared_ptr<Manager> Workplace::findMinimalIdManager (const Workplace& workplace) 
    {
        vector<shared_ptr<Manager>>::const_iterator iterator;
        shared_ptr<Manager> current_minimal(*(workplace.managers.begin()));
        for (iterator = workplace.managers.begin(); iterator != workplace.managers.end(); ++iterator){
            if ((**iterator).getId() < (*current_minimal).getId()){
                current_minimal = *iterator;
            }
        }
        return current_minimal;
    }

    shared_ptr<Manager> Workplace::findNextManagerToPrint (shared_ptr<Manager> last_printed, const Workplace& workplace) 
    {
        vector<shared_ptr<Manager>>::const_iterator iterator = workplace.managers.begin();
        shared_ptr<Manager> current_next(last_printed);
        while (iterator != workplace.managers.end()){
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