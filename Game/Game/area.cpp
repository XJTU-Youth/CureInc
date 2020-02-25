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
	affected = spread(affected - hospital.hospat, affeRate);
	processAction();

}

bool area::saveToYaml(std::string savName)
{
	std::ofstream fout(savName,std::fstream::trunc);
	if (fout.is_open())
	{
		YAML::Node data;
		data["affeRate"] = affeRate;
		data["population"] = population;
		data["affected"] = affected;
		data["dead"] = dead;
		data["healthy"] = healthy;
		data["cured"] = cured;
		data["dayliSpend"] = dayliSpend;
		data["hospital"]["hostot"] = hospital.hostot;
		data["hospital"]["hospat"] = hospital.hospat;
		data["day"] = day;
		fout << data;
		fout.close();
		return true;
	}
	return false;
}

bool area::loadFromYaml(std::string savName)
{
	YAML::Node data = YAML::LoadFile(savName);
	affeRate = data["affeRate"].as<double>;
	population = data["population"].as<unsigned int>;
	affected = data["affected"].as<unsigned int>;
	dead = data["dead"].as<unsigned int>;
	healthy = data["healthy"].as<unsigned int>;
	cured = data["cured"].as<unsigned int>;
	dayliSpend = data["dayliSpend"].as<unsigned int>;
	hospital.hostot = data["hospital"]["hostot"].as<unsigned int>;
	hospital.hospat = data["hospital"]["hospat"].as<unsigned int>;
	day = data["day"].as<int>;
	return true;
}
