<<<<<<< HEAD:manager.h
#ifndef MANAGER_H
#define MANAGER_H

#include <string>
//#include <fstream>
#include <iostream>
#include <set>
#include "Skill.h"
#include "Citizen.h"
#include "Employee.h"

//are all needed??
using std::ostream;
using std::set;
using std::cout;
using std::endl;
using std::string;

namespace mtm {
    class Manager : public Citizen {
    private:
        int salary;
        set<Employee*> employees;
    public:
        Manager (int id_citizen, string first_name, string last_name, int birth_year);
        Manager (const Manager& manager);
        ~Manager ();
        int getSalary ();
        virtual Citizen* clone () const;
        void addEmployee (Employee* const employee);
        void removeEmployee (const unsigned int id_employee);
        void setSalary (unsigned int salary);
        friend ostream& operator<< (ostream& os, const Manager& employee);
        ostream& printShort (ostream& os) override;
        ostream& printLong (ostream& os) override;
    };
}

=======
#ifndef MANAGER_H
#define MANAGER_H

#include <string>
//#include <fstream>
#include <iostream>
#include <set>
#include "Skill.h"
#include "Citizen.h"
#include "Employee.h"

//are all needed??
using std::ostream;
using std::set;
using std::cout;
using std::endl;
using std::string;

namespace mtm {
    class Manager : public Citizen {
    private:
        int salary;
        set<Employee*> employees;
    public:
        Manager (int id_citizen, string first_name, string last_name, int birth_year);
        Manager (const Manager& manager);
        ~Manager ();
        int getSalary ();
        virtual Citizen* clone () const;
        void addEmployee (Employee* const employee);
        void removeEmployee (const unsigned int id_employee);
        void setSalary (unsigned int salary);
        friend ostream& operator<< (ostream& os, const Manager& employee);
        ostream& printShort (ostream& os) override;
        ostream& printLong (ostream& os) override;
    };
}

>>>>>>> 142334cba2d320ccb591777578a6c403486a985f:Manager.h
#endif /* MANAGER_H */