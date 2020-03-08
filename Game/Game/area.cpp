#include "area.h"
const int lev_low[20]={1,1,10,20,50,100,200,400,800,1400,2000,3000,4000,5000,10000};
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
			    if(lev_lim>13)
                {
                    std::cout<<"The level of reduce movement has been the highest\n";
                }
			    if(affected>=lev_low[lev_lim]||dead>=lev_low[lev_lim]/10)
                {
                /**/
                /**/
                if(affect>=lev_low[lev_lim]+1)
				affeRate *= 0.87,num_aga-=1000;
				else
                affeRate*=0.9,num_aga+=1000;
				lev_lim++;

				}
				else
                {
                    affeRate*=0.95;
                    std::cout<<"Due to the excessive treatment,you set off a panic in the crowd,which makes the number of against people increase";
                    num_aga+=5000;
                }
				break;
				//expandable
			case reduceLimit:
			    affeRate/=1.1;
                lev_lim--;
            break;
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
	if(affected>1000000)
    {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout<<"Due to your improper control,the sick cause big harm to the city.\nYou lose the game.\nDon't lose your determination!\nPress any button to return to the menu";
    while(!_kbhit);
    char s=getch();
    menu();
    }
    /**/
    /**/
    if(money<10000)
    {
        std::cout<<"you have no money now.you lose\n the part of giving away money will join later\nPress any button to return to the menu"
        while(!_kbhit);
        char s=getch();
        menu();
    }
/*	if(day>233&&)/
    {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout<<"Because of the illness,the Olympic is put off\nAnd the economic of China is affected.You lose the game.\n Press any button to return to the menu";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    while(!_kbhit);
    char s=getch();
    menu();
    }*/

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
			<< day << std::endl
			<<num_aga<<std::endl
			<<lev_lim<<std::endl;

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
			>> day>>num_aga>>lev_lim;
		return true;
	}
	return false;
}
