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
				//hospital.hosava += 100;
				hospital.hostot += 100;
				break;
			case reduceMovement:
				affeRate *= 0.9;
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
	if(dead>500000)
    {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout<<"Due to your improper control,the sick cause big harm to the city.\nYou lose the game.\nPress any button to return to the menu";
    while(!_kbhit);
    char s=getch();
    menu();
    }
	if(day>233)
    {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout<<"Because of the illness,the Olympic is put off\nAnd the economic of China is affected.You lose the game.\nPress any button to return to the menu";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    while(!_kbhit);
    char s=getch();
    menu();
    }
	affected = spread(affected - hospital.hospat, affeRate);
	processAction();
	hospital.hospat = 0.5 * affected;
	dayliSpend = hospital.hospat * 2000 + hospital.hospat * 5000 + 10000000;

}

bool area::saveToYaml(std::string savName)
{
	std::ofstream fout(savName);
	if (fout.is_open())
	{

		fout << affeRate << std::endl
			<< population << std::endl
			<< affected << std::endl
			<< dead << std::endl
			<< healthy << std::endl
			<< cured << std::endl
			<< dayliSpend << std::endl
			<< hospital.hostot << std::endl
			<< hospital.hospat << std::endl
			<< day << std::endl;

		fout.close();
		return true;
	}
	return false;
}

bool area::loadFromYaml(std::string savName)
{
	std::ifstream fin(savName);
	if (fin.is_open())
	{
		fin >> affeRate >> population >> affected
			>> dead >> healthy >> cured >> dayliSpend
			>> hospital.hostot >> hospital.hospat
			>> day;
		return true;
	}
	return false;
}
