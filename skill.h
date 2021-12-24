#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <fstream>
#include <iostream>

using std::ostream;
using std::cout;
using std::endl;
using std::string;

namespace mtm {
    class Skill {
    private: 
        int id_skill;
        string name;
        unsigned int required_points;
        int strong;
    public:
        Skill(int id_skill, string name, unsigned int required_points, int strong);
        ~Skill () = default;
        int getId () const;
        string getName () const;
        unsigned int getRequiredPoints () const;
        //print
        friend bool operator< (const Skill& skill_a, const Skill& skill_b);
        friend bool operator== (const Skill& skill_a, const Skill& skill_b);
        friend ostream& operator<< (ostream& os, const Skill& skill);
        Skill& operator+= (const Skill& skill);
        Skill& operator++ (); //think about it
    };
    //compere by id
    bool operator!= (const Skill& skill_a, const Skill& skill_b);
    bool operator<= (const Skill& skill_a, const Skill& skill_b);
    bool operator>= (const Skill& skill_a, const Skill& skill_b);
    bool operator> (const Skill& skill_a, const Skill& skill_b);
    Skill operator+ (const Skill& skill, int points); 
}

#endif /* SKILL_H */ 

