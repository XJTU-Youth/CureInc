#pragma once
#include "area.h"
 class government
 {
public:
    void ch_day()
{
    money+=day_in;
    money-=Area.getTodaySpend();
}
    void co_bu();

    void go_pe_give(int& gi_rate);//���������ⲹ������,girate��ʾ����ʣ�ÿ��һ�ζ��ή��

private:
     area Area;
     unsigned long long money;
     unsigned long long day_in;
 };
