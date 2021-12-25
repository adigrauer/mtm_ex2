#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

namespace mtm {
    class Exception: public std::exception {
    };

    // IllegalEmployee - in case the user sends illegal argument to function
    class IllegalEmployee: public Exception {
        public:
            const char* what() const noexcept override;
    };

    //and so on classes like that


} 


#endif /* EXCEPTION_H */