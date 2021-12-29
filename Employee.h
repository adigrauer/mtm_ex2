#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
#include <set>
#include "Skill.h"
#include "Citizen.h"
#include "exception.h"

//are all needed??
using std::ostream;
using std::set;
using std::cout;
using std::endl;
using std::string;

namespace mtm {
    /* const declerations */
    const int STARTING_SALARY = 0;
    const int STARTING_SCORE = 0;

    class Employee : public Citizen { 
    private:
        int salary;
        int score;
        set<Skill> skill_set; //print skills by id
    public:
        /*class CompareEmployee {
        public:
            bool operator() (shared_ptr<Employee> employee_a, shared_ptr<Employee> employee_b){
                return(employee_a->getId() == employee_b->getId());
            }
        };*/
        Employee (int id_citizen, string first_name, string last_name, int birth_year); 
        Employee (const Employee& employee) = default; 
        ~Employee () override = default;
        virtual Citizen* clone () const;
        int getSalary () const;
        int getScore () const;
        void learnSkill (const Skill& skill);
        void forgetSkill (const int id_skill);
        bool checkIfEmployeeHasSkill (const int id_skill);
        void setSalary (int salary_to_add);
        void setScore (int score_to_add);
        ostream& printShort (ostream& os) const override;
        ostream& printLong (ostream& os) const override;
    };
}
#endif /* EMPLOYEE_H */

//employee can work in few places