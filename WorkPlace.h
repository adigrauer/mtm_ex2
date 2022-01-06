#ifndef WORKPLACE_H
#define WORKPLACE_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Manager.h"
#include "Citizen.h"

//are all needed??
using std::ostream;
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;

namespace mtm {
    /* WorkPlace class declaration */
    class Workplace {
    private:
        int workplace_id;
        int workers_salary;
        int managers_salary;
        string workplace_name;
        vector<Manager*> managers;
    public:
        /* hireEmployee- add new Employee to the vector of employees of the Manager by pointer to the employee in given workplace.
        return-
        EmployeeNotSelected-employee dont exist the condition, therefore cant be hired by given workplace
        ManagerIsNotHired- in case we try to hire employee by manager that does not exist in given workplace
        EmployeeAlreadyHired- in case that manager already hired in given workplace */
        template <typename condition> 
        void hireEmployee(condition condition_to_check, Employee* employee, int manager_id){
            if(condition_to_check(employee) == false){
                throw EmployeeNotSelected();
            }
            if(checkIfManagerExist(manager_id) == false){
                throw ManagerIsNotHired();
            }
            Manager temp_manager(manager_id, "temp", "temp", 0);
            vector<Manager*>::iterator ptr_managers;
            for(ptr_managers = managers.begin(); ptr_managers != managers.end(); ++ptr_managers){
                if((**ptr_managers) == temp_manager){
                    int employee_id = (*employee).getId();
                    if(((*ptr_managers)->cheackIfEmployeeExist(employee_id)) == true){
                        throw EmployeeAlreadyHired();
                    }
                    (*employee).setSalary(workers_salary);
                    (*ptr_managers)->addEmployee(employee);
                }
            }
            
        }
        
        /* WorkPlace C'tor */
        Workplace (int workplace_id,string workplace_name, int workers_salary, int managers_salary);
        
        /* WorkPlace copy C'tor */
        Workplace (const Workplace& workplace) = default;
        
        /* WorkPlace D'tor */
        //~Workplace () = default;
        ~Workplace () = default;

        /* getId: return WorkPlace's id.
        return-
        int id */
        int getId () const;
        
        /* getWorkersSalary: return WorkPlace workers salary.
        return-
        int workers salary */
        int getWorkersSalary() const;
        
        /* getManagersSalary: return WorkPlace managers salary.
        return-
        int managers salary */
        int getManagersSalary() const; 
        
        /* getName: return WorkPlace name.
        return-
        string workplace name */
        string getName () const;
        
        /* checkIfManagerExist- check if manager is already work in given workplace
        return-
        True- if the manager is already hired
        False- otherwise*/
        bool checkIfManagerExist (int manager_id);
        
        /* hireManager- add new Manager to the vector of managerss of workplace by pointer to the manager.
        return-
        ManagerAlreadyHired- in case that manager already hired in given workplace
        CanNotHireManager- in case that given manager already works in different workplace */
        void hireManager (Manager* manager);
        
        /* fireEmployee- fire employee from workplace under given manager
        return-
        EmployeeNotHired- in case that the employee does not a worker of the given manager.
        ManagerIsNotHired- in case we try to hire employee by manager that does not exist in given workplace */
        void fireEmployee (int worker_id, int manager_id);
        
        /* fireManager- fire manager from workplace
        return-
        ManagerIsNotHired- in case we try to hire employee by manager that does not exist in given workplace */
        void fireManager (int manager_id);
        
        /* checkIfTwoEmployeesWorkTogther- check if two employees work together in given workplace
        return-
        True- if the two employees wirk together at workplace
        False- otherwise*/
        bool checkIfTwoEmployeesWorkTogther (int worker_a_id, int worker_b_id);
        
        /* helping function to find the minimal and next manager to print in workplace, arranged by id */
        Manager* findMinimalIdManager () const;
        Manager* findNextManagerToPrint (Manager* last_printed) const;
        
        /* printShort- print long information of the workplace by given format */
        ostream& printLong (ostream& os) const;
        
        /* friens unary operators, overload operator << */
        friend ostream& operator<< (ostream& os, const Workplace& workplace) ;
        
        /* friens bool operators */
        
        friend bool operator< (const Workplace& workplace_a, const Workplace& workplace_b);
        friend bool operator== (const Workplace& workplace_a, const Workplace& workplace_b);
    };
}

#endif /* WORKPLACE_H */
