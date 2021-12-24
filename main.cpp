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
    Skill s1(1, "a", 0, 0);
    cout << s1;
    Skill s2(2, "b", 1, 1);
    Skill s3(3, "c", 2, 2);
    if(s3 < s2)
        return -1;
    if(s3 <= s2)
        return -1;
    s2 += 2;
    s2++;
    cout << s2;
    return 0;
}
