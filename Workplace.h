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
    class Workplace {
    private:
        int workplace_id;
        int workers_salary;
        int managers_salary;
        string workplace_name;
        vector<shared_ptr<Manager>> managers;
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
            vector<shared_ptr<Manager>>::iterator ptr_managers;
            for(ptr_managers = managers.begin(); ptr_managers != managers.end(); ++ptr_managers){
                if(**ptr_managers == temp_manager){
                    if((*ptr_managers)->cheackIfEmployeeExist(employee) == true){
                        throw EmployeeAlreadyHired();
                    }
                    //(*employee).setSalary(getWorkersSalary());
                    (**ptr_managers).addEmployee(employee);
                }
            }
            
        }
        Workplace (int workplace_id,string workplace_name, int workers_salary, int managers_salary);
        Workplace (const Workplace& workplace) = default;
        ~Workplace () = default;
        int getID () const;
        int gerWorkersSalary() const;
        int getManagersSalary() const; 
        string getName () const;
        bool checkIfManagerExist (int manager_id);
        void hireManager (Manager* manager);
        void fireEmployee (int worker_id, int manager_id);
        void fireManager (int manager_id);
        shared_ptr<Manager> findMinimalIdManager () const;
        shared_ptr<Manager> findNextManagerToPrint (shared_ptr<Manager> last_printed) const;
        ostream& printLong (ostream& os) const;
        friend ostream& operator<< (ostream& os, const Workplace& workplace) ;
        friend bool operator< (const Workplace& workplace_a, const Workplace& workplace_b);
    };
}

#endif /* WORKPLACE_H */
