#include "government.h"
const string gov="gov.sav";
void government::co_bu()
{
    area::action buildHosp = area::action::buildHospital;
    money -= Area.addAction(buildHosp, 7);
    day_in += 50000;
}
//string government::get_name_save(){return name_save;}
void government::new_game()
{
    std::cout<<"Please input the name of the save without space\n";
a1: std::cin>>name_save;
    FILE * dat;
    dat=fopen((name_save+gov).c_str(),"r");
    if(dat)
    {
        std::cout<<"Archive already exists, overwrite or not?answer with letter y/n\n";
        char s;
        std::cin>>s;
        if(s=='y') goto a1;
    }
    fclose(dat);
    money=money_de;
    day_in=day_in_de;
}
void government::read_save()
{
    std::cin>>name_save;
    FILE * dat;
    dat=fopen((name_save + gov).c_str(),"r");
    if(!dat)
    {
        std::cout<<"The program can't find the save";
        assert(0);
    }
    fread(&money,sizeof(unsigned long long),1,dat);
    fread(&day_in,sizeof(long long),1,dat);
    fread(&gi_rate,sizeof(int),1,dat);
    /**/
    fclose(dat);
}
void save_exit()
{
    FILE * dat;
    dat=fopen((name_save + gov).c_str(),"w");
    /**/
    fclose(dat);
}
void government::ch_day()
{
        Area._move();
        money+=day_in;
        money-=Area.getTodaySpend();
}
void government::go_pe_give(int& gi_rate)//���������ⲹ������,girate��ʾ����ʣ�ÿ��һ�ζ��ή��
{
    int ex_ge;//extra get
    bool from;
    //���������ģ�����=1������=0
    if (from = false)
    {
        static std::default_random_engine e(time(nullptr));
        static std::uniform_real_distribution<double> u(0, 1);
        if (u(e) > 0.9)
            ex_ge /= 1.5, day_in /=1.2, gi_rate +=/*!!!!û���*/0;//������ʮ�ֻ�
    }
}

bool government::_move()
{
    Area._move();
    Area.showOverallStatus();
    //TODO: ����˵���ʾ����ɲ����Ļ�ȡ�Լ���ɡ�
}
