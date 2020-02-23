#include "City.h"

using namespace std;

bool City::_move()
{
	mv_time();
	int affe=0, hide=0, hosp=0, cure=0, dead=0;
	for (auto &person : people)
	{
		person->_move(day,citizens,affected,hiden,cured,inHosp,hosCap,deadCount,\
		outgoingRate,affectPossibility,curePossibility,dayToHospital,deathRate);

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
	affected = affe;
	hiden = hide;
	inHosp = hosp;
	cured = cure;
	deadCount = dead;

	show();
	return affected > 0;
}

void City::getin()
{
	if (_kbhit())
	{
		char s = _getch();
		if (s == 'g')
		{
			system("cls");
			string s;
			cin >> s;
		}
	}
}

void City::show()
{
	cout << "affected:" << affected;
	cout << "IN Hospital" << inHosp;
	cout << "cured" << cured;
	cout << "dead" << deadCount << endl;
}

void City::mv_time()
{
	day++;
//	if (day <= 11) date.year = 2019, date.month = 12, date.day1 = 20 + day;
//	else
//	{
//		date.year++;
//		date.day1++;
//		if (date.day1 > day_of_month[date.month])date.day1 = 1, date.month++;
//	}
}

City::City(int _citizens, int _hosCap, double _outgoingRate,\
	double _affectPossibility, double _initAffectRate,\
	int _averageHidePeroid, int _dayToHospital, double _deathRate,\
	double _cureRate)
{
	citizens = _citizens, hosCap = _hosCap, outgoingRate = _outgoingRate, \
		affectPossibility = _affectPossibility, initAffectRate = _initAffectRate,\
		averageHidePeroid = _averageHidePeroid, dayToHospital = _dayToHospital, \
		deathRate = _deathRate, curePossibility = _cureRate;
	deadCount = 0;
	for (int i = 0; i < citizens; i++)
	{
		Person* pper = new Person(initAffectRate,averageHidePeroid);
		people.push_back(pper);
	}
}



int day_of_month[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};


City::Person::Person(double& initAffectRate, int& averageHidePeroid)
{
	static std::default_random_engine e;
	isAffected = isHiden = isInHosp = isCured = isDead = false;
	theDayAffected = showDay = -1;
	static normal_distribution<double> n(averageHidePeroid, 5);
	hidePerioid = lround(n(e));
	if (double(e() % 1000) / 1000.0 < initAffectRate)
		isAffected = isHiden = true, theDayAffected = 0, \
		showDay = theDayAffected + hidePerioid;


}

void City::Person::_move(int day, int& citizens, int& affected, int& hiden, int& cured, \
	int& hosCap, int& inHosp, int& deadcount, double& outgoingRate, \
	double& affectPossibility, double& curePossibility, int& dayToHospital, \
	double& deathRate)
{
	static std::default_random_engine e;
	if (!isAffected&&!isCured)
	{
		if (double((e() % 1000)) / 1000.0 < outgoingRate)
			if (double(e() % 1000) / 1000.0 * affected * outgoingRate\
				< affectPossibility)
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
		if (day == showDay + dayToHospital && inHosp < hosCap)
			isInHosp = true;
	}
	else if (isInHosp)
	{
		if (double(e() % 1000) / 1000.0 < deathRate)
			isDead = true;
		else if (double(e() % 1000) / 1000.0 < curePossibility)
			isCured = true, isHiden = isAffected = isInHosp = false;
	}
}
