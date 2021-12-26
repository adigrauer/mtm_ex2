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
        Employee(int id_citizen, string first_name, string last_name, int birth_year); 
        ~Employee () = default;
        virtual Citizen* clone () const;
        int getSalary () const;
        int getScore () const;
        void learnSkill (const Skill& skill);
        void forgetSkill (const int id_skill);
        bool hasSkill (const int id_skill);
        void setSalary (int salary_to_add);
        void setScore (int score_to_add);
        ostream& printShort (ostream& os) override;
        ostream& printLong (ostream& os) override;
    };
}
#endif /* EMPLOYEE_H */

//employee can work in few places