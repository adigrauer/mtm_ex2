#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include <iostream>
#include "Skill.h"
#include "Citizen.h"
#include "Employee.h"

//are all needed??
using std::ostream;
using std::set;
using std::cout;
using std::endl;
using std::string;

namespace mtm {
    typedef bool (*compareFunction)(Employee);
    class Faculty {
    private:
        Skill skill;
        int faculty_id; //need to add to constructor
        int add_points;
        compareFunction compare_function;
    public:
        Faculty (compareFunction compare_function, Skill skill, int point_to_add, int faculty_id);
        Faculty (const Faculty& faculty) = default;
        ~Faculty() = default;
        Skill getSkill ();
        int getId ();
        int getId () const;
        int getAddedPoints ();
        void teach (Employee* employee); //does teach gets pointer of employee??
        friend bool operator< (const Faculty& faculty_a, const Faculty& faculty_b);
        friend bool operator== (const Faculty& faculty_a, const Faculty& faculty_b);
    };
}

#endif /* FACULTY_H */