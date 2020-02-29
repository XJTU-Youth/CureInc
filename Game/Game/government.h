#pragma once
#include "area.h"
#include<assert.h>
#include<stdio.h>
using std::cout;
using std::cin;
using std::string;
class government
{

private:
	area Area;
	unsigned long long money;
	long long day_in;
	int gi_rate;//捐款相关率
	const unsigned long long money_de = 30000000;
	const long long day_in_de = 1000000;
	const int gi_rate_de = 0;
	string name_save;


public:
	void new_game();
	void read_save();
	void save_exit();
	void ch_day();
	void menu();
	inline string& get_name_save() { return name_save; }
	void co_bu();

	void go_pe_give(bool from);//捐款，政府额外补贴部分,girate表示捐款率，每捐一次都会降低
    template <class T>;
    inline void change(T& a, int b){a-=b;}
	inline government(unsigned int _population=0, unsigned int _init_affected=0, unsigned int init_hosCap=0) { Area.reset(_population, _init_affected, init_hosCap); }
	//    string get_name_save();
	bool _move();
	void Start();

};
