#ifndef CITY_H
#define CITY_H

#include <string>
#include <iostream>
#include <set>
//#include <memory> can we use this include to write using shared_ptr

#include "Manager.h"
#include "Faculty.h"
#include "Workplace.h"
#include "Citizen.h"
#include "Employee.h"
#include "Skill.h"

//are all needed??
using std::ostream;
using std::set;
using std::cout;
using std::endl;
using std::string;
//using std::shared_ptr;

namespace mtm {
    class City {
    private:
        string city_name;
        //vector<shared_ptr<Citizen>> citizens;
        set<Employee> employees;
        set<Manager> managers;
        set<Faculty> faculties;
        set<Workplace> workplaces;
    public:
        City (const string city_name);
        void addEmployee (int id_citizen, string first_name, string last_name, int birth_year);
        void addManager (int id_citizen, string first_name, string last_name, int birth_year);
        void addFaculty (Skill skill, int point_to_add);
        void createWorkplace (int workplace_id, int workers_salary, int managers_salary, string workplace_name);
        void teachAtFaculty (int employee_id, int faculty_id);
        void hireEmployeeAtWorkplace (/* condition function, */ int employee_id, int manager_id, int workplace_id);
        void hireManagerAtWorkplace (int manager_id, int workplace_id);
        void fireEmployeeAtWorkplace (/* condition function, */ int employee_id, int manager_id, int workplace_id);
        void fireManagerAtWorkplace (int manager_id, int workplace_id);
        ostream& getAllAboveSalary (ostream&, int salary_to_print);
    };
}

#endif /* CITY_H */
