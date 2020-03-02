#include "government.h"

int main()
{
	/*
	area Area;
	Area.loadFromYaml("test.yaml");
	Area._move();
	Area._move();
	Area.saveToYaml("test2.yaml");
	return 0;
	*/
	government Gov(1000000, 20, 1000);
	Gov.Start();
	while(Gov._move());
	Gov.save_exit();
	return 0;
}
