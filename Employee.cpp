#include "Employee.h"
#include "exception.h"
//#include "Faculty.h"

namespace mtm {
    Employee::Employee (int id_citizen, string first_name, string last_name, int birth_year): 
        Citizen(id_citizen, first_name, last_name, birth_year),
        salary(STARTING_SALARY),
        score(STARTING_SCORE),
        skill_set()
    {
    }

    Citizen* Employee::clone () const //בדוק שלא אותם שדות ולא אותה כתובת אבל אותו תוכן
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
            //throw SkillAlreadyLearned(); 
        }
       if (getScore() < skill.getRequiredPoints()){
            //throw canNotLearnSkill();
        }
        skill_set.insert (skill);
    }

    void Employee::forgetSkill (const int id_skill){
        if (hasSkill(id_skill) == false){
            //throw DidNotLearnSkill(); 
        }
        Skill temp_skill(id_skill, "temp", 0);
        skill_set.erase(skill_set.find(temp_skill));
    }

    bool Employee::hasSkill (const int id_skill){
        Skill temp_skill(id_skill, "temp", 0);
        if (temp_skill == *(skill_set.find(temp_skill))){
            return true;
        }
        return false;
    }

    void Employee::setSalary (int salary_to_add){
        if ((salary+salary_to_add) <= STARTING_SALARY){
            salary = STARTING_SALARY;
            return;
        }
        salary += salary_to_add; 
    }

    void Employee::setScore (int score_to_add){
        if ((score+score_to_add) <= STARTING_SCORE) {
            score = STARTING_SCORE;
            return;
        }
        score += score_to_add;
    }

    ostream& Employee::printShort (ostream& os)
    {
        os << getFirstName() << " " << getLastName() << endl
        << "Salary: " << salary << " Score: "<< score << endl;
        return os;
    }

    ostream& Employee::printLong (ostream& os)
    {
        set<Skill>::iterator print_iterator;
        os << getFirstName() << " " << getLastName() << endl
        << "id - " << getId() << " " << "birth_year - " << getBirthYear() << endl
        << "Salary: " << salary << " Score: "<< score << " Skills:" << endl;
        for (print_iterator=skill_set.begin(); print_iterator!=skill_set.end(); ++print_iterator) {
            os << ((*print_iterator).getName()) << endl;
        }
        return os;
    }

}
