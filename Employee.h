#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
//#include <fstream>
#include <iostream>
#include <set>
#include "Skill.h"
#include "Citizen.h"

//are all needed??
using std::ostream;
using std::set;
using std::cout;
using std::endl;
using std::string;

namespace mtm {
    class Employee : public Citizen {
    private:
        int salary;
        int score;
        set<Skill> skill_set;
        Employee(int id_citizen, string first_name, string last_name, int birth_year); 
        virtual Citizen* clone () const;
        int getSalary () const;
        int getScore () const;
    public:
        void learnSkill (const Skill& skill);
        void forgetSkill (const unsigned int id_skill);
        bool hasSkill (const unsigned int id_skill);
        void setSalary (int salary);
        void setScore (int score);
        friend ostream& operator<< (ostream& os, const Employee& employee);
        ostream& printShort (ostream& os) override;
        ostream& printLong (ostream& os) override;
    };
}
#endif /* EMPLOYEE_H */