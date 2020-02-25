#pragma once
#include "area.h"
 class government
 {
public:
    void ch_day()

    void co_bu();

    void go_pe_give(int& gi_rate);//捐款，政府额外补贴部分,girate表示捐款率，每捐一次都会降低

    inline government(unsigned int _population, unsigned int _init_affected, unsigned int init_hosCap) { Area.reset(_population, _init_affected, init_hosCap); }

    bool _move();

private:
     area Area;
     unsigned long long money;
     unsigned long long day_in;
 };
