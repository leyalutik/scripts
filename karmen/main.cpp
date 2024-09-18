#include<iostream>
#include<algorithm>
#include<map>
#include<cmath>

int main()
{

int n = 1;

while((100*n*n) > (std::pow(2,n)))
{
++n;
}

std::cout << "n= " << n << "\n";
std::cout << "100*N*N = " << 100*n*n << " 2^n= " << std::pow(2,n) << "\n";


n = 1;
while((log2(n)) <= std::pow(10,6))
{
	++n;
	std::cout << "n = " << n << " log2 (n) " << log2(n) << "\n";
}

std::cout << "n = " << n << "log2 n = 10^6, n=" << n << "\n";



return 0;
}
