#ifndef CITY_H
#define CITY_H

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <memory> 

#include "Manager.h"
#include "Faculty.h"
#include "WorkPlace.h"
#include "Citizen.h"
#include "Employee.h"
#include "Skill.h"

using std::ostream;
using std::set;
using std::vector;
using std::string;
using std::shared_ptr;
using std::dynamic_pointer_cast;
using std::cout;
using std::endl;

namespace mtm {
    class City {
    private:
        string city_name;
        vector<shared_ptr<Citizen>> citizens;
        vector<Faculty> faculties;
        vector<WorkPlace> workplaces;
    public:
        City (const string city_name);
        City (const City& city);
        ~City () = default;
        string getName () const;
        bool checkIfEmployeeExistInCity (int id_citizen);
        void addEmployee (int id_citizen, string first_name, string last_name, int birth_year);
        bool checkIfManagerExistInCity (int id_citizen);
        void addManager (int id_citizen, string first_name, string last_name, int birth_year);
        void addFaculty (int faculty_id, Skill skill, int point_to_add, compareFunction compare_function);       
        bool checkIfWorkplaceExistInCity (int workplace_id);
        void createWorkPlace (int workplace_id, string workplace_name, int workers_salary, int managers_salary);
        Faculty& findFacultybById (int faculty_id);
        void teachAtFaculty (int employee_id, int faculty_id);
        WorkPlace& findWorkplaceById (int workplace_id);
        Manager* findManagerByIdInCity (int manager_id);
        Employee* findEmployeeByIdInCity (int employee_id);
        template <typename condition> 
        void hireEmployeeAtWorkplace (condition condition_to_hire, int employee_id, int manager_id, int workplace_id)
        {
            if(checkIfEmployeeExistInCity(employee_id) == false){
                throw EmployeeDoesNotExist();
            }
            if(checkIfManagerExistInCity(manager_id) == false){
                throw ManagerDoesNotExist();
            }
            if(checkIfWorkplaceExistInCity(workplace_id) == false){
                throw WorkplaceDoesNotExist();
            }
            WorkPlace workplace_to_add_employee = findWorkplaceById(workplace_id);
            Employee* employee_to_hire = findEmployeeByIdInCity(employee_id);
            workplace_to_add_employee.hireEmployee(condition_to_hire, employee_to_hire, manager_id);
        }
        void hireManagerAtWorkplace (int manager_id, int workplace_id);
        void fireEmployeeAtWorkplace (int employee_id, int manager_id, int workplace_id);
        void fireManagerAtWorkplace (int manager_id, int workplace_id);
        bool isWorkingInTheSameWorkplace (int worker_a_id, int worker_b_id);
        const Citizen* findMinimalIdCitizenWithSalary (int salary) const;
        const Citizen* findNextCitizenWithSalary (const Citizen* last_printed, int salary) const;
        ostream& printAllAboveSalary (ostream& os, int salary_to_print);
        const Employee* findMinimalIdEmployeeWithSkill (int skill_id) const;
        const Employee* findNextEmployeeWithSkill (const Employee* last_printed, int skill_id) const;
        ostream& printAllEmployeesWithSkill (ostream& os, int skill_id) const;
    };
}

#endif /* CITY_H */
