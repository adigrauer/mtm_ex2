#include "City.h"

namespace mtm {
    City::City (string city_name):
        city_name(city_name),
        citizens(),
        faculties(),
        workplaces()
    {
    }

    City::City (const City& city):
        city_name(city.getName())
    {
        citizens = city.citizens;
        faculties = city.faculties;
        workplaces = city.workplaces;
    }

    string City::getName () const
    {
        return city_name;
    }

    bool City::checkIfEmployeeExistInCity (int id_citizen)
    {
        if (citizens.empty() == true) 
        {
            return false;
        }
        vector<shared_ptr<Citizen>>::iterator ptr;
        for(ptr = citizens.begin(); ptr != citizens.end(); ++ptr){
            if((**ptr).getId() == id_citizen){
                return true;;
            }
        }
        return false; 
    }

    void City::addEmployee (int id_citizen, string first_name, string last_name, int birth_year) 
    {
        if(checkIfEmployeeExistInCity(id_citizen) == true){
             throw EmployeeAlreadyExists();
        }
        //Employee* employee = new Employee(id_citizen, first_name, last_name, birth_year);
        //shared_ptr<Employee> employee_to_add(employee);
        shared_ptr<Employee> employee_to_add(new Employee(id_citizen, first_name, last_name, birth_year));
        citizens.push_back(employee_to_add);
    }

    ////code duplication!!!!!!!!!!
    bool City::checkIfManagerExistInCity (int id_citizen)
    {
         if (citizens.empty() == true) 
        {
            return false;
        }
        vector<shared_ptr<Citizen>>::iterator ptr;
        Manager temp_manager(id_citizen, "temp", "temp", 0);
        for(ptr = citizens.begin(); ptr != citizens.end(); ++ptr){
            if(**ptr == temp_manager){
                return true;;
            }
        }
        return false;
    }

    void City::addManager (int id_citizen, string first_name, string last_name, int birth_year) 
    {
        if(checkIfManagerExistInCity(id_citizen) == true){
            throw ManagerAlreadyExists();
        }
        //Manager* manager = new Manager(id_citizen, first_name, last_name, birth_year);
        shared_ptr<Manager> manager_to_add(new Manager(id_citizen, first_name, last_name, birth_year));
        citizens.push_back(manager_to_add);
    }

    void City::addFaculty (int faculty_id, Skill skill, int point_to_add, compareFunction compare_function)
    {
        Faculty faculty_to_add(compare_function, skill, point_to_add, faculty_id);
        vector<Faculty>::iterator ptr;
        for(ptr = faculties.begin(); ptr != faculties.end(); ++ptr){
            if(*ptr == faculty_to_add){
                faculties.push_back(faculty_to_add);
            }
        }
        throw FacultyAlreadyExists();
    }

    bool City::checkIfWorkplaceExistInCity (int workplace_id)
    {
        vector<WorkPlace>::iterator ptr;
        for(ptr = workplaces.begin(); ptr != workplaces.end(); ++ptr){
            if((*ptr).getID() == workplace_id){
                return true;
            }
        }
        return false;
    }

    //workplace cant have negative salary, witch error to return
    void City::createWorkPlace (int workplace_id, string workplace_name, int workers_salary, int managers_salary)
    {
        WorkPlace workplace_to_add(workplace_id, workplace_name, workers_salary, managers_salary);
        if(checkIfWorkplaceExistInCity (workplace_id) == true){
            throw WorkplaceAlreadyExists();
        }
        workplaces.push_back(workplace_to_add); 
    }

    Faculty& City::findFacultybById (int faculty_id) 
    {
        vector<Faculty>::iterator ptr;
        for(ptr = faculties.begin(); ptr != faculties.end(); ++ptr){
            if((*ptr).getId() == faculty_id){
                return *ptr;
            }
        }
        throw FacultyDoesNotExist();
    }

