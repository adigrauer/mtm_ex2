#include "City.h"

namespace mtm {
    City::City (string city_name):
        city_name(city_name),
        employees(),
        managers(),
        faculties(),
        workplaces()
    {
    }

    void City::addEmployee (int id_citizen, string first_name, string last_name, int birth_year) 
    {
        Employee employee (id_citizen, first_name, last_name, birth_year);
        if (employee == *(employees.find(employee))){
            throw EmployeeAlreadyExists();
        }
        employees.insert(employee);
    }

    void City::addManager (int id_citizen, string first_name, string last_name, int birth_year) 
    {
        Manager manager (id_citizen, first_name, last_name, birth_year);
        if (manager == *(managers.find(manager))){
            throw ManagerAlreadyExists();
        }
        managers.insert(manager);
    }

    void City::addFaculty (compareFunction compare_function, Skill skill, int point_to_add, int faculty_id)
    {
        Faculty faculty (compare_function, skill, point_to_add, faculty_id);
        if (faculty == *(faculties.find(faculty))){
            throw FacultyAlreadyExists();
        }
        faculties.insert(faculty);
    }

    void City::createWorkplace (int workplace_id, string workplace_name, int workers_salary, int managers_salary)
    {
        Workplace workplace (workplace_id, workplace_name, workers_salary, managers_salary);
        if (workplace == *(workplaces.find(workplace))){
            throw WorkplaceAlreadyExists();
        }
        workplaces.insert(workplace);
    }

    void City::teachAtFaculty (int employee_id, int faculty_id) 
    {
        Faculty faculty = findFacultybById(faculty_id);
        Employee temp_employee (employee_id, "temp", "temp", 0);
        if (temp_employee != *(employees.find(temp_employee))){
            throw EmployeeDoesNotExists();
        }
        Employee copy_employee(*(employees.find(temp_employee)));
        faculty.teach(&copy_employee); 
        employees.erase(temp_employee);
        employees.insert(copy_employee);
        /* **** צריך לפתור, אני רוצה להחליף את העובד הקודם אבל
        לא יודעת אם הוא עובד איפושו ואם צריך גם שם */
    }

    const Faculty City::findFacultybById (int id) 
    {
        set<Faculty>::iterator iterator;
        for (iterator = faculties.begin(); iterator != faculties.end(); ++iterator) {
            if ((*iterator).getId() == id){
                return *iterator;
            }
        }
        throw FacultyDoesNotExist();
    }
}   