#include <iostream>
#include <vector>
#include <string>
#include<sstream>
#include<fstream>

void function(const std::vector<int32_t>& v, std::vector<int32_t>& result);
void read_line(const std::string& str, std::vector<int32_t>& v);
void display(const std::vector<int32_t>& v, const std::vector<int32_t>& result);
void output(const std::vector<int32_t>& v);
int main()
{

	const std::string FILENAME = "input.txt";
	std::ifstream read (FILENAME.c_str(), std::ios::out);
	std::string str;
	std::vector<int32_t>  v;
	std::vector<int32_t>  result;

	while(std::getline(read, str, '\n'))
	{
		read_line(str, v);
		function(v,result);

		display(v,result);

		v.clear();
		result.clear();


	}




	return 0;
}

//-------------------------------------------
void function(const std::vector<int32_t>& v, std::vector<int32_t>& result)
{

	//result.push_back();

	/*
	   if(A[0] > A[1])
	   {
	   int key = A[0];
	   A[0] = A[1];
	   A[1] = key;
	   }
	   */
	if(v.empty())
	{
		return;
	}
	for(const auto& e:v)
	{
		result.push_back(e);
	}

	for(int i=1; i< result.size(); ++i)
	{	int key = result[i];
		for(int j = i-1; j>=0; --j)
		{
			if(key >  result[j])
			{

				result[j+1] = key;
				break;
			}
			else if(j == 0 && key <= result[j])
			{
				result[j+1] = result[j];
				result[j] = key;
				break;
			}
			result[j+1] = result[j];
		}

	}
}



void read_line(const std::string& str, std::vector<int32_t>& v)
{



	std::stringstream stream(str);
	int32_t el;
	while(stream >> el)
	{
		v.push_back(el);
	}

}
void display(const std::vector<int32_t>& v, const std::vector<int32_t>& result)
{

	std::cout << "INPUT:  ";
	output(v);
	std::cout << "\n";
	std::cout << "OUTPUT: ";
	output(result);
	std::cout << "\n\n";


}

void output(const std::vector<int32_t>& v)
{
	bool first = true;

	std::cout << "{ ";
	for(const auto& e : v)
	{
		if(first)
		{
			first = false;
		}
		else if(!first)
		{
			std::cout << ", ";
		}
		std::cout << e;
	}
	std::cout << "}";
}
