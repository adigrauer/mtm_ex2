#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>
#include <iostream>
#include <memory>

//are all needed??
using std::ostream;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;

namespace mtm {

    /* Citizen class declaration */
    class Citizen {
    private:
        string first_name;
        string last_name;
        int birth_year;
    protected:
        int id_citizen;
    public:
        /* Citizen C'tor */
        Citizen (int id_citizen, string first_name, string last_name, int birth_year);
        
        /* Citizen copy C'tor */
        Citizen (const Citizen& citizen) = default;
        
        /* Manager virtual D'tor */
        virtual ~Citizen () = default;

        /* clone: return copy of existing Citizen.
        return-
        Citizen pointer to copy of an existing Citizen */
        virtual Citizen* clone () const = 0;
        
        /* getBirthYear: return copy of Citizen's birthday year.
        return-
        int birthday year */
        int getBirthYear () const;

        /* getId: return copy of Citizen's id from const citizen.
        return-
        int id */
        int getId () const;

        /* getId: return copy of Citizen's id from non const citizen.
        return-
        int id */
        int getId ();

        /* getFirstName: return copy of Citizen's first name.
        return-
        string first name */
        string getFirstName () const;

        /* getLastName: return copy of Citizen's last name.
        return-
        string last name */
        string getLastName () const;

        /* overloud friend operators */
        friend bool operator< (const Citizen& citizen_a, const Citizen& citizen_b);
        friend bool operator== (const Citizen& citizen_a, const Citizen& citizen_b);
        
        /* printShort- virtual print short information of the Manager by given format */
        virtual ostream& printShort (ostream& os) const = 0;

        /* printShort- virtual print long information of the Manager by given format */
        virtual ostream& printLong (ostream& os) const = 0;
    };

    /* overloud operators */
    bool operator!= (const Citizen& citizen_a, const Citizen& citizen_b);
    bool operator<= (const Citizen& citizen_a, const Citizen& citizen_b);
    bool operator>= (const Citizen& citizen_a, const Citizen& citizen_b);
    bool operator> (const Citizen& citizen_a, const Citizen& citizen_b);
}

#endif /* CITIZEN */