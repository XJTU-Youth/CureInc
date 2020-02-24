#include "City.h"
#include <ctime>
using namespace std;

/*int main()
{
	City Wuhan(50000000, 2000, 0.05, 0.0000000001, 20, 14, 3, 0.5, 0.5);
	while (Wuhan._move());
		_getch();
	return 0;
}*/

double random_unint(unsigned int min, unsigned int max, unsigned int seed = 0)
{
	static std::default_random_engine e(seed);
	static std::uniform_real_distribution<double> u(min, max);
	return u(e);
}

/*int main()
{
	int i = 10;
	for (int j = 0; j < 20; j++)
	{
		i *= 1 + random_unint(0.1, 1, time(nullptr));
		cout << i << endl;
	}
	return 0;
}*/