#pragma once
#include <random>
class area
{
private:
    inline double random_float_between_0_1(unsigned int seed = 0)
    {
        static std::default_random_engine e(seed);
        static std::uniform_real_distribution<double> u(0, 1);
        return u(e);
    }
    unsigned int population;
    unsigned int affected;
    unsigned int distract;
    unsigned int hosCap;
    unsigned int dead;

    inline void spread(int& object, double& rate) { object *= 1 + rate; }

};

