#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

namespace mtm {
    class Exception: public std::exception {
    };

    class NegativePoints: public Exception {
    };

    class IllegalEmployee: public Exception {
    };

    class EmployeeAlreadyHired: public Exception {
    };

    class EmployeeNotHired: public Exception {
    };

    class SkillAlreadyLearned: public Exception {
    };
    
    class EmployeeNotAccepted: public Exception {
    };

    class canNotLearnSkill: public Exception {
    };
    
    class DidNotLearnSkill: public Exception {
    };

    class EmployeeNotSelected: public Exception {
    };

    class ManagerIsNotHired: public Exception {
    };
    
    class ManagerAlreadyHired: public Exception {
    };

    class EmployeeIsNotHired: public Exception {
    };
    
    class EmployeeAlreadyExists: public Exception {
    };

    class ManagerAlreadyExists: public Exception {
    };

    class FacultyAlreadyExists: public Exception {
    };

    class WorkplaceAlreadyExists: public Exception {
    };

    class EmployeeDoesNotExists: public Exception {
    };

    class FacultyDoesNotExist: public Exception {
    };

    class ManagerDoesNotExist: public Exception {
    };

    class EmployeeDoesNotExist: public Exception {
    };

    class WorkplaceDoesNotExist: public Exception {
    };
    
    class CanNotHireManager: public Exception {
    };
} 


#endif /* EXCEPTION_H */