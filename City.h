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
        set<Citizen> citizens;
        set<Faculty> fuculties;
        set<Workplace> workplaces;
    public:
        City (const string city_name);
        City addEmployee (int id_citizen, string first_name, string last_name, int birth_year);
        City addManager (int id_citizen, string first_name, string last_name, int birth_year);
        City addFaculty (Skill skill, int point_to_add);
        City createWorkplace (unsigned int workplace_id, unsigned int workers_salary, unsigned int managers_salary, string workplace_name);
    };
}

#endif /* CITY_H */
