#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<utility>


double Newton_method_log2_n (const double time);
double Newton_method_sqrt_n (const double time);
double Newton_method_n (const double time);
double Newton_method_n_log2_n (const double time);
double Newton_method_n_2 (const double time);
double Newton_method_n_3 (const double time);
double Newton_method_2_n (const double time);
double Newton_method_n_factorial (const double time);

int main()
{

//	std::vector<std::function<double<const double>> = {Newton_method_log2_n, Newton_method_sqrt_n};

 std::vector<std::pair<std::string,int64_t>> list = {
	 {"second",1}, {"minute",60},{"hour", 60*60}, {"day",3600*24},
	 {"month", 3600*24*30}, {"year",3600*24*30*365},{"century", 3600*24*30*365*100}
 };

 for ( auto& m : list)
 {
	 std::cout << "f(n) = n (10-6) : t = " << m.first << " max n for t : " << Newton_method_n(m.second) << "\n";

	 std::cout << "f(n) = log2(n) (10-6) : t = " << m.first << " max n for t : " << Newton_method_log2_n(m.second) << "\n";


 }

	return 0;

}
//---------------------------------------------


double Newton_method_log2_n(const double time)
{
	double eps = 0.0000001;
	double x1,x2;
	x1 = 1;
	x2 = 2;
	double k = 0.000001;
	while(fabs(x2-x1) >= eps)
	{
		double temp = x2;
		x2 =x1- ((k*log2(x1)-time)/(k*(1./x1)*(1./log(2))) );
		x1 = temp;
		//	std::cout << "x1 = " << x1 << "; x2 = " << x2 << "\n";


	}
	return x2;
}

double Newton_method_n (const double time)
{

double eps = 0.00000001;
double x1,  x2;
x1 = 1;
x2 = -1;
double k = 0.000001;
while(fabs(x2-x1) >= eps)
{
	double temp = x2;
	x2 =x1 - ((k*x1-1*time)/k );
	x1 = temp;
//	std::cout << "x1 = " << x1 << "; x2 = " << x2 << "\n";
}

return x2;

}
