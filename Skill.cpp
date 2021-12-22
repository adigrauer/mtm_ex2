#include "Skill.h"

namespace mtm {

    Skill::Skill (int id_skill, string name, unsigned int required_points, int strong): 
        id_skill(id_skill), required_points(required_points), strong(strong)
    {
        string new_name; // i think we nedd to copy the name 
    }

    Skill::~Skill ()
    {
    }
}