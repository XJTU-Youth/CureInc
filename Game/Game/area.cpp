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
				//Do something;
				break;
			case reduceMovement:
				//Do something;
				break;
				//expandable
			}
			
		}
	}
}


