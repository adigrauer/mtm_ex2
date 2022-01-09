#include <string>
#include <fstream>
#include <iostream>
#include "../Skill.h"
#include "../exceptions.h"
#include "../Employee.h"
#include "../Citizen.h"
#include "../Manager.h"
#include "../WorkPlace.h"
#include "../Faculty.h"

using std::ostream;
using std::cout;
using std::endl;
using std::string;
using namespace mtm;

void test_our()
{
    Skill s1(1, "a", 0);
    cout << s1;
    Skill s2(2, "b", 1);
    Skill s3(3, "c", 2);
    if(s3 < s2)
        return;
    if(s3 <= s2)
        return;
    s2 += 2;
    s2++;
    cout << s2;
    Employee employee1(1, "Lottem", "Arava", 1999);
    Employee employee2(1, "Adi", "Grauer", 1998);
    if(employee1.getSalary() != 0){
        return;
    }
    employee1.setSalary(1000);
    employee1.setScore(80);
    employee1.learnSkill(s1);
    employee1.learnSkill(s2);
    employee1.printLong(cout);
    employee1.forgetSkill(2);
    employee1.printLong(cout);
    employee2.printShort(cout);
}

void test_skill()
{
    Skill s1 (1,"C++",3);   
    Skill s2 = 1 + s1 + 3;
    cout << s1 << endl;
    cout << s2.getRequiredPoints() << endl;
    return;
}

void test_employee()
{
    Employee e1(1, "John", "Williams", 2002);
    Skill s1(1,"C++",0);
    Skill s2(2, "Java", 0);
    e1.learnSkill(s1);
    e1.learnSkill(s2);
    cout << "Short_Print" << endl;
    e1.printShort(cout);
    cout << "Long Print" << endl;
    e1.printLong(cout);
}

void test_manager()
{
    Manager m1(1,"Robert", "stark", 1980);
    Employee e1(1, "John", "Williams", 2002);
    Employee e2(2, "Alex", "Martinez", 2000);
    m1.addEmployee(&e1);
    m1.addEmployee(&e2);
    cout << "Short_Print" << endl;
    m1.printShort(cout);
    cout << "Long Print" << endl;
    m1.printLong(cout);
}

void test_faculty()
{
    class Condition{
    public:
        bool operator()(Employee* emp){
            return emp->getId()>0;
        }
    };
    Workplace Meta(1,"Meta", 10000, 20000);
    Employee* e1 = new Employee(1, "John", "Williams", 2002);
    Employee* e2 = new Employee(2, "Alex", "Martinez", 2000);
    Manager* m1 = new Manager(1,"Robert", "stark", 1980);
    Meta.hireManager(m1);
    Condition condition;
    Meta.hireEmployee(condition,e1,m1->getId());
    Meta.hireEmployee(condition,e2,m1->getId());
    cout << Meta;
    Meta.fireManager(m1->getId());
    cout << Meta;
    delete e1;
    delete e2;
    delete m1;
}

void test_operators()
{
    Employee employee1(1, "adi", "grauer", 1998);
    Employee employee2(2, "nadav", "ru", 1998);
    Manager manager1(3, "gili", "gal", 1998);
    Skill s1(1, "C++", 0);
    employee1.learnSkill(s1);
    manager1.addEmployee(&employee1);
    manager1.addEmployee(&employee2);
    Manager copy = manager1;
    //manager1.printLong(cout);
    //copy.printLong(cout);
    Citizen* clone1 = employee1.clone();
    Citizen* clone2 = manager1.clone();
    //cout << "clone1" << endl << endl;
    clone1->printLong(cout);
    //cout << "clone2" << endl << endl;
    clone2->printLong(cout);
    class FacultyCondition1: public Condition{
    bool operator()(Employee* employee) override{
        return employee->getId() > 0;
        }
    };
    FacultyCondition1 fc1;
    Faculty<Condition> faculty(1, s1, 5, &fc1);
    Faculty<Condition> copy_faculty = faculty;
    
    
    //city.addFaculty(1001, skill1, 10, &fc1);
    

}

int main()
{
    //test_employee();
    //cout << endl << endl;
    //test_faculty();
    //cout << endl << endl;
    //test_manager();
    //test_our();
    //cout << endl << endl;
    test_skill();
    //test_operators();
    return 0;
}
