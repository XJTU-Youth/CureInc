#pragma once
#include "area.h"
 class government
 {
public:
    void ch_day()

    void co_bu();

    void go_pe_give(int& gi_rate);//���������ⲹ������,girate��ʾ����ʣ�ÿ��һ�ζ��ή��

    inline government(unsigned int _population, unsigned int _init_affected, unsigned int init_hosCap) { Area.reset(_population, _init_affected, init_hosCap); }

    bool _move();

private:
     area Area;
     unsigned long long money;
     unsigned long long day_in;
 };
