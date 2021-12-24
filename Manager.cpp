#include "Manager.h"
namespace mtm {
    Citizen* Manager::clone () const
    {
        return new Manager(*this);
    }
}
