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
        set<Manager> manager;
    public:
        template <typename condition> 
        void hireEnployee(condition cond, Employee* employee, int manager_id){
            if(!(cond(Employee){
                throw EmployeeNotSelected();
            }
        }
        Workplace (int workplace_id, int workers_salary, int managers_salary, string workplace_name);
        int getId () const;
        int gerWorkersSalary(); 
        string getName ();
        Workplace hireManager (Manager* manager);
            //bool cheackIfManagerExist (Workplace workplace, unsigned int id_manager);
            //bool cheackIfManagerWorkInOtherPlace (Workplace workplace, unsigned int id_manager);
        //hireEmployee
        Workplace hireEmployee (/* function */ Employee* employee, int manager_id);
        Workplace fireEmployee (int worker_id, int manager_id);
        Workplace fireManager (int manager_id);
        friend ostream& operator<< (ostream& os, const Skill& skill);
    };
}

#endif /* WORKPLACE_H */
