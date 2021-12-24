#include <string>
#include <fstream>
#include <iostream>
#include "Skill.h"

using std::ostream;
using std::cout;
using std::endl;
using std::string;
using namespace mtm;

int main() {
    Skill s1(1, "C++", 0, 10);
    cout << "hello";
    cout << s1;
    return 0;
}
