#include "Skill.h"

namespace mtm {

    Skill::Skill (int id_skill, string name, int required_points): 
        id_skill(id_skill),
        name(name),
        required_points(required_points)
    {
    }

    int Skill::getId () const
    {
        return id_skill;
    }

    string Skill::getName () const
    {
        return name;
    }

    int Skill::getRequiredPoints () const
    {
        return required_points;
    }

    bool operator< (const Skill& skill_a, const Skill& skill_b)
    {
        return skill_a.id_skill < skill_b.id_skill;
    }

    bool operator== (const Skill& skill_a, const Skill& skill_b)
    {
        return skill_a.id_skill == skill_b.id_skill;
    }

    ostream& operator<< (ostream& os, const Skill& skill)
    {
        os << skill.name << /*" level: " << skill.strong <<*/ endl;
        return os;
    }

    Skill& Skill::operator+= (int point_to_add)
    {
        /*if(point_to_add < 0){
            throw ()
        }*/
        required_points += point_to_add;
        return *this;
    }

    Skill& Skill::operator++ (int) 
    {
        this->required_points ++;
        return *this;
    }
    
    //////////
    
    bool operator!= (const Skill& skill_a, const Skill& skill_b)
    {
        return !(skill_a == skill_b);
    }

    bool operator<= (const Skill& skill_a, const Skill& skill_b)
    {
        return !(skill_b < skill_a);
    }

    bool operator>= (const Skill& skill_a, const Skill& skill_b)
    {
        return skill_b <= skill_a;
    }

    bool operator> (const Skill& skill_a, const Skill& skill_b)
    {
        return skill_b < skill_a;
    }

    Skill operator+ (const Skill& skill, int points)
    {
        return Skill(skill) += points;
    }

    Skill operator+ (int points, const Skill& skill)
    {
         return Skill(skill) += points;
    }

}