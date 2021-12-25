#include <string>
#include <fstream>
#include <iostream>
#include "Skill.h"
#include "exception.h"
#include "Employee.h"
#include "Citizen.h"
#include "Manager.h"

using std::ostream;
using std::cout;
using std::endl;
using std::string;
using namespace mtm;

int main() {
    Skill s1(1, "a", 0, 0);
    cout << s1;
    Skill s2(2, "b", 1, 1);
    Skill s3(3, "c", 2, 2);
    if(s3 < s2)
        return -1;
    if(s3 <= s2)
        return -1;
    s2 += 2;
    s2++;
    cout << s2;

    Employee employee1(1, "Lottem", "Arava", 1999);
    Employee employee2(1, "Adi", "Grauer", 1998);
    if(employee1.getSalary() != 0){
        return -1;
    }
    employee1.setSalary(1000);
    employee1.setScore(80);
    employee1.learnSkill(s1);
    employee1.learnSkill(s2);
    employee1.printLong(cout);
    employee1.forgetSkill(2);
    employee1.printLong(cout);
    employee2.printShort(cout);
    return 0;
    /* their test*/
    /*Employee e1(1, "John", "Williams", 2002);
    Skill s1(1,"C++",0);
    Skill s2(2, "Java", 0);
    e1.learnSkill(s1);
    e1.learnSkill(s2);
    cout << "Short_Print" << endl;
    e1.printShort(cout);
    cout << "Long Print" << endl;
    e1.printLong(cout);
    return 0;*/
}
