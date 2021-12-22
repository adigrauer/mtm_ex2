#ifndef WORKPLACE_H
#define WORKPLACE_H

#include <string>
//#include <fstream>
#include <iostream>
#include <set>
#include "manager.h"
#include "citizen.h"

//are all needed??
using std::ostream;
using std::set;
using std::cout;
using std::endl;
using std::string;

namespace mtm {
    class Workplace {
    private:
        unsigned int id_workplace;
        unsigned int workers_salary;
        unsigned int managers_salary;
        string workplace_name;
        set<Manager> manager;
    public:
        Workplace (unsigned int id_workplace, unsigned int workers_salary, unsigned int managers_salary, string workplace_name);
        unsigned int getId ();
        unsigned int gerWorkersSalary(); 
        string hetName ();
    };
}

#endif