    void City::teachAtFaculty (int employee_id, int faculty_id) 
    {
        vector<shared_ptr<Citizen>>::iterator ptr;
        Faculty faculty = findFacultybById(faculty_id);
        Employee temp_employee (employee_id, "temp", "temp", 0);
        if(checkIfEmployeeExistInCity(employee_id) == false){
            throw EmployeeDoesNotExists();
        }
        Employee* employee_to_teach = findEmployeeByIdInCity(employee_id);
        faculty.teach(employee_to_teach); 
    }

    WorkPlace& City::findWorkplaceById (int workplace_id) 
    {
        vector<WorkPlace>::iterator ptr;
        for(ptr = workplaces.begin(); ptr != workplaces.end(); ++ptr){
            if((*ptr).getID() == workplace_id){
                return *ptr;
            }
        }
        return *ptr; 
        ////////////////////what to return here in cade of endind the for loop///////////
    }

    Manager* City::findManagerByIdInCity (int manager_id) 
    {
        vector<shared_ptr<Citizen>>::iterator ptr;
        Manager* manager = NULL;
        for(ptr = citizens.begin(); ptr != citizens.end(); ++ptr){
            if((**ptr).getId() == manager_id){
                manager = dynamic_cast<Manager*>((*ptr).get());
                return manager;
            }
        }
        return manager;
        ////////////////////what to return here in cade of endind the for loop///////////
    }

    Employee* City::findEmployeeByIdInCity (int employee_id) 
    {
        vector<shared_ptr<Citizen>>::iterator ptr;
        Employee* manager = NULL;
        for(ptr = citizens.begin(); ptr != citizens.end(); ++ptr){
            if((**ptr).getId() == employee_id){
                manager = dynamic_cast<Employee*>((*ptr).get());
                return manager;
            }
        }
        return manager;
        ////////////////////what to return here in cade of endind the for loop///////////
    }

    void City::hireManagerAtWorkplace (int manager_id, int workplace_id)
    {
        if(checkIfManagerExistInCity(manager_id) == false){
            throw ManagerDoesNotExist();
        }
        if(checkIfWorkplaceExistInCity(workplace_id) == false){
            throw WorkplaceDoesNotExist();
        }
        WorkPlace workplace_to_add_manager = findWorkplaceById(workplace_id);
        Manager* manager_to_hire = findManagerByIdInCity(manager_id); 
        workplace_to_add_manager.hireManager(manager_to_hire);
    }

    void City::fireManagerAtWorkplace (int manager_id, int workplace_id)
    {
        if(checkIfManagerExistInCity(manager_id) == false){
            throw ManagerDoesNotExist();
        }
        if(checkIfWorkplaceExistInCity(workplace_id) == false){
            throw WorkplaceDoesNotExist();
        }
        WorkPlace workplace_to_fire_manager = findWorkplaceById(workplace_id);
        workplace_to_fire_manager.fireManager(manager_id);
        ////////////////////will all his workers be deletet by this function?????///////////
    }

    void City::fireEmployeeAtWorkplace (int employee_id, int manager_id, int workplace_id)
    {
        if(checkIfEmployeeExistInCity(employee_id) == false){
                throw EmployeeDoesNotExist();
        }
        if(checkIfManagerExistInCity(manager_id) == false){
            throw ManagerDoesNotExist();
        }
        if(checkIfWorkplaceExistInCity(workplace_id) == false){
            throw WorkplaceDoesNotExist();
        }
        WorkPlace workplace_to_fire_manager = findWorkplaceById(workplace_id);
        workplace_to_fire_manager.fireEmployee(employee_id, manager_id);
    }
    /*
    ostream& City::getAllAboveSalary (ostream&, int salary_to_print)
    {

    }

    bool City::isWorkingInTheSameWorkplace (int worker_a_id, int worker_b_id)
    {
        if(checkIfEmployeeExistInCity(worker_a_id) == false || checkIfEmployeeExistInCity(worker_b_id) == false){
            throw EmployeeDoesNotExist();
        }

    }

    void City::printAllEmployeesWithSkill (ostream& os) const
    {

    }
    */

}   