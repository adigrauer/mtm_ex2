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
using std::dynamic_pointer_cast;
using std::cout;
using std::endl;

namespace mtm {
    class City {
    private:
        string city_name;
        vector<shared_ptr<Citizen>> citizens;
        vector<Faculty<Condition>> faculties;
        vector<Workplace> workplaces;
    public:
        /* City C'tor */
        City (const string city_name);

        /* City copy C'tor */
        City (const City& city);

        /* City virtual D'tor */
        ~City () = default;

        /* getName: return copy of City's name.
        return-
        string name */
        string getName () const;

        /* checkIfCitizenExistInCity: cheack if citizen exist by id
        return-
        true if exist, otherewise false */
        bool checkIfCitizenExistInCity (int id_citizen);

        /* checkIfEmployeeExistInCity: cheack if employee exist by id
        return-
        true if exist, otherewise false */
        bool checkIfEmployeeExistInCity (int id_citizen);

        /* addEmployee: add employee to the city
        return-
        EmployeeAlreadyExists- in case that employee already exist in given city */
        void addEmployee (int id_citizen, string first_name, string last_name, int birth_year);
        
        /* checkIfManagerExistInCity: cheack if manager exist by id
        return-
        true if exist, otherewise false */
        bool checkIfManagerExistInCity (int id_citizen);
        
        /* addManager: add manager to the city
        return-
        ManagerAlreadyExists- in case that manager already exist in given city */
        void addManager (int id_citizen, string first_name, string last_name, int birth_year);
        
        /* addFaculty: add faculty to the city
        return-
        FacultyAlreadyExists- in case that faculty already exist in given city */
        void addFaculty (int faculty_id, Skill skill, int point_to_add, Condition* compare_function);       
        
        /* checkIfWorkplaceExistInCity: cheack if workplace exist by id
        return-
        true if exist, otherewise false */
        bool checkIfWorkplaceExistInCity (int workplace_id);
        
        /* createWorkPlace: add workplace to the city
        return-
        WorkplaceAlreadyExists- in case that workplace already exist in given city */
        void createWorkplace (int workplace_id, string workplace_name, int workers_salary, int managers_salary);
        
        /* findFacultybById: find specific faculty by id
        return-
        referance to specific faculty */
        Faculty<Condition>& findFacultybById (int faculty_id);
        
        /* teachAtFaculty: teach employee skiil that learned in the faculty if stans the consition to learn,
        and has enougth points to gain the skill
        return-
        EmployeeDoesNotExist- in case that employee does not exist in given city
        FacultyDoesNotExist- in case that faculty does not exist in given city */
        void teachAtFaculty (int employee_id, int faculty_id);
        
        /* findWorkplaceById: find specific workplace by id
        return-
        referance to specific workplace */
        Workplace& findWorkplaceById (int workplace_id);
        
        /* findManagerByIdInCity: find specific manager by id
        return-
        referance to specific manager */
        Manager* findManagerByIdInCity (int manager_id);
        
        /* findEmployeeByIdInCity: find specific employee by id
        return-
        referance to specific employee */
        Employee* findEmployeeByIdInCity (int employee_id);
        
        /* generic function hireEmployeeAtWorkplace: hire employee to given workplace under specific manager 
        return-
        EmployeeDoesNotExist- in case that employee does not exist in given city
        ManagerDoesNotExist- in case that manager does not exist in given city 
        WorkplaceDoesNotExist- in case that workplace does not exist in given city */
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
            findWorkplaceById(workplace_id).hireEmployee(condition_to_hire, findEmployeeByIdInCity(employee_id), manager_id);
        }
        
        /* hireManagerAtWorkplace: hire manager to given workplace.
        return-
        ManagerDoesNotExist- in case that manager does not exist in given city 
        WorkplaceDoesNotExist- in case that workplace does not exist in given city */
        void hireManagerAtWorkplace (int manager_id, int workplace_id);
        
        /* fireEmployeeAtWorkplace: fire employee from given workplace under specific manager 
        return-
        EmployeeDoesNotExist- in case that employee does not exist in given city
        ManagerDoesNotExist- in case that manager does not exist in given city 
        WorkplaceDoesNotExist- in case that workplace does not exist in given city */
        void fireEmployeeAtWorkplace (int employee_id, int manager_id, int workplace_id);
        
        /* fireManagerAtWorkplace: fire manager from given workplace.
        return-
        ManagerDoesNotExist- in case that manager does not exist in given city 
        WorkplaceDoesNotExist- in case that workplace does not exist in given city */
        void fireManagerAtWorkplace (int manager_id, int workplace_id);
        
        /* isWorkingInTheSameWorkplace: cheacking if two employees working together in the same workplace
        return-
        true if working together, otherewise false */
        bool isWorkingInTheSameWorkplace (int worker_a_id, int worker_b_id);
        
        /* helping function to find the minimal and next citizen to print, arranged by id */
        const Citizen* findMinimalIdCitizenWithSalary (int salary) const;
        const Citizen* findNextCitizenWithSalary (const Citizen* last_printed, int salary) const;
        
        /* printAllAboveSalary: print all the citizens with salary equal or above given salary
        return- ostream& */
        int getAllAboveSalary (ostream& os, int salary_to_print);
        
        /* helping function to find the minimal and next citizen to print, arranged by id */
        const Employee* findMinimalIdEmployeeWithSkill (int skill_id) const;
        const Employee* findNextEmployeeWithSkill (const Employee* last_printed, int skill_id) const;
        
        /* printAllEmployeesWithSkill: print all the employees with given skill
        return- ostream& */
        ostream& printAllEmployeesWithSkill (ostream& os, int skill_id) const;
    };

}

#endif /* CITY_H */
