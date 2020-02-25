#include "government.h"

int main()
{
	area Area;
	Area.loadFromYaml("test.yaml");
	Area._move();
	Area._move();
	Area.saveToYaml("test2.yaml");
	return 0;
}