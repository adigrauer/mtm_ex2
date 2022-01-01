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

//conditions for hire employee
class HiringCondition1 {
public:
    bool operator()(Employee *emp) {
        return emp->getSalary() > 100;
    }
};

class HiringCondition2 {
public:
    bool operator()(Employee *emp) {
        return emp->getSalary() < 500;
    }
};

class HiringCondition3 {
public:
    bool operator()(Employee *emp) {
        return emp->getId() >= 7;
    }
};

class HiringCondition4 {
public:
    bool operator()(Employee *emp) {
        return emp->getId() < 8;
    }
};

class HiringCondition5 {
public:
    bool operator()(Employee *emp) {
        return emp->getScore() > 4;
    }
};

class HiringCondition6 {
public:
    bool operator()(Employee *emp) {
        return emp->getScore() < 10;
    }
};

void test_skill()
{
    cout << "skill test" << endl;
    Skill skill_cheack1(1,"singing",2);
    Skill skill_cheack2(2,"singing",5);
    if(skill_cheack1 > skill_cheack2){
        cout << "should be false- test 1" << endl;
    }
    skill_cheack1 += 4;
    try {
        skill_cheack1 += -2;
    }catch(NegativePoints) {
        cout << "catch 1- passed" << endl;
    };
    try {
        skill_cheack1 + -1;
    }catch(NegativePoints) {
        cout << "catch 2- passed" << endl;
    };
    skill_cheack1 + 5;
    //need to handle symetric +
    //5 + skill_cheack1;
    skill_cheack1 ++;
    if(skill_cheack1 >= skill_cheack2){
        cout << "should be false- test 2" << endl;
    }
    if(skill_cheack1 == skill_cheack2){
        cout << "should be false- test 3" << endl;
    }
    if(skill_cheack1.getRequiredPoints() != 12){
        cout << "should be 12 required points- test 4" << endl;
    }
    cout << skill_cheack1 << endl;
    cout << skill_cheack2 << endl;
    cout << "skill test passed" << endl;
}

void test_employee()
{
    cout << "employee test" << endl;
    Employee employee1(2, "adi", "grauer", 10);
    Employee employee2(4, "lottem", "arave", 12);
    Employee employee3(1, "nadav", "ru", 4);
    Employee employee4(7, "adi", "grauer", 7);
    Skill skill1(1,"baking",2);
    Skill skill2(2,"dancing",5);
    Skill skill3(4,"eating",10);
    Skill skill4(12,"drawing",7);
    Skill skill5(8,"writing",1);
    try {
        employee4.learnSkill(skill3);
    }catch(canNotLearnSkill) {
        cout << "catch 1- passed" << endl;
    };
    try {
        employee3.learnSkill(skill2);
    }catch(canNotLearnSkill) {
        cout << "catch 2- passed" << endl;
    };
    employee2.setScore(20);
    if(employee2.getScore() != 20){
        cout << "score sould be 20" << endl;
    }
    employee2.learnSkill(skill3);
    employee2.learnSkill(skill1);
    employee2.learnSkill(skill2);
    try {
        employee2.learnSkill(skill3);
    }catch(SkillAlreadyLearned) {
        cout << "catch 3- passed" << endl;
    };
    cout << "LongPrint employee1" << endl;
    employee2.printLong(cout);

    employee1.setScore(50);
    employee1.learnSkill(skill4);
    employee1.learnSkill(skill1);
    employee1.learnSkill(skill2);
    cout << "LongPrint employee2" << endl;
    employee1.printLong(cout);

    employee2.forgetSkill(1);
    employee2.forgetSkill(2);
    cout << "LongLong employee2" << endl;
    employee2.printLong(cout);
    employee1.forgetSkill(12);
    employee1.forgetSkill(1);
    employee1.forgetSkill(2);
    try {
        employee1.forgetSkill(8);
    }catch(DidNotLearnSkill) {
        cout << "catch 4- passed" << endl;
    };
    try {
        employee1.forgetSkill(4);
    }catch(DidNotLearnSkill) {
        cout << "catch 5- passed" << endl;
    };
    cout << "printLong employee1" << endl;
    employee1.printLong(cout);
    /*** how to use clone??
    Citizen* copy = employee1.clone();
    cout << "printLong copy" << endl;      
    (*copy).printLong(cout);
    */
    cout << "employee test passed" << endl;
}

