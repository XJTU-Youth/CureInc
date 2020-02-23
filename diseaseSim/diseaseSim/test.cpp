#include "City.h"

using namespace std;

int main()
{
	City Wuhan(10000, 200, 0.0, 0.03, 0.002, 1, 3, 0.5, 0.5);
	while (Wuhan._move());
	return 0;
}