#include "government.h"
const string gov = "gov.sav";
const string logo=
"                 :N@B@@u                                     EP\n"
"                @Bu.  i:                                     B@\n"
"               EB         :BJ   .Mu   LFrXB1   7@B@G,        @M   :OuU@B@J     JB@BM,\n"
"              .Bv         :@2    @S   1@O.    X@   ;B:       BB   ,@@.  .@v   @B,\n"
"              .@r         :Bu    Bu   Y@     :@Bi7v2@q       @M   :Br    Bu  :Bi\n"
"               M@         :@7    @u   jB.    :BB:rrr:        @B   ,@i    @L  ,@i\n"
"               .B@r   ..  .BB   SBk   2@,     SB             @B   :BL    @5   B@:  .\n"
"                 vMB@B@;   :M@BNvN7   LM.      rO@B@0.       GZ   :Bi    @L    L@B@O.\n";
void inline movexy(short x, short y)
{
    COORD position={x, y};
    HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, position);
}
void government::Start()
{
    movexy(3,1);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<logo;
    Sleep(3000);
    system("cls");
    movexy(10,5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout<<"CureInc:the game of the epidemic prevention in HuBei Province";
	movexy(13,7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout<<"Due to coding problem,we can't use Chinese temporarily";
	movexy(21,9);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout<<"[Press any button to continue]";
	while(!_kbhit());
	char rub=getch();
	system("cls");
	movexy(20,6);
	cout<<"Loading";
	for(int i=1;i<=6;i++)
	{
	Sleep(200);
	cout<<".";
	}
	menu();

}
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
	while (_move());
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
		MessageBox(NULL,L"we can't find this save",L"pay a little attention",MB_ICONWARNING|MB_OK);
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
	char ch;
	cout << "Do you wanna make choice?<Y/N>\n";
	cin >> ch;
	if (ch != 'y' && ch != 'Y')
		return true;
a:	cout << "Do your choice: H for build Hospital\n\
R for keep citizens at home\n E for save and exit.\n";
	char input;
	cin >> input;
		area::action b = area::action::buildHospital;
	area::action r = area::action::reduceMovement;
	switch (input) {
	case 'H':
	case 'h':

		Area.addAction(b, 7);
		break;
	case 'R':
	case 'r':

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
