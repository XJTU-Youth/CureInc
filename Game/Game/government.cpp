#include "government.h"
const string gov = "gov.sav";

void government::co_bu()
{
	area::action buildHosp = area::action::buildHospital;
	money -= Area.addAction(buildHosp, 7);
	day_in += 50000;
}
//string government::get_name_save(){return name_save;}
void government::new_game()
{
	system("cls");
	std::cout << "Please input the name of the save without space\n";
a1: std::cin >> name_save;
	FILE* dat;
	errno_t err;
	err = fopen_s(&dat, (name_save + gov).c_str(), "r");
	if (!err)
	{
	    fclose(dat);
		std::cerr << "Archive already exists, overwrite or not?answer with letter y/n\n";
		char s;
		std::cin >> s;
		if (s != 'y') goto a1;
	}
	money = money_de;
	day_in = day_in_de;
	assert(Area.saveToYaml(name_save));
}
void government::read_save()
{
	system("cls");
	cout << "input the name of the save\n";
	std::cin >> name_save;
	FILE* dat;
	errno_t err = fopen_s(&dat, (name_save + gov).c_str(), "r");
	if (err)
	{
		std::cerr << "The program can't find the save";
		menu();
	}
	fread(&money, sizeof(unsigned long long), 1, dat);
	fread(&day_in, sizeof(long long), 1, dat);
	fread(&gi_rate, sizeof(int), 1, dat);
	/**/
	fclose(dat);
	assert(Area.loadFromYaml(name_save));
}
void government::save_exit()
{
	FILE* dat;
	errno_t err;
	err = fopen_s(&dat, (name_save + gov).c_str(), "w");
	/**/
	if(err==0)
	fclose(dat);
	menu();
}
void government::menu()
{
	system("cls");
	printf("Welcome to the game CureInc\nchoose a/b/c to continue\na:start a new game\nb:load game\nc:exit\n");
	char s;
a2:cin >> s;
	switch (s)
	{
	case 'A':
	case 'a':
		new_game(); break;
	case 'B':
	case 'b':
		read_save(); break;
	case 'C':
	case 'c':
		exit(0);
	default:
		cout << "Pay a little attention!!!,input the letter again\n";
		goto a2;

	}
}
void government::ch_day()
{
	Area._move();
	money += day_in;
	money -= Area.getTodaySpend();
}
void government::go_pe_give(bool from)//���������ⲹ������,girate��ʾ����ʣ�ÿ��һ�ζ��ή��
{
	int ex_ge = 0;//extra get
	//���������ģ�����=1������=0
	if (from == false)
	{
		static std::default_random_engine e(time(nullptr));
		static std::uniform_real_distribution<double> u(0, 1);
		if (u(e) > 0.9)
			ex_ge =ex_ge*2/3, day_in=day_in*5/6, gi_rate += 0;
	}
}

bool government::_move()
{
	Area._move();
	Area.showOverallStatus();
	//TODO: Complete codes for gameplay
a:	cout << "Do your choice: H for build Hospital\n\
R for keep citizens at home\n E for save and exit.\n";
	char input;
	cin >> input;
	switch (input) {
	case 'H':
	case 'h':
		area::action b = area::action::buildHospital;
		Area.addAction(b, 7);
		break;
	case 'R':
	case 'r':
		area::action r = area::action::reduceMovement;
		Area.addAction(r, 3);
		break;
	case 'E':
	case 'e':
		return false;
		break;
	default:
		cout << "Not an option!\n";
		goto a;
	}
	return true;
}
