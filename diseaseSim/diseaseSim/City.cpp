#include "City.h"

using namespace std;

void City::move()
{

}

City::Person::Person()
{
	isAffected = isHiden = isInHosp = isCured = false;
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
}
