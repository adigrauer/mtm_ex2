//q5 part 5.1

#ifndef DRY_H
#define DRY_H

#include <exception>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

const int MIN  = 0;
const int BadInput = -1;

template <class T>
vector<T> slice(std::vector<T> vec, int start, int step, int stop);




#endif /* DRY_H */ 