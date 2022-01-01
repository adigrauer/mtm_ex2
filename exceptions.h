#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

namespace mtm {
    class Exception: public std::exception {
    };

    /*-----skill exceptions----- */

    /* in case of getting negativ pointes to add to skill's score to gain*/
    class NegativePoints: public Exception {
    };

    /*-----Employee eceptions----- */

    /* in case that employee already has the skill */
    class SkillAlreadyLearned: public Exception {
    };

    /* in case that we try to forget skiil the employee dont have */
    class DidNotLearnSkill: public Exception {
    };

    /* in case that given emmployee cant learn skill due to lower points than needed togain the skill */
    class canNotLearnSkill: public Exception {
    };
    
    /*-----Manager eceptions----- */

    /* in case we try to add employee that had already hired by given manager */
    class EmployeeAlreadyHired: public Exception {
    };

    /* in case we try to remove employee that had not hired by given manager */
    class EmployeeNotHired: public Exception {
    };

    /*-----Workplace eceptions----- */

    /* employee dont exist the condition, therefore cant be hired by given workplace */
    class EmployeeNotSelected: public Exception {
    };

    /* in case we try to hire employee by manager that does not exist in given workplace */ 
    class ManagerIsNotHired: public Exception {
    };

    /* in case that manager already hired in given workplace */
    class ManagerAlreadyHired: public Exception {
    };
    
    /* in case that given manager already works in different workplace */
    class CanNotHireManager: public Exception {
    };

    /* in case we try to fire employye that is not hired by given manager */ 
    class EmployeeIsNotHired: public Exception {
    };
    
    /*-----Faculty eceptions----- */
    
    /* employee dont exist the condition, therefore cant learn the skiil of given faculty */
    class EmployeeNotAccepted: public Exception {
    };

    /*-----City eceptions----- */

    /* employee already exist in given city */ 
    class EmployeeAlreadyExists: public Exception {
    };

    /* manager already exist in given city */ 
    class ManagerAlreadyExists: public Exception {
    };

    /* faculty already exist in given city */ 
    class FacultyAlreadyExists: public Exception {
    };

    /* workplace already exist in given city */ 
    class WorkplaceAlreadyExists: public Exception {
    };

    /* employee does not exist in given city */
    class EmployeeDoesNotExists: public Exception {
    };

    /* faculty does not exist in given city */
    class FacultyDoesNotExist: public Exception {
    };

    /* manager does not exist in given city */
    class ManagerDoesNotExist: public Exception {
    };

    /* workplace does not exist in given city */
    class WorkplaceDoesNotExist: public Exception {
    };

} 

#endif /* EXCEPTION_H */