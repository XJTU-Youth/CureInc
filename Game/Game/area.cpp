#include "area.h"

void area::processAction()
{
	for (auto action_ : actions)
	{
		action_.second--;
		if (action_.second == 0)
		{
			switch (action_.first)
			{
			case buildHospital:
				hospital.hosava += 100;
				hospital.hostot += 100;
				break;
			case reduceMovement:
				//Do something;
				break;
				//expandable
			}
			
		}
	}
}

void area::mv_time()
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
void area::_move()
{
	mv_time();
	spread(affected, );
	processAction();

}