void test_manager()
{
    cout << "manager test" << endl;
    Employee employee1(2, "adi", "grauer", 10);
    Employee employee2(4, "lottem", "arave", 12);
    Employee employee3(1, "nadav", "ru", 4);
    Employee employee4(7, "gili", "grauer", 7);
    Manager manager1(7, "einat", "grauer", 2000);
    Manager manager2(7, "ofer", "grauer", 1996);
    manager1.addEmployee(&employee4);
    manager1.addEmployee(&employee1);
    manager2.addEmployee(&employee3);
    manager2.addEmployee(&employee2);
    try {
        manager1.addEmployee(&employee1);
    }catch(EmployeeAlreadyHired) {
        cout << "catch 1- passed" << endl;
    };
    try {
        manager2.addEmployee(&employee2);
    }catch(EmployeeAlreadyHired) {
        cout << "catch 2- passed" << endl;
    };
    manager1.setSalary(100);
    if(manager1.getSalary() != 100){
        cout << "manager 1 salary should be 100" << endl;
    }
    manager2.setSalary(200);
    if(manager2.getSalary() != 200){
        cout << "manager 2 salary should be 200" << endl;
    }
    cout << "printLong manager1" << endl;
    manager1.printLong(cout);
    cout << "printLong manager2" << endl;
    manager2.printLong(cout);
    manager2.removeEmployee(1);
    try {
        manager2.removeEmployee(7);
    }catch(EmployeeNotHired) {
        cout << "catch 3- passed" << endl;
    };
    manager1.removeEmployee(7);
    manager1.removeEmployee(2);
    cout << "printLong manager1" << endl;
    manager1.printLong(cout);
    cout << "printLong manager2" << endl;
    manager2.printLong(cout);
    cout << "manager test passed" << endl;
}

void test_workplace()
{
    cout << "workplace test" << endl;
    Employee employee1(2, "adi", "grauer", 10);
    Employee employee2(14, "lottem", "arave", 12);
    Employee employee3(1, "nadav", "ru", 4);
    Employee employee4(7, "gili", "grauer", 7);
    employee1.setScore(12);
    employee2.setScore(9);
    employee3.setScore(2);
    employee4.setScore(5);
    Manager manager1(7, "einat", "grauer", 2000);
    Manager manager2(8, "ofer", "grauer", 1996);
    HiringCondition3 condition3;
    HiringCondition6 condition6;
    WorkPlace atias(1000, "atias", 100, 500);
    WorkPlace hahi(1001, "hahi", 27, 72);
    atias.hireManager(&manager2);
    hahi.hireManager(&manager1);
    try {
        atias.hireManager(&manager2);
    }catch(ManagerAlreadyHired) {
        cout << "catch 1- passed" << endl;
    };
    try {
        hahi.hireManager(&manager2);
    }catch(CanNotHireManager) {
        cout << "catch 2- passed" << endl;
    };
    atias.hireEmployee(condition3, &employee2, manager2.getId());
    atias.hireEmployee(condition3, &employee4, manager2.getId());
    try {
        atias.hireEmployee(condition3, &employee1, manager2.getId());
    }catch(EmployeeNotSelected) {
        cout << "catch 3- passed" << endl;
    };
    try {
        atias.hireEmployee(condition3, &employee2, manager1.getId());
    }catch(ManagerIsNotHired) {
        cout << "catch 4- passed" << endl;
    };
    try {
        atias.hireEmployee(condition3, &employee4, manager2.getId());
    }catch(EmployeeAlreadyHired) {
        cout << "catch 5- passed" << endl;
    };
    cout << "printing workplace 1" << endl;
    cout << atias;
    cout << endl;
    if(employee2.getSalary() != 100){
        cout << "lottems's salary should be 100" << endl;
    }
    if(employee3.getSalary() != 0){
        cout << "nadav's salary should be 100" << endl;
    }
    hahi.hireEmployee(condition6, &employee3, manager1.getId());
    hahi.hireEmployee(condition6, &employee4, manager1.getId());
    hahi.hireEmployee(condition6, &employee2, manager1.getId());
    try {
        hahi.hireEmployee(condition6, &employee1, manager1.getId());
    }catch(EmployeeNotSelected) {
        cout << "catch 6- passed" << endl;
    };
    if(employee3.getSalary() != 27){
        cout << "nadav's salary should be 27" << endl;
    }
    if(manager1.getSalary() != 72){
        cout << "einat's salary should be 72" << endl;
    }
    if(employee2.getSalary() != 127){
        cout << "lottems's salary should be 127" << endl;
    }
    cout << "printing workplace 2" << endl;
    cout << hahi;
    cout << endl;
    hahi.fireEmployee(employee4.getId(), manager2.getId());
    hahi.fireEmployee(employee3.getId(), manager2.getId());
    hahi.fireEmployee(employee2.getId(), manager2.getId());
    cout << "printing workplace 2- without workers only manager" << endl;
    cout << hahi;
    cout << endl;
    if(employee2.getSalary() != 100){
        cout << "lottem's salary should be 100" << endl;
    }
    if(employee3.getSalary() != 0){
        cout << "nadav's salary should be 0" << endl;
    }
    atias.fireManager(manager1.getId());
    cout << "printing workplace 1- without workers" << endl;
    cout << hahi;
    cout << endl;
    cout << "workplace test passed" << endl;
}

