#include "Workplace.h"

namespace mtm {
    Workplace::Workplace (int workplace_id, int workers_salary, int managers_salary, string workplace_name):
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
        Manager temp_manager(manager_id, "temp", "temp", 0);
        
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
        Employee temp_employee(worker_id, "temp", 0, 0); 
        if(((*(managers.find(temp_manager))).cheackIfEmployeeExist(temp_employee)) == false){
            throw EmployeeIsNotHired();
        }
        /*************/
        /*************/
        (*(managers.find(temp_manager))).removeEmployee(worker_id);
        //I think the problem is thar find returns const iterator
        /*************/
        /*************/
    }

    void Workplace::fireManager (int manager_id)
    {
        Manager temp_manager(manager_id, "temp", "temp", 0);
        if(checkIfManagerExist((manager_id) == false)){
            throw ManagerIsNotHired();
        }
        managers.erase((managers.find(temp_manager)));
    }

    //ostream& operator<< (ostream& os, const Skill& skill);

}