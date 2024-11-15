


#ifndef FRAMEWORK_TEST_H

#define FRAMEWORK_TEST_H 1

#include <iostream>
#include <vector>
#include<string>
#include<functional>
#include<exception>

#include "insert_sort.h"





std::function<void(std::string&)> get_function(const std::string function_name);


void display(const std::string& line);


#endif
