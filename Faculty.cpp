#include "Faculty.h"
#include "Skill.h"

namespace mtm {
    Faculty::Faculty (compareFunction compare_function, Skill skill, int point_to_add, int faculty_id):
        compare_function(compare_function),
        skill(skill),
        add_points(point_to_add),
        faculty_id(faculty_id)
    {
    }

    Skill Faculty::getSkill ()
    {
        return skill;
    }

    int Faculty::getId ()
    {
        return faculty_id;
    }

    int Faculty::getAddedPoints ()
    {
        return add_points;
    }

    /////does faculty gerts referance or pointer???????
    void Faculty::teach (Employee* employee)
    {
        if(compare_function((*employee)) == false){
            //throw EmployeeNotAccepted();
        }
        (*employee).learnSkill(skill); 
        /////////if learnSkill passed than we will add score, doest this implementation right?
        (*employee).setScore(add_points);
    }

}