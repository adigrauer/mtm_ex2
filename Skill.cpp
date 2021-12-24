#include "Skill.h"

namespace mtm {

    Skill::Skill (int id_skill, string name, unsigned int required_points, int strong): 
        id_skill(id_skill), required_points(required_points), strong(strong), name(name){}

    int Skill::getId () const
    {
        return id_skill;
    }

    string Skill::getName () const
    {
        return name;
    }

    unsigned int Skill::getRequiredPoints () const
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
        os << skill.name << "level:" << skill.strong << endl;
        return os;
    }
}