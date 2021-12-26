#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

namespace mtm {
    class Exception: public std::exception {
    };

    // IllegalEmployee - in case the user sends illegal argument to function
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
    
} 


#endif /* EXCEPTION_H */