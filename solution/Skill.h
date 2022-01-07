#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <iostream>
#include "exceptions.h"

using std::ostream;
using std::cout;
using std::endl;
using std::string;

namespace mtm {
    /*const declerations*/
    const int ZERO = 0;
    
    /* Skill class declaration */
    class Skill {
    private: 
        int id_skill;
        string name;
        int required_points;
    public:
        /* Skill C'tor */
        Skill(int id_skill, string name, int required_points);
        
        /* Skill copy C'tor */
        Skill(const Skill& skill) = default;
        
        /* Skill D'tor */
        ~Skill () = default;

        /* getId: return copy of skill's id.
        return-
        int id */
        int getId () const;
        
        /* getName: return copy of skill's name.
        return-
        string name */
        string getName () const;
        
        /* getRequiredPoints: return the rwquired points of a skill.
        return-
        int required points */
        int getRequiredPoints () const;

        /* friens bool operators */
        friend bool operator< (const Skill& skill_a, const Skill& skill_b);
        friend bool operator== (const Skill& skill_a, const Skill& skill_b);
        friend ostream& operator<< (ostream& os, const Skill& skill);
        
        /* unary operators */
        Skill& operator+= (int point_to_add);
        Skill operator++ (int);
        
    };
    /* binary operators, compare by id */
    bool operator!= (const Skill& skill_a, const Skill& skill_b);
    bool operator<= (const Skill& skill_a, const Skill& skill_b);
    bool operator>= (const Skill& skill_a, const Skill& skill_b);
    bool operator> (const Skill& skill_a, const Skill& skill_b);
    Skill operator+ (const Skill& skill, int point_to_add); 
    Skill operator+ (int point_to_add, const Skill& skill);
}

#endif /* SKILL_H */ 

