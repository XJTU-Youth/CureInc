#pragma once
#include <random>
#include <ctime>
#include <utility>
#include <vector>
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


public:
    enum action {buildHospital, reduceMovement};

    std::vector<std::pair<action, std::int16_t>> actions;//消息队列，存放pair，pair内部是操作名称和还需时间。
};

