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

    class Condition{
    public:
        virtual bool operator()(Employee* employee) = 0;
    };

    template<typename T>
    class Faculty {
    private:
        Skill skill;
        int faculty_id; 
        int add_points;
    public:
        T* compare_function;
        /* Faculty C'tor */
        Faculty (int faculty_id, Skill skill, int point_to_add, T* compare_function);
        
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
        //template<typename T>
        friend bool operator< (const Faculty<T>& faculty_a, const Faculty<T>& faculty_b)
        {
            return faculty_a.getId() < faculty_b.getId();
        }

        //template<typename T>
        friend bool operator== (const Faculty<T>& faculty_a, const Faculty<T>& faculty_b)
        {
        return faculty_a.getId() == faculty_b.getId();
        }
    };

    template<typename T>
    Faculty<T>::Faculty (int faculty_id, Skill skill, int point_to_add, T* compare_function):
        skill(skill),
        faculty_id(faculty_id),
        add_points(point_to_add),
        compare_function(compare_function)
    {
    }

    template<typename T>
    Skill Faculty<T>::getSkill ()
    {
        return skill;
    }

    template<typename T>
    int Faculty<T>::getId () const 
    {
        return faculty_id;
    }

    template<typename T>
    int Faculty<T>::getId () 
    {
        return faculty_id;
    }

    template<typename T>
    int Faculty<T>::getAddedPoints ()
    {
        return add_points;
    }

    template<typename T>
    void Faculty<T>::teach (Employee* employee)
    {
        if((*compare_function)(employee) == false){
            throw EmployeeNotAccepted();
        }
        (*employee).learnSkill(skill); 
        (*employee).setScore(add_points);
    }

}

#endif /* FACULTY_H */