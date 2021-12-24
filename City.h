#ifndef CITY_H
#define CITY_H

#include <string>
#include <fstream>
#include <iostream>
#include <set>
#include "Manager.h"
#include "Faculty.h"
#include "Workplace.h"
#include "Citizen.h"
#include "Employee.h"

//are all needed??
using std::ostream;
using std::set;
using std::cout;
using std::endl;
using std::string;

namespace mtm {
    class City {
    private:
        string city_name;
        set<Citizen*> citizens;
        set<Faculty> fuculties;
        set<Workplace> workplaces;
    public:
        City (const string city_name);
        void addEmployee (int id_citizen, string first_name, string last_name, int birth_year);
        void addManager (int id_citizen, string first_name, string last_name, int birth_year);
        void addFaculty (Skill skill, int point_to_add);
        void createWorkplace (unsigned int workplace_id, unsigned int workers_salary, unsigned int managers_salary, string workplace_name);
        void teachAtFaculty (unsigned int employee_id, unsigned int faculty_id);
        void hireEmployeeAtWorkplace (/* condition function, */ unsigned int employee_id, unsigned int manager_id, unsigned int workplace_id);
        void hireManagerAtWorkplace (unsigned int manager_id, unsigned int workplace_id);
        void fireEmployeeAtWorkplace (/* condition function, */ unsigned int employee_id, unsigned int manager_id, unsigned int workplace_id);
        void fireManagerAtWorkplace (unsigned int manager_id, unsigned int workplace_id);
        ostream& getAllAboveSalary (ostream&, unsigned int salary_to_print);
    };
}

#endif /* CITY_H */
