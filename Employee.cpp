#include "Employee.h"

namespace mtm {
    Employee::Employee (int id_citizen, string first_name, string last_name, int birth_year): Citizen(id_citizen, first_name, last_name, birth_year){
        salary = 0;
        score = 0;
         set<Skill> skill_set;
    }
    Employee::~Employee () {
        skill_set.clear();
    }

    Citizen* Employee::clone () const
    {
        return new Employee(*this);
    }

    int Employee::getSalary() const{
        return salary;
    }

    int Employee::getScore()const{
        return score;
    }

    void Employee::learnSkill (const Skill& skill) {
        if (skill == *(skill_set.find(skill))){
            //throw SkillAlreadyLearned 
        }
        //try {
            Faculty::teach(skill);
        //} catch (EmployeeNotAccepted);
        // throw canNotLearnSkill
        skill_set.insert (skill);
    }
    void Employee::forgetSkill (const unsigned int id_skill){
        if (hasSkill(id_skill) == false){
            //throw DidNotLearnSkill 
        }
        Skill temp_skill(id_skill, "temp", 0,  0);
        skill_set.erase(skill_set.find(temp_skill));
    }

    bool Employee::hasSkill (const unsigned int id_skill){
        Skill temp_skill(id_skill, "temp", 0,  0);
        if (temp_skill == *(skill_set.find(temp_skill))){
            return true;
        }
        return false;
    }
    void Employee::setSalary (int salary_to_add){
        salary += salary_to_add; /*האם צריך לבדוק חוקיות*/
    }

    void Employee::setScore (int score_to_add){
        score += score_to_add; /*האם צריך לבדוק חוקיות*/
    }

    ostream& operator<< (ostream& os, const Employee& employee)
    {
        os << Employee.first_name << endl;
        os <<  "Salary:" << Employee.salary << "Score:" << Employee.score << endl;
        return os;
    }
    ostream& Employee::printShort (ostream& os)
    {
        << getFirstName() << " " << getLastName() << endl
        << "Salary: " << this->salary << "Score: "<< this->score << endl;
        return os;
    }

    ostream& Employee::printLong (ostream& os)
    {
        set<Skill>::iterator print_iterator;
        << getFirstName() << " " << getLastName() << endl
        << "id - " << getId() << " " << "birth_year - " << getBirthYear() << endl
        << "Salary: " << this->salary << "Score: "<< this->score << "Skills:" << endl
        for (print_iterator=skill_set.begin(); print_iterator!=skill_set.end(); ++it {
            << *print_iterator.name << endl
        }
        return os;
    }
    ////////////
    /*Skill Employee::findSkillById (const unsigned int id_skill){
        Skill temp_skill(id_skill, "temp", 0,  0);
        return (skill_set.find(temp_skill));
    }*/ //לא מצליחה לממש הערך החזרה וזה לא מסתדר לי
}