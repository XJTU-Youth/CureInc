#pragma once
#include <random>
#include <ctime>
#include <utility>
#include <vector>
#include <iostream>
#include <Windows.h>

const std::string HubeiMap = R"(
              ,,,---                                                      
       ,,,'```      \,,,_                                                 
     |                   .                                                
      `.                   |  ,,                                          
         ,                ,       \  _. ____..                            
             |         |               |      |                           
         /          '                 |       \ ,......../``  _|          
          ',         |                ,           \      |     | ,- ,     
             ,'        `' .   ,' .`        '.   ,.-        ,         \-- ,
               '.         `                    `          /|          -'` 
                  \     ,-  |                  /    ,.'`   ',       |     
                   ' |       |   .........,,-`      |        `        /    
        /   \ '''    /        \/-                 /    | '_.         \    
       /           /             ` \            |      |  |.            | 
  .--          /     .....-      ,' |     _.  -    ``,'/`        |\     \ 
 |                | /        `` `     \ /   \   /\        `,     | `'... `
   |          ,.`  '             \._,`       ``   |           `',         
  '        /                                     |     ,--'''             
    `` \  |                                      \   /                    
         `                                        ```                     )";


class area
{
private:
	inline double random_float_between_0_1(unsigned int seed = time(nullptr))
	{
		static std::default_random_engine e(seed);
		static std::uniform_real_distribution<double> u(0, 1);
		return u(e);
	}

	double affeRate;

	unsigned int population;
	unsigned int affected;
	//  unsigned int distract;
	unsigned int dead;
	unsigned int todayDied;
	unsigned int healthy;
	unsigned int cured;

	unsigned int dayliSpend;

	struct
	{
		unsigned int hostot;//总床位
	 //   unsigned int doctot;//总医生
		unsigned int hospat;//病人数
	} hospital;

	inline unsigned int spread(const unsigned int& object, const double& rate) { return object * (1 + rate); }
	void processAction();


public:
	enum action { buildHospital, reduceMovement };
private:
	std::vector<std::pair<action, int16_t>> actions;//消息队列，存放pair，pair内部是操作名称和还需时间。
public:

	int day;

	inline unsigned long long addAction(action _action, int16_t time) { actions.push_back(std::pair<action, int16_t>(_action, time)); return _action == buildHospital ? 2000000 : 0; }
	inline void showAction() { for (auto& action_ : actions)std::cout << "Action:" << int(action_.first) << " Time:" << action_.second << " days.\n"; }
	inline void showOverallStatus() {
		system("cls");
		std::cout << HubeiMap << std::endl << "Total Population: " << population << "\nTotal nCov affected: " << affected << "\nTotal hospital capacity: "\
			<< hospital.hostot << "\nAvaliable hospital room: " << hospital.hostot - hospital.hospat << "\nDead patients count: " << dead << std::endl;
	}
	void mv_time();
	const int day_of_month[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	inline area(unsigned int _population = 0, unsigned int _init_affected = 0, unsigned int init_hosCap = 0) :population(_population), affected(_init_affected)
	{
		hospital.hospat = 0, hospital.hostot = init_hosCap; affeRate = 0.5;
	}

	inline void reset(unsigned int _population, unsigned int _init_affected, unsigned int init_hosCap)
	{
		hospital.hostot = 0, = hospital.hostot = init_hosCap;
		population = _population;
		affected = _init_affected;
	}
	struct _date
	{
		int year;
		int month;
		int day1;
	} date;
	void _move();
	inline unsigned int& getTodayDead() { return todayDied; }
	inline unsigned int& getHosPat() { return hospital.hospat; }
	inline unsigned int& getAffected() { return affected; }
	inline unsigned int& getCured() { return cured; }
	inline unsigned int& getHealthy() { return healthy; }
	inline unsigned int& getTodaySpend() { return dayliSpend; }
};

