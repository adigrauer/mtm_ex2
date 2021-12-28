#include "City.h"

namespace mtm {
    City::City (string city_name):
        city_name(city_name),
        citizens(),
        faculties(),
        workplaces()
    {
    }

    void City::addEmployee (int id_citizen, string first_name, string last_name, int birth_year) 
    {
        shared_ptr<Employee> new_employee(new Employee(id_citizen, first_name, last_name, birth_year)); //need to free????
        vector<shared_ptr<Citizen>>::iterator ptr;
        for(ptr = citizens.begin(); ptr != citizens.end(); ++ptr){
            if(**ptr == *new_employee){
                throw EmployeeAlreadyExists();
            }
        }
        citizens.insert(ptr, new_employee);
    }

    void City::addManager (int id_citizen, string first_name, string last_name, int birth_year) 
    {
        shared_ptr<Manager> new_manager(new Manager(id_citizen, first_name, last_name, birth_year));
        vector<shared_ptr<Citizen>>::iterator ptr;
        for(ptr = citizens.begin(); ptr != citizens.end(); ++ptr){
            if(**ptr == *new_manager){
                throw ManagerAlreadyExists();
            }
        }
        citizens.insert(ptr, new_manager);
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
        if (workplace == *(workplaces.find(workplace))){ //need to add operator ==
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
    }

    Faculty& City::findFacultybById (int id) 
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