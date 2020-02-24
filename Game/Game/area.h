#pragma once
#include <random>
#include <ctime>
#include <utility>
#include <vector>
#include <iostream>

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
    unsigned int population;
    unsigned int affected;
//  unsigned int distract;
    unsigned int dead;

    struct
    {
        unsigned int hostot;//总床位
     //   unsigned int doctot;//总医生
        unsigned int hosava;//可用床位
    } hospital;

    inline void spread(int& object, double& rate) { object *= 1 + rate; }
    void processAction();


public:
    enum action {buildHospital, reduceMovement};
private:
    std::vector<std::pair<action, int16_t>> actions;//消息队列，存放pair，pair内部是操作名称和还需时间。
public:
    inline void addAction(action _action, int16_t time) { actions.push_back(std::pair<action, int16_t>(_action, time)); }
    inline void showAction() { for (auto& action_ : actions)std::cout << "Action:" << int(action_.first) << " Time:" << action_.second << " days.\n"; }
    inline void showOverallStatus() {
        std::cout << HubeiMap << std::endl << "Total Population: " << population << "\nTotal nCov affected: " << affected << "\nTotal hospital capacity: "\
            << hospital.hostot << "\nAvaliable hospital room: " << hospital.hosava << "\nDead patients count: " << dead << std::endl;
    }

    inline area(unsigned int _population, unsigned int _init_affected, unsigned int init_hosCap) :population(_population), affected(_init_affected)
    { hospital.hosava = hospital.hostot = init_hosCap; }
};

