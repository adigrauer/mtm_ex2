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
        T to_add = vec[it];
        new_vector.push_back(to_add);
    }
    return new_vector;
}

/*
void test_dry_1()
{
    // this syntax initializes a vector with values a,b,c,d,e
    vector<char> vec_char {'a', 'b', 'c', 'd', 'e'};
    // returns vector with values a,c
    vector<char> vec_sliced_1 = slice(vec_char, 0, 2, 4);
    cout << "print vec_sliced_1" << endl;
    for (unsigned int i = 0; i < vec_sliced_1.size(); i++){
            cout << vec_sliced_1[i] << " ";
    }
    cout << endl;
    // returns vector with values b,c,d,e
    vector<char> vec_sliced_2 = slice(vec_char, 1, 1, 5);
    cout << "print vec_sliced_2" << endl;
    for (unsigned int i = 0; i < vec_sliced_2.size(); i++){
            cout << vec_sliced_2[i] << " ";
    }
    cout << endl;
    vector<double> vec_double {0.2, 1.2, 2.2, 3.2, 4.2, 5.2, 6.2, 7.2, 8.2};
    // returns vector with values 0.2, 1.2, 2.2
    vector<double> vec_sliced_3 = slice(vec_double, 0, 1, 3);
    cout << "print vec_sliced_3" << endl;
    for (unsigned int i = 0; i < vec_sliced_3.size(); i++){
            cout << vec_sliced_3[i] << " ";
    }
    cout << endl;
    //returns vector with values 2.2, 4.2
    vector<double> vec_sliced_4 = slice(vec_double, 2, 2, 6);
    cout << "print vec_sliced_4" << endl;
    for (unsigned int i = 0; i < vec_sliced_4.size(); i++){
            cout << vec_sliced_4[i] << " ";
    }
    cout << endl;
}
*/

//q5 part 5.2
class A {
public:
    std::vector<int*> values;
    A ();
    A (const A& a);
    ~A ();
    A& operator= (const A& a);
    void add(int x);
};

//A class methods
A::A():
    values()
{
}

A::A (const A& a)
{
    for(unsigned int it = 0; it < (a.values).size(); ++it){
        values[it] = new int(*((a.values)[it]));
    }
}

A::~A()
{
    //change to unsigned int from int cause vector.size return unsigned int
    for(unsigned int it = 0; it < values.size(); ++it){
        int* temp = values[it];
        delete temp;
    }
}

A& A::operator= (const A& a)
{
    values = a.values;
    return *this;
}

//cant do new in initialization list
void A::add(int x)
{
    int* to_add = new int(x);
    values.push_back(to_add); 
}

int main() {
    A a, sliced;
    a.add(0); a.add(1); a.add(2); a.add(3); a.add(4); a.add(5);
    sliced.values = slice(a.values, 1, 1, 4);
    *(sliced.values[0]) = 800;
    std::cout << *(a.values[1]) << std::endl;
    return 0;
}





