#include "Dry.h"
//q5 part 5.1

template <class T>
vector<T> slice(std::vector<T> vec, int start, int step, int stop)
{
    if(start < MIN || start >= vec.size()){
        throw BadInput;
    }
    if(stop < MIN || stop > vec.size()){
        throw BadInput;
    }
    if(step <= MIN){
        throw BadInput;
    }
    if(start >= stop){
        vector<T> empty_vector;
        return empty_vector;
    }
    vector<T> new_vector;
    for(int it = start; it < stop; it+=step){
        new_vector.push_back(vec[it]);
    }
    return new_vector;
}

//q5 part 5.2
class A {
public:
    std::vector<int*> values;
    A ();
    ~A ();
    void add(int x) { values.push_back(new int(x)); }

};

//A class methods
A::A():
    values()
{
}

A::~A()
{
    for(int it = 0; it < values.size(); ++it){
        delete values[it];
    }
}


int main() {
    A a, sliced;
    a.add(0); a.add(1); a.add(2); a.add(3); a.add(4); a.add(5);
    sliced.values = slice(a.values, 1, 1, 4);
    *(sliced.values[0]) = 800;
    std::cout << *(a.values[1]) << std::endl;
    return 0;
}

