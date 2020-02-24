#pragma once
#include <random>
#include <ctime>
#include <utility>
#include <vector>
#include <iostream>
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
    unsigned int distract;
    unsigned int dead;

    struct hospital
    {
        unsigned int hostot;//总床位
        unsigned int doctot;//总医生
        unsigned int hosava;//可用床位
    };

    inline void spread(int& object, double& rate) { object *= 1 + rate; }
    void processAction();


public:
    enum action {buildHospital, reduceMovement};
private:
    std::vector<std::pair<action, int16_t>> actions;//消息队列，存放pair，pair内部是操作名称和还需时间。
public:
    inline void addAction(action _action, int16_t time) { actions.push_back(std::pair<action, int16_t>(_action, time)); }
    inline void showAction() { for (auto& action_ : actions)std::cout << "Action:" << int(action_.first) << " Time:" << action_.second << " days.\n"; }
};

