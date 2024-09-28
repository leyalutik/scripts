#ifndef INSERT_SORT_H
#define INSERT_SORT_H

#include <vector>
#include <iostream>
#include <sstream>


void insert_sort(std::string& line);

template<class K>
void modify_string_to_vec( const std::string& line,std::vector<K>& v)
{
	if(v.size() != 0)
	{
		v.clear();
	}
	std::stringstream ss(line);
	size_t k = 0;
	size_t LIMIT = 3000000;
	K a;
	while(ss >> a && k < LIMIT)
	{

		v.push_back(a);	
		++k;
	}

}
template<class K>
void modify_vec_to_string( const std::vector<K>& v , std::string& line)
{
	if(!line.empty())
	{
		line.clear();
	}
	for(const auto& element : v)
	{
		line += std::to_string(element) + std::string(" ");
	}


}

#endif
