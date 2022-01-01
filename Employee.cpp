#include "Employee.h"
#include "exceptions.h"
//#include "Faculty.h"

namespace mtm {
    Employee::Employee (int id_citizen, string first_name, string last_name, int birth_year): 
        Citizen(id_citizen, first_name, last_name, birth_year),
        salary(STARTING_SALARY),
        score(STARTING_SCORE),
        skill_set()
    {
    }

    Employee::Employee (const Employee& employee):
        Citizen(employee),
        salary(employee.getSalary()),
        score(employee.getScore())
    {
        skill_set = employee.skill_set;
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

    bool Employee::hasSkill (int skill_id) const
    {
        Skill temp_skill(skill_id, "temp", 0);
        set<Skill>::iterator ptr;
        for(ptr = skill_set.begin(); ptr != skill_set.end(); ++ ptr){
            if(temp_skill == *(ptr))
                return true;
        }
        return false;
    }

    void Employee::learnSkill (const Skill& skill) {
        if(hasSkill(skill.getId()) == true){
            throw SkillAlreadyLearned(); 
        }
        if (getScore() < skill.getRequiredPoints()){
            throw canNotLearnSkill();
        }
        skill_set.insert(skill);
    }

    void Employee::forgetSkill (const int id_skill){
        if (hasSkill(id_skill) == false){
            throw DidNotLearnSkill(); 
        }
        Skill temp_skill(id_skill, "temp", 0);
        skill_set.erase(skill_set.find(temp_skill));
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

    ostream& Employee::printShort (ostream& os) const
    {
        os << getFirstName() << " " << getLastName() << endl
        << "Salary: " << getSalary() << " Score: " << getScore() << endl;
        return os;
    }

    ostream& Employee::printLong (ostream& os) const
    {
        set<Skill>::iterator print_iterator;
        os << getFirstName() << " " << getLastName() << endl
        << "id - " << getId() << " " << "birth_year - " << getBirthYear() << endl
        << "Salary: " << getSalary() << " Score: " << getScore();
        if(skill_set.empty() == false){ 
            os  << " Skills:" << endl;
            for (print_iterator = skill_set.begin(); print_iterator != skill_set.end(); ++print_iterator) {
                os << ((*print_iterator).getName()) << endl;
            }
            return os;
        }
        os << endl;
        return os;
    }

}
