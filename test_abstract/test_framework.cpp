
#include "test_framework.h"




std::function<void(std::string&)> get_function(const std::string function_name)
{
	if(function_name == "insert_sort")
	{
		std::function<void(std::string&)> f = insert_sort;
		return f;
	}

	else
	{
	throw std::runtime_error("RUNTIME ERROR:\n No checking function.\n (Add #include <function_name.h> in test_framework.h\n Add function_name(string) in get_function(string) in test_framework.cpp\n Add argument FUNCTION=function_name in Makefile)");
	}
}

void display(const std::string& line)
{
	bool first = true;
	for(auto& i:line)
	{
		if(!first)
		{
			std::cout << "," ;
		}
		else
		{
			first = false;
		}
			std::cout << i;
	}

}
