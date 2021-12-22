#ifndef MANAGER_H
#define MANAGER_H

#include <string>
//#include <fstream>
#include <iostream>
#include <set>
#include "skill.h"
#include "citizen.h"
#include "employee.h"

//are all needed??
using std::ostream;
using std::set;
using std::cout;
using std::endl;
using std::string;

namespace mtm {
    class Manager {
    private:
        int salary;
        set<Employee> employyes;
    public:
        Manager (int id_citizen, string first_name, string last_name, int birth_year);
        int getSalary ();
        Manager* clone ();
        void addEmployee (const Employee* employee);
        void removeEmployee (const unsigned int id_employee);
        void setSalary (unsigned int salary);
        friend ostream& operator<< (ostream& os, const Manager& employee);
    };
    ostream& printShort (ostream& os);
    ostream& printLong (ostream& os);
}

#endif /* MANAGER_H */