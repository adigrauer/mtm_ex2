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
/*template <class T>*/ typedef T;
    class Citizen {
    private:
        //class T
        int id_citizen;
        string first_name;
        string last_name;
        int birth_year;
    public:
        Citizen (int id_citizen, string first_name, string last_name, int birth_year);
        Citizen* clone ();
        int getBirthYear () const;
        int getId () const;
        string getFirstName () const;
        string getLastName () const;
        friend bool operator< (const Citizen& citizen_a, const Citizen& citizen_b);
        friend bool operator== (const Citizen& citizen_a, const Citizen& citizen_b);
        friend ostream& operator<< (ostream& os, const Citizen& citizen);
    };
    bool operator!= (const Citizen& citizen_a, const Citizen& citizen_b);
    bool operator<= (const Citizen& citizen_a, const Citizen& citizen_b);
    bool operator>= (const Citizen& citizen_a, const Citizen& citizen_b);
    bool operator> (const Citizen& citizen_a, const Citizen& citizen_b);
    ostream& printShort (ostream& os);
    ostream& printLong (ostream& os);
}

#endif /* CITIZEN */