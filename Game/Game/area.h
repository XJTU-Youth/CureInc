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
        unsigned int hostot;//�ܴ�λ
        unsigned int doctot;//��ҽ��
        unsigned int hosava;//���ô�λ
    };

    inline void spread(int& object, double& rate) { object *= 1 + rate; }


public:
    enum action {buildHospital, reduceMovement};

    std::vector<std::pair<action, std::int16_t>> actions;//��Ϣ���У����pair��pair�ڲ��ǲ������ƺͻ���ʱ�䡣
};

