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
        Skill getSkill ();
        int getId ();
        int getAddedPoints ();
        Faculty teach (Employee& Employee);
    };
}

#endif /* FACULTY_H */