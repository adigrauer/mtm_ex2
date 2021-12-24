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
        unsigned int workplace_id;
        unsigned int workers_salary;
        unsigned int managers_salary;
        string workplace_name;
        set<Citizen*> manager;
        class Condition {
        private:
            int condition_to_comapre;
        public:
            Condition (int condition);
            bool operator() (int condition) const;
        };
    public:
        Workplace (unsigned int workplace_id, unsigned int workers_salary, unsigned int managers_salary, string workplace_name);
        unsigned int getId ();
        unsigned int gerWorkersSalary(); 
        string getName ();
        Workplace hireManager (Manager* manager);
            //bool cheackIfManagerExist (Workplace workplace, unsigned int id_manager);
            //bool cheackIfManagerWorkInOtherPlace (Workplace workplace, unsigned int id_manager);
        //hireEmployee
        Workplace hireEmployee (/* function */ Employee* employee, unsigned int manager_id);
        Workplace fireEmployee (unsigned int worker_id, unsigned int manager_id);
        Workplace fireManager (unsigned int manager_id);
        friend ostream& operator<< (ostream& os, const Skill& skill);
    };
}

#endif /* WORKPLACE_H */