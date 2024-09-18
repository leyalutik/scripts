#include <vector>
#include <iostream>

void insert(std::vector<int>& A)
{

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
}



int main()
{

	std::vector v = {};
			//{3,10,2,0};
	insert(v);
	
	bool first = true;
	for(auto& i:v)
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




	return 0;

}
