#pragma once
#include "area.h"
#include<assert.h>
#include<stdio.h>
using std::cout;
using std::cin;
using std::string;
class government
{
public:
	void new_game();
	void read_save();
	void save_exit();
	void ch_day();
	void menu();
	inline string& get_name_save() { return name_save; }
	void co_bu();

	void go_pe_give(int& gi_rate);//捐款，政府额外补贴部分,girate表示捐款率，每捐一次都会降低

	inline government(unsigned int _population, unsigned int _init_affected, unsigned int init_hosCap) { Area.reset(_population, _init_affected, init_hosCap); }
	//    string get_name_save();
	bool _move();



private:
	area Area;
	unsigned long long money;
	long long day_in;
	int gi_rate;//捐款相关率
	const unsigned long long money_de;
	const long long day_in_de;
	const int gi_rate_de;
	string name_save;

};
