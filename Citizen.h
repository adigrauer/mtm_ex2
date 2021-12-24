#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>
//#include <fstream>
#include <iostream>

//are all needed??
using std::ostream;
using std::cout;
using std::endl;
using std::string;

namespace mtm {
    class Citizen {
    private:
        string first_name;
        string last_name;
        int birth_year;
    protected:
        int id_citizen;
    public:
        Citizen (int id_citizen, string first_name, string last_name, int birth_year);
        virtual Citizen* clone () const = 0;
        int getBirthYear () const;
        int getId () const;
        string getFirstName () const;
        string getLastName () const;
        friend bool operator< (const Citizen& citizen_a, const Citizen& citizen_b);
        friend bool operator== (const Citizen& citizen_a, const Citizen& citizen_b);
        friend ostream& operator<< (ostream& os, const Citizen& citizen);
        virtual ostream& printShort (ostream& os) = 0;
        virtual ostream& printLong (ostream& os) = 0;
    };
    bool operator!= (const Citizen& citizen_a, const Citizen& citizen_b);
    bool operator<= (const Citizen& citizen_a, const Citizen& citizen_b);
    bool operator>= (const Citizen& citizen_a, const Citizen& citizen_b);
    bool operator> (const Citizen& citizen_a, const Citizen& citizen_b);
}

#endif /* CITIZEN */