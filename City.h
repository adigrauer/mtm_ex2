#ifndef CITY_H
#define CITY_H

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <memory> 

#include "Manager.h"
#include "Faculty.h"
#include "Workplace.h"
#include "Citizen.h"
#include "Employee.h"
#include "Skill.h"

using std::ostream;
using std::set;
using std::vector;
using std::string;
using std::shared_ptr;
using std::cout;
using std::endl;

namespace mtm {
    class City {
    private:
        string city_name;
        vector<shared_ptr<Citizen>> citizens;
        set<Faculty> faculties;
        set<Workplace> workplaces;
    public:
        City (const string city_name);
        //City (const City& city);
        ~City () = default;
        void addEmployee (int id_citizen, string first_name, string last_name, int birth_year);
        void addManager (int id_citizen, string first_name, string last_name, int birth_year);
        void addFaculty (compareFunction compare_function, Skill skill, int point_to_add, int faculty_id);
        void createWorkplace (int workplace_id, string workplace_name, int workers_salary, int managers_salary);
        void teachAtFaculty (int employee_id, int faculty_id);
        void hireEmployeeAtWorkplace (/* condition function, */ int employee_id, int manager_id, int workplace_id);
        void hireManagerAtWorkplace (int manager_id, int workplace_id);
        void fireEmployeeAtWorkplace (/* condition function, */ int employee_id, int manager_id, int workplace_id);
        void fireManagerAtWorkplace (int manager_id, int workplace_id);
        ostream& getAllAboveSalary (ostream&, int salary_to_print);
        bool isWorkingInTheSameWorkplace (int worker_a_id, int worker_b_id);
        void printAllEmployeesWithSkill (ostream& os) const;
        Faculty& findFacultybById (int id);
    };
}

#endif /* CITY_H */
