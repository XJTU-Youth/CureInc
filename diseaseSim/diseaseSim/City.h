#pragma once
#include <vector>
#include <random>
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
		void _move(int day);
		static std::default_random_engine e;

		Person();
	};
	static int citizens;
	static int affected;
	static int cured;
	static int hosCap;
	static int inHosp;
	static int deadCount;

	std::vector<Person*> people;

	static double outgoingRate;

	static double affectPossibility;

	static double curePossibility;

	static double initAffectRate;

	static int averageHidePeroid;

	static int dayToHospital;

	static double deathRate;

	int day = 0;

	void _move();


	void show();
	void mv_time();
public:
	City(int _citizens, int _hosCap, double _outgoingRate, \
		double _affectPossibility, double _initAffectRate, \
		int _averageHidePeroid, int _dayToHospital, \
		double _deathRate, double _cureRate);
	struct _date
	{
		int year;
		int month;
		int day1;
	} date;
};

