#include "City.h"

using namespace std;
int day_of_month[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
void City::move()
{
	mv_time();
}
void City::mv_time()//在move里面调用这个就行，先day++了，所以day初始化到0
{
    day++;
    if(day<=11) date.year=2019,date.month=12,date.day1=20+day;
    else
    {
        date.year++
        date.day1++;
        if(date.day1>day_of_month[date.month])date.day1=1,date.month++;
    }
}
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

void City::Person::move(int day)
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
