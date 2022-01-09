#include "Citizen.h"

namespace mtm {

    Citizen::Citizen (int id_citizen, string first_name, string last_name, int birth_year) :
        first_name(first_name), 
        last_name(last_name),
        birth_year(birth_year),
        id_citizen(id_citizen)
    {
    }

    int Citizen::getBirthYear () const
    {
        return birth_year;
    }

    int Citizen::getId () const
    {
        return id_citizen;
    }

    int Citizen::getId ()
    {
        return id_citizen;
    }

    string Citizen::getFirstName () const
    {
        return first_name;
    }

    string Citizen::getLastName () const
    {
        return last_name;
    }
    
    bool operator< (const Citizen& citizen_a, const Citizen& citizen_b)
    {
        return citizen_a.id_citizen < citizen_b.id_citizen;
    }
    
    bool operator== (const Citizen& citizen_a, const Citizen& citizen_b)
    {
        return citizen_a.id_citizen == citizen_b.id_citizen;
    }

    bool operator!= (const Citizen& citizen_a, const Citizen& citizen_b)
    {
        return !(citizen_a == citizen_b);
    }

    bool operator<= (const Citizen& citizen_a, const Citizen& citizen_b)
    {
        return !(citizen_b < citizen_a);
    }

    bool operator>= (const Citizen& citizen_a, const Citizen& citizen_b)
    {
        return citizen_b <= citizen_a;
    }

    bool operator> (const Citizen& citizen_a, const Citizen& citizen_b)
    {
        return citizen_b < citizen_a;
    }
}
