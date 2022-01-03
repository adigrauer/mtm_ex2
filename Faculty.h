#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include <iostream>
#include "Skill.h"
#include "Citizen.h"
#include "Employee.h"

using std::ostream;
using std::set;
using std::cout;
using std::endl;
using std::string;

namespace mtm {
    template<typename Condition>
    class Condtion{
    public:
        virtual bool operator()(Employee* employee) = 0;
    };
    
    //typedef bool (*compareFunction)(Employee);
    typedef bool (*compareFunction)(Employee*);
    class Faculty {
    private:
        Skill skill;
        int faculty_id; 
        int add_points;
        //compareFunction compare_function;
    public:

        /* Faculty C'tor */
        Faculty (compareFunction compare_function, Skill skill, int point_to_add, int faculty_id);
        
        /* Faculty copy C'tor */
        Faculty (const Faculty& faculty) = default;
        
        /* Faculty virtual D'tor */
        ~Faculty() = default;
        
        /* getSkill: return Faculty's skill.
        return-
        Skill skill */
        Skill getSkill ();
        
        /* getId: return faculty's id from faculty.
        return-
        int id */
        int getId ();
        
        /* getId: return faculty's id from const faculty.
        return-
        int id */
        int getId () const;
        
        /* getAddedPoints: return faculty's added pointes.
        return-
        int added points */
        int getAddedPoints ();
        
        /* teach: teach emmployee the skill that learned in the faculty if stants the condition for learning
        return-
        EmployeeNotAccepted - in case that employee dont exist the condition, therefore cant learn the skiil of given faculty */
        void teach (Employee* employee); //does teach gets pointer of employee??
        
        /* friens bool operators */
        friend bool operator< (const Faculty& faculty_a, const Faculty& faculty_b);
        friend bool operator== (const Faculty& faculty_a, const Faculty& faculty_b);
    };
}

#endif /* FACULTY_H */