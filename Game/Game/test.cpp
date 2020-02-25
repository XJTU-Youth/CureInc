#include "government.h"

int main()
{
	area Area(5000000, 20, 1000);
	Area.saveToYaml("test.yaml");
	return 0;
}