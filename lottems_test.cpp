#include <iostream>
#include "Employee.h"
#include "Manager.h"
#include "WorkPlace.h"
#include "City.h"
#include <assert.h>
#include "exceptions.h"

using namespace mtm;
using std::cout;
using std::endl;

bool facultyCond1(Employee* emp){
    return emp->getId()>0;
}
bool facultyCond2(Employee* emp){
    return emp->hasSkill(1);
}
bool facultyCond3(Employee* emp){
    return emp->getBirthYear() < 1990;
}

class HiringCondition {
public:
    bool operator()(Employee *emp) {
        return emp->getScore() > 10;
    }
};

int main() {
    City city ("Haifa");

    Skill cooking_skill(1, "Cooking", 0);
    Skill dancing_skill(2, "Dancing", 10);
    Skill special_skill(10, "Defense against the dark arts", 100);

    city.addEmployee(5, "Lottem", "Arava", 1999);
    city.addEmployee(4, "Harry", "Potter", 1980);
    city.addEmployee(3, "Lorelei", "Gilmore", 1968);
    city.addEmployee(2, "Rory", "Gilmore", 1982);

    city.addManager(12, "Luke", "Deines", 1965);
    city.addManager(11, "Jess", "Meriano",1982);
    city.addManager(10,"Paris", "Geller", 1981);

    city.addFaculty(100, cooking_skill, 10, facultyCond1);
    city.addFaculty(200,cooking_skill, 50, facultyCond3);
    city.addFaculty(300,dancing_skill, 10, facultyCond2);
    try{
        city.addFaculty(200, special_skill, 100, facultyCond2);
    }catch(FacultyAlreadyExists) {};
    city.addFaculty(400, special_skill, 100, facultyCond2);

    city.teachAtFaculty(5, 100);
    city.teachAtFaculty(4, 100);
    city.teachAtFaculty(3, 100);

    cout << endl << "printAllEmployeesWithSkill output1" << endl;
    city.printAllEmployeesWithSkill(cout, 1);


}