///bool function for faculty learm skill condition
bool facultyCond1(Employee* emp){
    return emp->getId() > 5;
}

bool facultyCond2(Employee* emp){
    return emp->hasSkill(1);
}

bool facultyCond3(Employee* emp){
    return emp->hasSkill(4);
}

bool facultyCond4(Employee* emp){
    return emp->hasSkill(1);
}

bool facultyCond5(Employee* emp){
    return emp->getSalary() > 40;
}

bool facultyCond6(Employee* emp){
    return emp->getScore() > 20;
}

bool facultyCond7(Employee* emp){
    return emp->getLastName() > "dor";
}

bool facultyCond8(Employee* emp){
    return emp->getLastName() < "roni";
}

bool facultyCond9(Employee* emp){
    return emp->getBirthYear() > 2000;
}

void test_faculty()
{
    Skill skill1(1,"baking",2);
    Skill skill2(2,"dancing",5);
    Skill skill3(4,"eating",10);
    Skill skill4(12,"drawing",7);
    Skill skill5(8,"writing",1);
    Faculty bake(facultyCond1, skill1, 5, 1);
    Faculty dance(facultyCond2, skill2, 10, 2);
    Faculty eat(facultyCond7, skill3, 3, 5);
    Faculty draw(facultyCond9, skill1, 7, 3);
    Faculty write(facultyCond6, skill1, 6, 9);
    Employee employee1(2, "adi", "grauer", 10);
    Employee employee2(4, "lottem", "arave", 2020);
    Employee employee3(1, "nadav", "ru", 4);
    Employee employee4(7, "gili", "grauer", 7);
    Employee employee5(7, "einat", "grauer", 2000);
    Employee employee6(8, "ofer", "grauer", 1996);
    try {
        bake.teach(&employee6);
    }catch(canNotLearnSkill) {
        cout << "catch 1- passed" << endl;
    };
    employee6.setScore(7);
    employee1.setScore(50);
    employee2.setScore(50);
    employee3.setScore(50);
    employee4.setScore(50);
    employee5.setScore(50);
    bake.teach(&employee6);
    dance.teach(&employee6);
    try {
        dance.teach(&employee2);
    }catch(EmployeeNotAccepted) {
        cout << "catch 1- passed" << endl;
    };
    write.teach(&employee1);
    draw.teach(&employee2);
    try {
        draw.teach(&employee3);
    }catch(EmployeeNotAccepted) {
        cout << "catch 2- passed" << endl;
    };
    eat.teach(&employee4);
    try {
        eat.teach(&employee2);
    }catch(EmployeeNotAccepted) {
        cout << "catch 3- passed" << endl;
    };
    cout << "faculty test passed" << endl;
}

int main(){
    test_skill();
    test_employee();
    test_manager();
    test_workplace();
    test_faculty();
    return 0;
}