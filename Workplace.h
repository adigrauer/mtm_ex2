#ifndef WORKPLACE_H
#define WORKPLACE_H

#include <string>
//#include <fstream>
#include <iostream>
#include <set>
#include "Manager.h"
#include "Citizen.h"

//are all needed??
using std::ostream;
using std::set;
using std::cout;
using std::endl;
using std::string;

namespace mtm {
    class Workplace {
    private:
        int workplace_id;
        int workers_salary;
        int managers_salary;
        string workplace_name;
        set<Manager> managers;
    public:
        template <typename condition> 
        void hireEnployee(condition condition_to_check, Employee* employee, int manager_id){
            if(condition_to_check(Employee) == false){
                throw EmployeeNotSelected();
            }
            if(checkIfManagerExist(manager_id) == false){
                throw ManagerIsNotHired();
            }
            Manager temp_manager(manager_id, "temp", "temp", 0);
            set<Manager>::iterator pointer_to_mamanger = managers.find(temp_manager);
            if((*pointer_to_mamanger).cheackIfEmployeeExist(*employee) == true){
                throw EmployeeAlreadyHired();
            }
        }
        Workplace (int workplace_id, int workers_salary, int managers_salary, string workplace_name);
        Workplace (const Workplace& workplace) = default;
        ~Workplace () = default;
        int getID () const;
        int gerWorkersSalary() const;
        int getManagersSalary() const; 
        string getName () const;
        bool checkIfManagerExist (int manager_id);
        void hireManager (Manager* manager);
            //bool cheackIfManagerExist (Workplace workplace, unsigned int id_manager);
            //bool cheackIfManagerWorkInOtherPlace (Workplace workplace, unsigned int id_manager);
        void fireEmployee (int worker_id, int manager_id);
        void fireManager (int manager_id);
        friend ostream& operator<< (ostream& os, const Skill& skill);
    };
}

#endif /* WORKPLACE_H */
