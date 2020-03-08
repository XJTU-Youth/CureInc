/*#pragma once
#include <vector>
#include <random>
#include <conio.h>
#include <iostream>
class City
{
private:
	class Person
	{
	public:
		bool isAffected;
		bool isHiden;
		bool isInHosp;
		bool isCured;
		bool isDead;
		int theDayAffected;
		int hidePerioid;
		int showDay;
		void _move(int day, int& citizens, int& affected, int& hiden, int& cured,\
		int& hosCap, int& inHosp, int& deadcount, double& outgoingRate,\
		double& affectPossibility, double& curePossibility, int& dayToHospital,\
		double& deathRate);
		

		Person(bool initAffect, int& averageHidePeroid);
	};
	int citizens;
	int affected;
	int hiden;
	int cured;
	int hosCap;
	int inHosp;
	int deadCount;

	const int day_of_month[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

	std::vector<Person*> people;

	double outgoingRate;

	double affectPossibility;

	double curePossibility;

	int initAffectCount;

	int averageHidePeroid;

	int dayToHospital;

	double deathRate;

	int day = 0;
public:
	bool _move();

	void getin();
	void show();
	void mv_time();



	City(int _citizens, int _hosCap, double _outgoingRate, \
		double _affectPossibility, int _initAffectCount, \
		int _averageHidePeroid, int _dayToHospital, \
		double _deathRate, double _cureRate);
	struct _date
	{
		int year;
		int month;
		int day1;
	} date;
};
*/
