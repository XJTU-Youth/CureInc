#include "City.h"

using namespace std;

int main()
{
	City Wuhan(10000000, 2000, 0.05, 0.000001, 0.002, 14, 3, 0.5, 0.5);
	while (Wuhan._move())
		_getch();
	return 0;
}