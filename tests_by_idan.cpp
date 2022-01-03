#include <cstdlib>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <cstdio>
#include <vector>
#include "exceptions.h"
#include "Skill.h"
#include "Citizen.h"
#include "Employee.h"
#include "Manager.h"
#include "WorkPlace.h"
#include "Faculty.h"
#include "City.h"

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;

using namespace mtm;

using mtm::Exception;
using mtm::Skill;
using mtm::Citizen;
using mtm::Employee;
using mtm::Manager;
using mtm::WorkPlace;
using mtm::Faculty;
using mtm::City;

static const std::string FILE_PATH = "./testOutputs";

#define ASSERT_TEST(expr)                                                         \
     do {                                                                          \
         if (!(expr)) {                                                            \
             printf("\nAssertion failed at %s:%d %s ", __FILE__, __LINE__, #expr); \
             result = false;                                                       \
         }                                                                         \
     } while (0);

#define RUN_TEST(test, name)                  \
    do {                                 \
        cout << "+ Running " << (name) << "...";  \
        if (test()) {                    \
            cout << "[OK]\n" << endl;         \
        } else {                         \
            cout << "[Failed]\n\n <span>To see what the test does and why it failed, please check the link at the top of the page to the test file</span>" << endl;       \
        }                                \
    } while (0);

#define ASSERT(expr) ASSERT_TEST(expr)

#define OPEN_FILE(streamName, name) std::string fileName = name;\
std::ofstream streamName(fileName, std::ofstream::trunc | std::ofstream::in);\
if(!(streamName).is_open()){\
throw FileFailed();\
}

class FileFailed: std::exception {
public:
    FileFailed() = default;
    ~FileFailed() = default;
};

bool matchFiles(const std::string& out, const std::string& exp) {
    ifstream output(out);
    if (!output) {
        cout << "can't open file" << endl;
    }
    ifstream expOutput(exp);
    if (!expOutput) {
        cout << "can't open file" << endl;
    }
    while (!output.eof()) {
        char c;
        output >> std::noskipws >> c;
        char ex;
        expOutput >> std::noskipws >> ex;
        if (ex != c) {
            return false;
        }
    }
    return true;
}

template <class T> void print(const T& x, ofstream& stream) { stream << x << endl; }

///////////////////////////////////////////////////////////////////////////////////
//                               Conditions                                      //
///////////////////////////////////////////////////////////////////////////////////

class FacultyCondition1: public Condition{
    bool operator()(Employee* employee) override{
        return employee->getId() > 0;
    }
};

class FacultyCondition2: public Condition{
    bool operator()(Employee* employee) override{
        return employee->getId() > 3;
    }
};

class FacultyCondition3: public Condition{
    bool operator()(Employee* employee) override{
        return employee->getId()>0;
    }
};

class FacultyCondition4: public Condition{
    bool operator()(Employee* employee) override{
        return employee->hasSkill(1);
    }
};

class FacultyCondition5: public Condition{ 
    bool operator()(Employee* emp) override{
        return emp->hasSkill(2) && emp->hasSkill(1);
    }
};

class FacultyCondition6: public Condition{ 
    bool operator()(Employee* emp) override{
        return emp->getBirthYear() >= 2000;
    }
};

class HiringCondition1{
public:
    bool operator()(Employee *emp) {
        return emp->getScore() >= 0;
    }
};

class HiringCondition2{
public:
    bool operator()(Employee *emp) {
        return emp->getScore() >= 40;
    }
};

class HiringCondition3{
public:
    bool operator()(Employee *emp) {
        return emp->getId() % 5 == 0;
    }
};

class HiringCondition4{
    public:
        bool operator()(Employee* emp){
            return emp->getId()>0;
        }
};

class HiringCondition5{
    public:
        bool operator()(Employee* emp){
            return emp->getId() < 5;
        }
};

class HiringCondition6{
public:
    bool operator()(Employee *emp) {
        return emp->getScore() > 5;
    }
};


///////////////////////////////////////////////////////////////////////////////////
//                          The tests Starts here                                //
//                                GOOD LUCK                                      //
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
//                              Skill tests                                      //
///////////////////////////////////////////////////////////////////////////////////

bool testConstructorSkill(){
    bool result = true;
    OPEN_FILE(out, FILE_PATH + std::string("/your_outputs/testConstructorSkill.txt"))
    Skill s1(1,"skill 1", 1);
    Skill s2(2,"skill 2", 2);
    Skill s3(3,"skill 3", 3);
    print(s1, out);
    print(s2, out);
    print(s3, out);
    out.close();
    ASSERT(matchFiles(fileName, FILE_PATH + std::string("/expected/testConstructorSkill.txt")))
    return result;
}

bool testBooleanOperatorsSkill()
{
    bool result = true;
    Skill s1(1,"skill 1", 1);
    Skill s2(2,"skill 2", 2);
    Skill s3(3,"skill 3", 3);
    Skill s4(3,"skill 4", 4);
    ASSERT(s1 < s2)
    ASSERT(s2 > s1)
    ASSERT(s3 == s4)
    ASSERT(s1 <= s1)
    ASSERT(s1 <= s2)
    ASSERT(s2 >= s1)
    ASSERT(s3 >= s4)
    ASSERT(s1 != s2)
    return result;
}

bool testArithmeticOperatorsSkill() 
{
    bool result = true;
    OPEN_FILE(out, FILE_PATH + std::string("/your_outputs/testArithmeticOperatorsSkill.txt"))
    Skill s1(1,"skill 1", 1);
    Skill s2(2,"skill 2", 2);
    Skill s3(3,"skill 3", 3);
    Skill s4(4,"skill 4", 4);
    s1 += 3;
    s2 = s2 + 1;
    s2 = 1 + s2;
    s3++;
    print(s1, out);
    print(s2, out);
    print(s3, out);
    print(s4, out);
    ASSERT(matchFiles(fileName, FILE_PATH + std::string("/expected/testArithmeticOperatorsSkill.txt")))
    return result;
}

bool testExceptionsSkill(){
    bool result = true;
    OPEN_FILE(out, FILE_PATH + std::string("/your_outputs/testExceptionsSkill.txt"))
    Skill s1(1,"skill 1", 1);
    Skill s2(2,"skill 2", 2);
    Skill s3(3,"skill 3", 3);
    try {
        s1 += -1;
        print(s1, out);
    }
    catch (mtm::NegativePoints&) {
        print(s1, out);
        out << "NegativePoints" << endl;
    }
    try {
        s2 = s1 + (-1);
        print(s2, out);
    }
    catch (mtm::NegativePoints&) {
        print(s2, out);
        out << "NegativePoints" << endl;
    }
    try {
        s3 = (-1) + s2;
        print(s3, out);
    }
    catch (mtm::NegativePoints&) {
        print(s3, out);
        out << "NegativePoints" << endl;
    }
    out.close();
    ASSERT(matchFiles(fileName, FILE_PATH + std::string("/expected/testExceptionsSkill.txt")))
    return result; 
}

///////////////////////////////////////////////////////////////////////////////////
//                             Employee tests                                    //
///////////////////////////////////////////////////////////////////////////////////

bool testEmployee_SegelProvided(){
    bool result = true;
    OPEN_FILE(out, FILE_PATH + std::string("/your_outputs/testEmployee_SegelProvided.txt"))
    Employee e1(1, "John", "Williams", 2002);
    Skill s1(1,"C++",0);
    Skill s2(2, "Java", 0);
    e1.learnSkill(s1);
    e1.learnSkill(s2);
    out << "Short_Print" << endl;
    e1.printShort(out);
    out << "Long Print" << endl;
    e1.printLong(out);
    out.close();
    ASSERT(matchFiles(fileName, FILE_PATH + std::string("/expected/testEmployee_SegelProvided.txt")))
    return result;
}

bool testEmployee(){
    bool result = true;
    OPEN_FILE(out, FILE_PATH + std::string("/your_outputs/testEmployee.txt"))
    Skill s1(1,"skill 1", 1);
    Skill s2(2,"skill 2", 2);
    Skill s3(3,"skill 3", 3);
    Skill s4(4,"skill 4", 4);
    Employee e1(1,"name","1", 2000);
    out << "printShort:" << endl;
    e1.printShort(out);
    out << "printLong:" << endl;
    e1.printLong(out);
    ASSERT(!e1.hasSkill(1))
    e1.setScore(2);
    e1.learnSkill(s2);
    e1.learnSkill(s1);
    try {
        e1.learnSkill(s3);
    }
    catch (mtm::CanNotLearnSkill&) {
        out << "CanNotLearnSkill" << endl;
    }
    try {
        e1.learnSkill(s1);
    }
    catch (mtm::SkillAlreadyLearned&) {
        out << "SkillAlreadyLearned" << endl;
    }
    e1.setScore(3);
    e1.learnSkill(s4);
    e1.learnSkill(s3);
    ASSERT(e1.hasSkill(1))
    e1.forgetSkill(1);
    ASSERT(!e1.hasSkill(1))
    e1.setSalary(100);
    e1.printLong(out);
    e1.forgetSkill(2);
    e1.forgetSkill(3);
    e1.forgetSkill(4);
    e1.printLong(out);
    out.close();
    ASSERT(matchFiles(fileName, FILE_PATH + std::string("/expected/testEmployee.txt")))
    return result;
}

///////////////////////////////////////////////////////////////////////////////////
//                              Manager tests                                    //
///////////////////////////////////////////////////////////////////////////////////

bool testManager_SegelProvided(){
    bool result = true;
    OPEN_FILE(out, FILE_PATH + std::string("/your_outputs/testManager_SegelProvided.txt"))
    Employee e1(1, "John", "Williams", 2002);
    Employee e2(2, "Alex", "Martinez", 2000);
    Manager m1(1,"Robert", "stark", 1980);
    m1.addEmployee(&e1);
    m1.addEmployee(&e2);
    out << "Short_Print" << endl;
    m1.printShort(out);
    out << "Long Print" << endl;
    m1.printLong(out);
    out.close();
    ASSERT(matchFiles(fileName, FILE_PATH + std::string("/expected/testManager_SegelProvided.txt")))
    return result; 
}

bool testManager(){
    bool result = true;
    OPEN_FILE(out, FILE_PATH + std::string("/your_outputs/testManager.txt"))
    Employee e1(1,"name","1", 2001);
    Employee e2(2,"name","2", 2002);
    Employee e3(3,"name","3", 2003);
    Employee e4(4,"name","4", 2004);
    e1.setSalary(100);
    e2.setSalary(200);
    e3.setSalary(300);
    e4.setSalary(400);
    Manager m1(1,"Big","Boss",2000);
    out << "printShort:" << endl;
    m1.printShort(out);
    out << endl<< "printLong:" << endl;
    m1.printLong(out);
    m1.setSalary(500);
    try {
        m1.removeEmployee(1);
    }
    catch (mtm::EmployeeIsNotHired&) {
        out << endl<< "EmployeeIsNotHired" << endl;
    }
    m1.addEmployee(&e1);
    try {
        m1.addEmployee(&e1);
    }
    catch (mtm::EmployeeAlreadyHired&) {
        out << "EmployeeAlreadyHired" << endl << endl;
    }
    m1.removeEmployee(1);
    m1.addEmployee(&e2);
    m1.addEmployee(&e4);
    m1.addEmployee(&e3);
    m1.printLong(out);
    m1.removeEmployee(2);
    m1.removeEmployee(3);
    m1.removeEmployee(4);
    out.close();
    ASSERT(matchFiles(fileName, FILE_PATH + std::string("/expected/testManager.txt")))
    return result;
}

///////////////////////////////////////////////////////////////////////////////////
//                             Workplace tests                                   //
///////////////////////////////////////////////////////////////////////////////////

bool testWorkplace_SegelProvided(){
    bool result = true;
    OPEN_FILE(out, FILE_PATH + std::string("/your_outputs/testWorkplace_SegelProvided.txt"))
    WorkPlace Meta(1,"Meta", 10000, 20000); 
    Employee* e1 = new Employee(1, "John", "Williams", 2002);
    Employee* e2 = new Employee(2, "Alex", "Martinez", 2000);
    Manager* m1 = new Manager(1,"Robert", "stark", 1980);
    Meta.hireManager(m1);
    HiringCondition4 condition;
    Meta.hireEmployee(condition,e1,m1->getId());
    Meta.hireEmployee(condition,e2,m1->getId());
    out << Meta;
    Meta.fireManager(m1->getId());
    out << Meta;
    out.close();
    ASSERT(matchFiles(fileName, FILE_PATH + std::string("/expected/testWorkplace_SegelProvided.txt")))
    delete e1;
    delete e2;
    delete m1;
    return result;
}

bool testWorkplace(){
    bool result = true;
    OPEN_FILE(out, FILE_PATH + std::string("/your_outputs/testWorkplace.txt"))
    string str1("WorkPlace");
    WorkPlace WP(1,str1, 7500, 15000);
    WorkPlace WP0(1,"In Bankruptcy", 100, 150); 
    Employee* e1 = new Employee(1, "Employee", "number_1", 2000);
    Employee* e2 = new Employee(2, "Employee", "number_2", 2000);
    Employee* e3 = new Employee(3, "Employee", "number_3", 2000);
    Employee* e4 = new Employee(4, "Employee", "number_4", 2000);
    Employee* e5 = new Employee(5, "Employee", "number_5", 2000);
    Manager* m1 = new Manager(6, "Manager", "number_1", 1990);
    Manager* m2 = new Manager(7, "Manager", "number_2", 1990);
    ASSERT(WP.getId() == 1)
    ASSERT(WP.getManagersSalary() == 15000)
    ASSERT(WP.getWorkersSalary() == 7500)
    ASSERT(str1.compare(WP.getName()) == 0)
    WP.hireManager(m1);
    WP0.hireManager(m2);
    try {
        WP.hireManager(m1);
    }
    catch (mtm::ManagerAlreadyHired&) {
        out << "ManagerAlreadyHired" << endl;
    }
    try {
        WP.hireManager(m2);
    }
    catch (mtm::CanNotHireManager&) {
        out << "CanNotHireManager" << endl;
    }
    HiringCondition5 condition;
    WP.hireEmployee(condition ,e1, 6);
    WP.hireEmployee(condition ,e2, 6);
    WP.hireEmployee(condition ,e3, 6);
    WP.hireEmployee(condition ,e4, 6);
    WP0.hireEmployee(condition ,e4, 7);
    try {
        WP.hireEmployee(condition ,e5, 6);
    }
    catch (mtm::EmployeeNotSelected&) {
        out << "EmployeeNotSelected" << endl;
    }
    try {
        WP.hireEmployee(condition ,e4, 7);
    }
    catch (mtm::ManagerIsNotHired&) {
        out << "ManagerIsNotHired" << endl;
    }
    try {
        WP.hireEmployee(condition ,e4, 6);
    }
    catch (mtm::EmployeeAlreadyHired&) {
        out << "EmployeeAlreadyHired" << endl;
    }
    WP.fireEmployee(1, 6);
    try {
        WP.fireEmployee(1, 6);
    }
    catch (mtm::EmployeeIsNotHired&) {
        out << "EmployeeIsNotHired" << endl;
    }
    try {
        WP.fireEmployee(2, 7);
    }
    catch (mtm::ManagerIsNotHired&) {
        out << "ManagerIsNotHired" << endl;
    }
    out << endl << WP0;
    out << endl << WP << endl;
    WP0.fireManager(7);
    try {
        WP0.fireManager(7);
    }
    catch (mtm::ManagerIsNotHired&) {
        out << "ManagerIsNotHired" << endl;
    }
    out << endl << WP0;
    ASSERT(matchFiles(fileName, FILE_PATH + std::string("/expected/testWorkplace.txt")))
    delete e1; delete e2; delete e3; delete e4; delete e5; delete m1; delete m2;
    return result;
}

///////////////////////////////////////////////////////////////////////////////////
//                              Faculty tests                                    //
///////////////////////////////////////////////////////////////////////////////////

bool testFaculty_segalProvided(){
    bool result = true;
    OPEN_FILE(out, FILE_PATH + std::string("/your_outputs/testFaculty_segalProvided.txt"))
    vector<Faculty<Condition>> Faculties;
    FacultyCondition1 fc1;
    FacultyCondition2 fc2;
    Skill skill1(1,"Programming with c++",0);
    Skill skill2(2,"Programming with c",10);
    Faculty<Condition> faculty1(1,skill1,10,&fc1);
    Faculty<Condition> faculty2(3,skill2,10,&fc2);
    Employee e1(10, "John", "Williams", 2002);
    Employee e2(20, "Alex", "Martinez", 2000);
    Faculties.push_back(faculty1);
    Faculties.push_back(faculty2);
    int i = 1;
    for(Faculty<Condition> faculty:Faculties){
        try{
            faculty.teach(&e1);
            faculty.teach(&e2);
            out << "Condition " << i << " Called" << endl;
            out << "Condition " << i << " Called" << endl;
        }
        catch(...){
            out << "Somthing goes wrong" << endl;
        }
        i++;
    }
    ASSERT(matchFiles(fileName, FILE_PATH + std::string("/expected/testFaculty_segalProvided.txt")))
    return result;
}

bool testFaculty(){
    bool result = true;
    Skill skill1(1,"Programming with c++",0);
    Skill skill2(2,"Programming with c",10);
    FacultyCondition3 fc3;
    FacultyCondition4 fc4;
    Faculty<Condition> f1(1,skill1,5,&fc3);
    Faculty<Condition> f2(2,skill2,2,&fc4);
    ASSERT(f1.getId() == 1)
    ASSERT(f2.getId() == 2)
    ASSERT(f1.getAddedPoints() == 5)
    ASSERT(f2.getAddedPoints() == 2)
    Skill* s1 = f1.getSkill();
    Skill* s2 = f2.getSkill();
    ASSERT(s1->getId() == 1)
    ASSERT(s2->getId() == 2)
    delete s1;
    delete s2;
    return result;
}

///////////////////////////////////////////////////////////////////////////////////
//                                City tests                                     //
///////////////////////////////////////////////////////////////////////////////////

bool testCity_SegelProvided(){
    bool result = true;
    OPEN_FILE(out, FILE_PATH + std::string("/your_outputs/testCity_SegelProvided.txt"))
    City city ("TLV");
    Skill skill1(1,"Programming with c++",0);
    Skill skill2(2,"Programming with c",10);
    city.addEmployee(11, "John", "Williams", 2002);
    city.addEmployee(12, "Alex", "Martinez", 2000);
    city.addEmployee(13, "Lionel", "Smith", 2000);
    city.addManager(104,"Mohamad","Masarwa",1998);
    FacultyCondition3 fc3;
    FacultyCondition4 fc4;
    city.addFaculty(1001, skill1, 10, &fc3);
    city.addFaculty(1002, skill2, 15, &fc4);
    city.teachAtFaculty(11,1001);
    city.teachAtFaculty(11,1002);
    city.teachAtFaculty(12,1001);
    city.teachAtFaculty(13,1001);
    city.createWorkPlace(10001, "Meta", 10000, 20000);
    city.hireManagerAtWorkplace(104,10001);
    HiringCondition6 hiringCondition;
    city.hireEmployeeAtWorkplace(hiringCondition, 11, 104, 10001);
    city.hireEmployeeAtWorkplace(hiringCondition, 12, 104, 10001);
    city.hireEmployeeAtWorkplace(hiringCondition, 13, 104, 10001);
    city.fireEmployeeAtWorkplace(12,104,10001);
    out << "printAllAboveSalary output: " << endl;
    city.printAllAboveSalary(out,1000);
    out << endl << "printAllEmployeesWithSkill output" << endl;
    city.printAllEmployeesWithSkill(out, 1);
    city.fireManagerAtWorkplace(104,10001);
    out << "printAllAboveSalary output: " << endl;
    city.printAllAboveSalary(out,1000);
    out << endl << "printAllEmployeesWithSkill output" << endl;
    city.printAllEmployeesWithSkill(out, 1);
    ASSERT(matchFiles(fileName, FILE_PATH + std::string("/expected/city_test_output.txt")))
    return result;
}

bool testCity(){
    bool result = true;
    OPEN_FILE(out, FILE_PATH + std::string("/your_outputs/testCity.txt"))
    City city ("HAIFA");
    Skill skill1(1,"skill 1",0);
    Skill skill2(2,"skill 2",5);
    Skill skill3(3,"skill 3",10);
    Skill skill4(4,"skill 4",15);
    Skill skill5(5,"skill 5",20);
    city.addEmployee(11, "employee_1", "last_1", 1998);
    out << "++ Exceptions: addEmployee ++" << endl;
    try {
        city.addEmployee(11, "employee_1", "last_1", 1998);
    }
    catch (mtm::CitizenAlreadyExists&) {
        out << "CitizenAlreadyExists" << endl;
    }
    try {
        city.addEmployee(11, "???", "???", 2022);
    }
    catch (mtm::CitizenAlreadyExists&) {
        out << "CitizenAlreadyExists" << endl;
    }
    city.addEmployee(12, "employee_2", "last_2", 1999);
    city.addEmployee(13, "employee_3", "last_3", 2000);
    city.addEmployee(14, "employee_4", "last_4", 2001);
    city.addEmployee(15, "employee_5", "last_5", 2002);
    city.addManager(101,"manager_1","last_1",1990);
    out << endl << "++ Exceptions: addManager ++" << endl;
    try {
        city.addManager(11,"manager_1","last_1",1990);
    }
    catch (mtm::CitizenAlreadyExists&) {
        out << "CitizenAlreadyExists" << endl;
    }
    try {
        city.addManager(101,"manager_1","last_1",1990);
    }
    catch (mtm::CitizenAlreadyExists&) {
        out << "CitizenAlreadyExists" << endl;
    }
    try {
        city.addManager(101, "???", "???", 2022);
    }
    catch (mtm::CitizenAlreadyExists&) {
        out << "CitizenAlreadyExists" << endl;
    }
    city.addManager(102,"manager_2","last_2",1990);
    city.addManager(103,"manager_3","last_3",1990);
    city.addManager(104,"manager_4","last_4",1990);
    city.addManager(105,"manager_5","last_5",1990);
    FacultyCondition3 fc3;
    FacultyCondition4 fc4;
    FacultyCondition5 fc5;
    FacultyCondition6 fc6;
    city.addFaculty(1001, skill1, 5, &fc3);
    out << endl << "++ Exceptions: addFaculty ++" << endl;
    try {
        city.addFaculty(1001, skill1, 5, &fc3);
    }
    catch (mtm::FacultyAlreadyExists&) {
        out << "FacultyAlreadyExists" << endl;
    }
    city.addFaculty(1002, skill2, 10, &fc6);
    city.addFaculty(1003, skill3, 15, &fc5);
    city.addFaculty(1004, skill4, 20, &fc5);
    city.addFaculty(1005, skill5, 25, &fc3);
    city.createWorkPlace(10001, "WorkPlace 1", 10000, 20000);
    out << endl << "++ Exceptions: createWorkPlace ++" << endl;
    try {
        city.createWorkPlace(10001, "WorkPlace 1", 10000, 20000);
    }
    catch (mtm::WorkplaceAlreadyExists&) {
        out << "WorkplaceAlreadyExists" << endl;
    }
    city.createWorkPlace(10002, "WorkPlace 2", 15000, 25000);
    city.hireManagerAtWorkplace(101, 10001);
    out << endl << "++ Exceptions: hireManagerAtWorkplace ++" << endl;
    try {
        city.hireManagerAtWorkplace(108, 10001);
    }
    catch (mtm::ManagerDoesNotExists&) {
        out << "ManagerDoesNotExists" << endl;
    }
    try {
        city.hireManagerAtWorkplace(101, 10008);
    }
    catch (mtm::WorkplaceDoesNotExists&) {
        out << "WorkplaceDoesNotExists" << endl;
    }  
    try {
        city.hireManagerAtWorkplace(101, 10001);
    }
    catch (mtm::ManagerAlreadyHired&) {
        out << "ManagerAlreadyHired" << endl;
    }  
    try {
        city.hireManagerAtWorkplace(101, 10002);
    }
    catch (mtm::CanNotHireManager&) {
        out << "CanNotHireManager" << endl;
    }  
    city.hireManagerAtWorkplace(102, 10001);
    city.hireManagerAtWorkplace(103, 10001);
    city.hireManagerAtWorkplace(104, 10001);
    city.hireManagerAtWorkplace(105, 10002);
    HiringCondition1 hiringCondition1;
    HiringCondition2 hiringCondition2;
    HiringCondition2 hiringCondition3;
    out << endl << "++ Exceptions: hireEmployeeAtWorkplace ++" << endl;
    try {
        city.hireEmployeeAtWorkplace(hiringCondition2, 11, 101, 10001);
    }
    catch (mtm::EmployeeNotSelected&) {
        out << "EmployeeNotSelected" << endl;
    }
    try {
        city.hireEmployeeAtWorkplace(hiringCondition1, 11, 105, 10001);
    }
    catch (mtm::ManagerIsNotHired&) {
        out << "ManagerIsNotHired" << endl;
    }
    city.hireEmployeeAtWorkplace(hiringCondition1, 11, 101, 10001);
    city.hireEmployeeAtWorkplace(hiringCondition1, 12, 101, 10001);
    try {
        city.hireEmployeeAtWorkplace(hiringCondition1, 11, 101, 10001);
    }
    catch (mtm::EmployeeAlreadyHired&) {
        out << "EmployeeAlreadyHired" << endl;
    } 
    try {
        city.hireEmployeeAtWorkplace(hiringCondition2, 18, 101, 10001);
    }
    catch (mtm::EmployeeDoesNotExists&) {
        out << "EmployeeDoesNotExists" << endl;
    }
    try {
        city.hireEmployeeAtWorkplace(hiringCondition2, 11, 108, 10001);
    }
    catch (mtm::ManagerDoesNotExists&) {
        out << "ManagerDoesNotExists" << endl;
    }
    try {
        city.hireEmployeeAtWorkplace(hiringCondition2, 11, 101, 10008);
    }
    catch (mtm::WorkplaceDoesNotExists&) {
        out << "WorkplaceDoesNotExists" << endl;
    }
    city.teachAtFaculty(11,1001);
    city.teachAtFaculty(12,1001);
    city.teachAtFaculty(13,1001);
    city.teachAtFaculty(14,1001);
    out << endl << "++ Exceptions: teachAtFaculty ++" << endl;
    try {
        city.teachAtFaculty(18,1001);
    }
    catch (mtm::EmployeeDoesNotExists&) {
        out << "EmployeeDoesNotExists" << endl;
    }
    try {
        city.teachAtFaculty(11,1008);
    }
    catch (mtm::FacultyDoesNotExists&) {
        out << "FacultyDoesNotExists" << endl;
    }
    try {
        city.teachAtFaculty(15,1005);
    }
    catch (mtm::CanNotLearnSkill&) {
        out << "CanNotLearnSkill" << endl;
    }
    try {
        city.teachAtFaculty(11,1001);
    }
    catch (mtm::SkillAlreadyLearned&) {
        out << "SkillAlreadyLearned" << endl;
    }
    try {
        city.teachAtFaculty(12,1002);
    }
    catch (mtm::EmployeeNotAccepted&) {
        out << "EmployeeNotAccepted" << endl;
    }
    city.teachAtFaculty(15,1001);
    city.teachAtFaculty(13,1002);
    city.teachAtFaculty(14,1002); 
    city.teachAtFaculty(15,1002);
    city.teachAtFaculty(13,1003);
    city.teachAtFaculty(14,1003); 
    city.teachAtFaculty(15,1003);    
    city.teachAtFaculty(13,1004);
    city.teachAtFaculty(14,1004); 
    city.teachAtFaculty(15,1004);  
    city.hireEmployeeAtWorkplace(hiringCondition1, 13, 102, 10001);
    city.hireEmployeeAtWorkplace(hiringCondition1, 14, 102, 10001);
    city.hireEmployeeAtWorkplace(hiringCondition2, 15, 105, 10002);
    city.teachAtFaculty(13,1005);
    city.teachAtFaculty(14,1005); 
    city.teachAtFaculty(15,1005); 
    city.hireEmployeeAtWorkplace(hiringCondition3, 15, 103, 10001);
    ASSERT(city.isWorkingInTheSameWorkplace(14,15) == true)
    out << endl << "printAllAboveSalary output:" << endl;
    city.printAllAboveSalary(out,1);
    out << endl << "printAllEmployeesWithSkill output:" << endl;
    city.printAllEmployeesWithSkill(out, 1);
    out << endl << "printAllEmployeesWithSkill output:" << endl;
    city.printAllEmployeesWithSkill(out, 2);
    city.fireEmployeeAtWorkplace(15, 103, 10001);
    out << endl << "printAllAboveSalary output:" << endl;
    city.printAllAboveSalary(out,20000);
    ASSERT(city.isWorkingInTheSameWorkplace(11,12) == true)
    ASSERT(city.isWorkingInTheSameWorkplace(11,13) == true)
    city.fireManagerAtWorkplace(101,10001);
    ASSERT(city.isWorkingInTheSameWorkplace(11,12) == false)
    ASSERT(city.isWorkingInTheSameWorkplace(11,13) == false)
    city.fireEmployeeAtWorkplace(13, 102, 10001);
    out << endl << "printAllAboveSalary output:" << endl;
    city.printAllAboveSalary(out,1);
    out << endl << "++ Exceptions: fireEmployeeAtWorkplace ++" << endl;
    try {
        city.fireEmployeeAtWorkplace(18, 101, 10001);
    }
    catch (mtm::EmployeeDoesNotExists&) {
        out << "EmployeeDoesNotExists" << endl;
    }
    try {
        city.fireEmployeeAtWorkplace(11, 108, 10001);
    }
    catch (mtm::ManagerDoesNotExists&) {
        out << "ManagerDoesNotExists" << endl;
    }
    try {
        city.fireEmployeeAtWorkplace(11, 101, 10008);
    }
    catch (mtm::WorkplaceDoesNotExists&) {
        out << "WorkplaceDoesNotExists" << endl;
    }
    try {
        city.fireEmployeeAtWorkplace(13, 102, 10001);
    }
    catch (mtm::EmployeeIsNotHired&) {
        out << "EmployeeIsNotHired" << endl;
    }
    try {
        city.fireEmployeeAtWorkplace(11, 101, 10001);
    }
    catch (mtm::ManagerIsNotHired&) {
        out << "ManagerIsNotHired" << endl;
    }
    out << endl << "++ Exceptions: fireManagerAtWorkplace ++" << endl;
    try {
        city.fireManagerAtWorkplace(108,10001);
    }
    catch (mtm::ManagerDoesNotExists&) {
        out << "ManagerDoesNotExists" << endl;
    }
    try {
        city.fireManagerAtWorkplace(101,10008);
    }
    catch (mtm::WorkplaceDoesNotExists&) {
        out << "WorkplaceDoesNotExists" << endl;
    }
    try {
        city.fireManagerAtWorkplace(101,10001);
    }
    catch (mtm::ManagerIsNotHired&) {
        out << "ManagerIsNotHired" << endl;
    }
    out << endl << "++ Exceptions: isWorkingInTheSameWorkplace ++" << endl;
    try {
        city.isWorkingInTheSameWorkplace(11,18);
    }
    catch (mtm::EmployeeDoesNotExists&) {
        out << "EmployeeDoesNotExists" << endl;
    }
    try {
        city.isWorkingInTheSameWorkplace(18,11);
    }
    catch (mtm::EmployeeDoesNotExists&) {
        out << "EmployeeDoesNotExists" << endl;
    }
    city.fireManagerAtWorkplace(102,10001);
    city.fireManagerAtWorkplace(103,10001);
    city.fireManagerAtWorkplace(104,10001);
    city.fireManagerAtWorkplace(105,10002);
    out << endl << "printAllAboveSalary output:" << endl;
    city.printAllAboveSalary(out,1);
    out << endl << "printAllEmployeesWithSkill output:" << endl;
    city.printAllEmployeesWithSkill(out, 6);
    out << endl << "printAllEmployeesWithSkill output:" << endl;
    city.printAllEmployeesWithSkill(out, 5);
    out << endl << "printAllAboveSalary output:" << endl;
    city.printAllAboveSalary(out,0);
    ASSERT(matchFiles(fileName, FILE_PATH + std::string("/expected/testCity.txt")))
    return result;
}

///////////////////////////////////////////////////////////////////////////////////
//                                  Main                                         //
///////////////////////////////////////////////////////////////////////////////////

#define NUMBER_OF_TESTS 14

#define TEST_NAMES \
    X(testConstructorSkill) \
    X(testBooleanOperatorsSkill) \
    X(testArithmeticOperatorsSkill) \
    X(testExceptionsSkill)  \
    X(testEmployee_SegelProvided) \
    X(testEmployee) \
    X(testManager_SegelProvided) \
    X(testManager) \
    X(testWorkplace_SegelProvided) \
    X(testWorkplace) \
    X(testFaculty_segalProvided) \
    X(testFaculty) \
    X(testCity_SegelProvided) \
    X(testCity)


const char* testNames[] = {
    #define X(name) #name,
        TEST_NAMES
    #undef X
};

bool (*tests[])(void) = {
    #define X(test_name) test_name,
        TEST_NAMES
    #undef X
};

int main(int argc, char* argv[]) {
    cout << "\nRUNNING IDAN'S TESTS... GOOD LUCK =]\n" << endl;
    if (argc < 2) {
        for (int i = 0; i < NUMBER_OF_TESTS; i++) {
            RUN_TEST(tests[i], testNames[i])
        }
    }
    else if (argc > 2) {
        std::cout << "invalid arguments" << std::endl;
    }
    else {
        int i = std::atoi(argv[1]);
        tests[i - 1]();
    }
    return 0;
}
