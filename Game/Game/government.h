#pragma once
#include "area.h"
 class government
 {
public:
    void ch_day()
{
    money+=day_in();
    money-=Area.getTodaySpend();
}
    void co_bu()
    {
    area::action buildHosp=buildHospital;
    money -= Area.addAction(buildHosp, 7);
    day_in+=50000;
    }
    void go_pe_give(&int gi_rate)//���������ⲹ������,girate��ʾ����ʣ�ÿ��һ�ζ��ή��
    {
        int ex_ge;//extra get
        bool from;
        //���������ģ�����=1������=0
        if(from=false)
        {
        static std::default_random_engine e(seed);
        static std::uniform_real_distribution<double> u(0, 1);
        if(u(e)>0.9)
            ex_ge/=1.5,day_in-=20000,gi_rate+=/*!!!!û���*/;//������ʮ�ֻ�
        }
    }
private:
     area Area;

 };
