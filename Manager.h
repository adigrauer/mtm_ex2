#ifndef MANAGER_H
#define MANAGER_H

#include <string>
//#include <fstream>
#include <iostream>
#include <vector>
#include <memory>
#include "Skill.h"
#include "Citizen.h"
#include "Employee.h"

//are all needed??
using std::ostream;
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;

namespace mtm {

    /* const declerations */
    const int STARTING_SALARY_MANAGER = 0;

    /* Manager class declaration */
    class Manager : public Citizen {
    private:
        int salary;
        vector<shared_ptr<Employee>> employees;
    public:
        class Compare{
        public:
            bool operator() (shared_ptr<Manager> citizen_a, shared_ptr<Manager> citizen_b){
                return(citizen_a->getId() == citizen_b->getId());
            }
        };
        /* Manager C'tor */
        Manager (int id_citizen, string first_name, string last_name, int birth_year);
        
        /* Manager copy C'tor */
        Manager (const Manager& manager) = default;
        
        /* Manager D'tor */
        ~Manager () override = default;

        /* getSalary: return copy of Manager's salary.
        return-
        int salary */
        int getSalary () const;

        /* clone: return copy of existing Manager.
        return-
        Citizen pointer to copy of an existing Manager */
        virtual Citizen* clone () const;

        /* cheackIfEmployeeExist- check if employee is already work under given manager
        return-
        True- if the employee is already hired
        False- otherwise*/
        bool cheackIfEmployeeExist (Employee* employee);

        /* addEmployee- add new Employee the the set of employees of the Manager by pointer the the employee.
        return-
        EmployeeAlreadyHired- in case that the employee already exist in the Manager employees.*/
        void addEmployee (Employee* employee);

        /* removeEmployee- remove employee fron the employees of given manager by employee's id
        return-
        EmployeeNotHired- in case that the employee does not a worker of the given manager.*/
        void removeEmployee (int employee_id);
        
        /* setSalary- raise the salary of the Manager by given amount
        return-
        void function*/
        void setSalary (int salary_to_add);
        
        /* printShort- print short information of the Manager by given format */
        ostream& printShort (ostream& os) const override;
        
        /* printShort- print long information of the Manager by given format */
        ostream& printLong (ostream& os) const override;

        shared_ptr<Employee> findMinimalIdEmployee () const;
        shared_ptr<Employee> findNextEmployeeToPrint (shared_ptr<Employee> last_printed) const;
    };

}

#endif /* MANAGER_H */