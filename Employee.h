#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
#include <set>
#include "Skill.h"
#include "Citizen.h"
#include "exceptions.h"

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
        set<Skill> skill_set; 
    public:
        /* Employee C'tor */
        Employee (int id_citizen, string first_name, string last_name, int birth_year); 
        
        /* Employee copy C'tor */
        Employee (const Employee& employee) = default; 
        
        /* Employee D'tor */
        ~Employee () override = default;
        
        /* clone: return copy of existing EmployeeEmployee.
        return-
        Citizen pointer to copy of an existing Employee */
        virtual Employee* clone () const;
        
        /* hasSkill- check if employee has given skill
        return-
        True- if employee haaaaas the skill, otherwise false */
        bool hasSkill (int skill_id) const;
        
        /* getSalary: return Enployee's salary.
        return-
        int salary */
        int getSalary () const override;
        
        /* getScore: return Enployee's score.
        return-
        int score */
        int getScore () const;
        
        /* learnSkill: add given skill to the set of skills of given employee
        return-
        SkillAlreadyLearned- in case that employee already has the skill 
        CanNotLearnSkill- in case that given emmployee cant learn skill due to lower points than needed togain the skill*/
        void learnSkill (const Skill& skill);
        
        /* forgetSkill: remove given skill from the set of skills of given employee
        return-
        DidNotLearnSkill- in case that we try to forget skiil the employee dont have */
        void forgetSkill (const int id_skill);
        
        /* setSalary- raise the salary of the Employee by given amount
        return-
        void function*/
        void setSalary (int salary_to_add);
        
        /* setScore- raise the score of the Employee by given amount
        return-
        void function*/
        void setScore (int score_to_add);
        
        /* printShort- print short information of the Employee by given format */
        ostream& printShort (ostream& os) const override;
        
        /* printShort- print long information of the Employee by given format */
        ostream& printLong (ostream& os) const override;
    };
}
#endif /* EMPLOYEE_H */
