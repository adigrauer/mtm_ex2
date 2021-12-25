#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
//#include <fstream>
#include <iostream>
#include <set>
#include "Skill.h"
#include "Citizen.h"
#include "Faculty.h"
#include "exception.h"
//are all needed??
using std::ostream;
using std::set;
using std::cout;
using std::endl;
using std::string;

namespace mtm {
    class Employee : public Citizen {
        /* const declerations */
    const int STARTING_SALARY = 0;
    const int STARTING_SCORE = 0;
    private:
        int salary;
        int score;
        set<Skill> skill_set;
    public:
        Employee(int id_citizen, string first_name, string last_name, int birth_year); 
        ~Employee ();
        virtual Citizen* clone () const;
        int getSalary () const;
        int getScore () const;
        void learnSkill (const Skill& skill);
        void forgetSkill (const unsigned int id_skill);
        bool hasSkill (const unsigned int id_skill);
        void setSalary (int salary_to_add);
        void setScore (int score_to_add);
        ostream& printShort (ostream& os) override;
        ostream& printLong (ostream& os) override;
    };
}
#endif /* EMPLOYEE_H */