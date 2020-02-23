#include "City.h"

using namespace std;

void City::_move()
{
	mv_time();
	int affe, hide, hosp, cure, dead;
	for (auto person : people)
	{
		person->_move(day);

		if (person->isDead)
			++dead;
		if (person->isInHosp)
			++hosp;
		if (person->isHiden)
			++hide;
		if (person->isCured)
			++cure;
		if (person->isAffected)
			++affe;
		
	}
}

void City::mv_time()
{
	day++;
	if (day <= 11) date.year = 2019, date.month = 12, date.day1 = 20 + day;
	else
	{
		date.year++;
		date.day1++;
		if (date.day1 > day_of_month[date.month])date.day1 = 1, date.month++;
	}
}

City::City(int _citizens, int _hosCap, double _outgoingRate, double _affectPossibility, double _initAffectRate, int _averageHidePeroid, int _dayToHospital, double _deathRate, double _cureRate)
{
	citizens = _citizens, hosCap = _hosCap, outgoingRate = _outgoingRate, \
		affectPossibility = _affectPossibility, initAffectRate = _initAffectRate, \
		averageHidePeroid = _averageHidePeroid, dayToHospital = _dayToHospital, \
		deathRate = _deathRate, curePossibility = _cureRate;
	deadCount = 0;
	for (int i = 0; i < citizens, i++)
	{
		Person* pper = new(Person);
		people.push_back(pper);
	}
}



int day_of_month[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};


City::Person::Person()
{
	isAffected = isHiden = isInHosp = isCured = isDead = false;
	theDayAffected = showDay = -1;
	static normal_distribution<double> n(averageHidePeroid, 5);
	hidePerioid = lround(n(e));
	if (double(e() % 1000) / 1000.0 < City::initAffectRate)
		isAffected = isHiden = true, theDayAffected = 0, \
		showDay = theDayAffected + hidePerioid;


}

void City::Person::_move(int day)
{
	if (!isAffected&&!isCured)
	{
		if (double((e() % 1000)) / 1000.0 < City::outgoingRate)
			if (double(e() % 1000) / 1000.0 * City::affected * City::outgoingRate\
				< City::affectPossibility)
				isAffected = isHiden = true, theDayAffected = day, \
				showDay = theDayAffected + hidePerioid;
	}
	else if (isAffected && isHiden)
	{
		if (day == showDay)
			isHiden = false;
	}
	else if (isAffected && !isHiden)
	{
		if (day == showDay + City::dayToHospital && City::inHosp < City::hosCap)
			isInHosp = true;
	}
	else if (isInHosp)
	{
		if (double(e() % 1000) / 1000.0 < City::deathRate)
			isDead = true;
		else if (double(e() % 1000) / 1000.0 < City::curePossibility)
			isCured = true, isHiden = isAffected = isInHosp = false;
	}
}
