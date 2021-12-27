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
        const Manager temp_manager(manager_id, "temp", "temp", 0);
        
        if (temp_manager == *(managers.find(temp_manager))){
            return true;
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
        managers.insert(*manager);
    }
            
    void Workplace::fireEmployee (int worker_id, int manager_id)
    {
        Manager temp_manager(manager_id, "temp", "temp", 0);
        if(checkIfManagerExist((manager_id) == false)){
            throw ManagerIsNotHired();
        }
        set<Manager>::iterator it;
        it = managers.find(temp_manager);
        Employee temp_employee(worker_id, "temp", 0, 0); 
        if(((*(it)).cheackIfEmployeeExist(temp_employee)) == false){
            throw EmployeeIsNotHired();
        }
        Manager copy_manager = (*it);
        copy_manager.removeEmployee(worker_id);
        managers.erase(temp_manager);
        managers.insert(copy_manager);
    }

    void Workplace::fireManager (int manager_id)
    {
        Manager temp_manager(manager_id, "temp", "temp", 0);
        if(checkIfManagerExist((manager_id) == false)){
            throw ManagerIsNotHired();
        }
        managers.erase((managers.find(temp_manager)));
    }

    ostream& operator<< (ostream& os, const Workplace& workplace) 
    {
        set<Manager>::iterator print_iterator;
        if(workplace.managers.empty() == false){
            os << "Workplace name - " << workplace.getName() << " Groups:" << endl;
            os << "Manager" << " ";
            for (print_iterator = (workplace.managers).begin(); print_iterator != (workplace.managers).end(); ++print_iterator)
            {
                (*print_iterator).printLong(os);
            }
            return os;
        }
        os << "Workplace name - " << workplace.getName() << endl;
        return os;
    }
}