#ifndef WORKPLACE_H
#define WORKPLACE_H

#include <string>
//#include <fstream>
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
    class WorkPlace {
    private:
        int workplace_id;
        int workers_salary;
        int managers_salary;
        string workplace_name;
        vector<Manager*> managers;
    public:
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
        WorkPlace (int workPlace_id,string workplace_name, int workers_salary, int managers_salary);
        WorkPlace (const WorkPlace& workplace) = default;
        ~WorkPlace () = default;
        int getID () const;
        int gerWorkersSalary() const;
        int getManagersSalary() const; 
        string getName () const;
        bool checkIfManagerExist (int manager_id);
        void hireManager (Manager* manager);
        void fireEmployee (int worker_id, int manager_id);
        void fireManager (int manager_id);
        bool checkIfTwoEmployeesWorkTogther (int worker_a_id, int worker_b_id);
        Manager* findMinimalIdManager () const;
        Manager* findNextManagerToPrint (Manager* last_printed) const;
        ostream& printLong (ostream& os) const;
        friend ostream& operator<< (ostream& os, const WorkPlace& workplace) ;
        friend bool operator< (const WorkPlace& workplace_a, const WorkPlace& workplace_b);
        friend bool operator== (const WorkPlace& workplace_a, const WorkPlace& workplace_b);
    };
}

#endif /* WORKPLACE_H */
