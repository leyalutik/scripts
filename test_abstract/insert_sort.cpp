
#include "insert_sort.h"


void insert_sort(std::string& line)
{

//initialize
std::vector<int32_t> A;
modify_string_to_vec(line,A);

/*
if(A[0] > A[1])
{
	int key = A[0];
	A[0] = A[1];
	A[1] = key;
}
*/	for(int i=1; i< A.size(); ++i)
	{	int key = A[i];
		for(int j = i-1; j>=0; --j)
		{
			if(key >  A[j])
			{
			
				A[j+1] = key;
				break;
			}
			else if(j == 0 && key <= A[j])
			{
				A[j+1] = A[j];
				A[j] = key;
				break;
			}
			A[j+1] = A[j];
		}

	}
modify_vec_to_string(A,line);
}

<<<<<<< HEAD:karmen/insert_sort.cpp
#ifndef TEST_ABSTRACT_CPP
                 
=======

/*
>>>>>>> 25afba90a8f4690c6da805a24ee5ee805681fb8a:test_abstract/insert_sort.cpp

int main()
{

	std::string line = "1 2 3 4 1 2 3";
	insert_sort(line);
	
	std::cout << line << "\n";

	std::getchar();

	return 0;

}

<<<<<<< HEAD:karmen/insert_sort.cpp

  #endif
=======
*/

>>>>>>> 25afba90a8f4690c6da805a24ee5ee805681fb8a:test_abstract/insert_sort.cpp
