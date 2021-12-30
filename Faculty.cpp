#include "Faculty.h"
#include "Skill.h"

namespace mtm {
    Faculty::Faculty (compareFunction compare_function, Skill skill, int point_to_add, int faculty_id):
        skill(skill),
        faculty_id(faculty_id),
        add_points(point_to_add),
        compare_function(compare_function)
    {
    }

    Skill Faculty::getSkill ()
    {
        return skill;
    }

    int Faculty::getId () const 
    {
        return faculty_id;
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
        //if(compare_function((*employee)) == false){
        if(compare_function((employee)) == false){
            throw EmployeeNotAccepted();
        }
        (*employee).learnSkill(skill); 
        /////////if learnSkill passed than we will add score, doest this implementation right?
        (*employee).setScore(add_points);
    }

    bool operator< (const Faculty& faculty_a, const Faculty& faculty_b) 
    {
        return faculty_a.getId() < faculty_b.getId();
    }

    bool operator== (const Faculty& faculty_a, const Faculty& faculty_b)
    {
        return faculty_a.getId() == faculty_b.getId();
    }
    
}