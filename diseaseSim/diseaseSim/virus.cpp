//#pragma GCC optimize(3)
//u1s1,O3is not neccessary
#include<stdio.h>
/*
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
*/
//#include<Windows.h>
#include<conio.h>
// conio.h:being the god forever!!!
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>

#define scanf scanf_s
#define printf printf_s
#define getch _getch
#define kbhit _kbhit

//pay attention to this define!!!
#define  q hubei[i][j]
#define lao8hanbao printf("[Press any key to continue]\n");while(!kbhit());rub=getch();
/*void movexy(int x,int y)
{
		 COORD position={x, y};
		 HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
		 SetConsoleCursorPosition(hOut, position);
} */
/*
int kbhit()
{
	static const int STDIN = 0;
	static bool initialized = false;

	if (! initialized) {
		// Use termios to turn off line buffering
		termios term;
		tcgetattr(STDIN, &term);
		term.c_lflag &= ~ICANON;
		tcsetattr(STDIN, TCSANOW, &term);
		setbuf(stdin, NULL);
		initialized = true;
	}

	int bytesWaiting;
	ioctl(STDIN, FIONREAD, &bytesWaiting);
	return bytesWaiting;
}
*/

void dbg1() { printf_s("debug 1 called\n"); }
void dbg2() { printf_s("debug 2 called\n"); }
void dbg3() { printf_s("debug 3 called\n"); }
void dbg4() { printf_s("debug 4 called\n"); }
void dbg5() { printf_s("debug 5 called\n"); }
void dbg6() { printf_s("debug 6 called\n"); }
void dbg7() { printf_s("debug 7 called\n"); }
void dbg8() { printf_s("debug 8 called\n"); }
void dbgq() { printf_s("debug q called\n"); }
void dbgw() { printf_s("debug w called\n"); }
void dbge() { printf_s("debug e called\n"); }
void dbgr() { printf_s("debug r called\n"); }

const char Aoligei[23333] =
"      1LvL2FSSXL:\n"
"        :@B@:,,,i1B@7      vB@:\n"
"         B@i       Z@S     .r:\n"
"        L@k        iB@,               ..          .,         ..            ..          ,.\n"
"       .@B7        i@B, ,uvX2       vjvL2r.    :YLYvuv     r5JL7vJr      iLvJJr.    iLuvYFv\n"
"       r@B.        kBZ :ui.@B:    .XB:  B@:  ,M@7   L@:  :M@i  :B@J    .M@  .B@i  :MB7   OB.\n"
"      .Z@v        ,B@r .  7BN     :M@OL:.   :B@u:rYuJ:  :B@j   .@8     ,@BOL:.   .@B5:iv2J:\n"
"      7@B.       :B@7    ,BM       ,1@B@B:  L@M: ,.    .N@J    5B7      ,kB@B@.  1BO  ,.   \n"
"      0Bj       LB@:    .8@. 7:  uO:   v@5  uBP      ,  M@i   i@M  v. UO,   JBv  U@X      : \n"
"   :;NB@Pi:rLSPMO7      7@Or7P, .@@u  i0S,  .E@7  :LSu  L@X..7B@ZuJ7 :B@j  iPq    O@i..iL0J.\n"
"  .ijuYvL7vL1vi.         :77i    .::iir:      ir777i,    ,77r:,,7Ji   .:i:rr:      :Lvv7i. \n"
"                                                                                        \n"
"                                                                                      \n"
"                     .:r:.   ,                                                       \n"
"                   ;GOXLLSM8OL      7OF                                             \n"
"                  5@r     i@M       2@u                                           \n"
"                 j@q       Bu                                                      \n"
"                 UB@v.     .     .i7:       :7r,  iYJ;   iLui                   \n"
"                  UB@B@B@r      iur7@Z     7Pr8BGLi.rB@FJr.i@B:                \n"
"                    iUXBB@G    ,u  u@S    :i .M@r    O@J    M@:                     \n"
"                :       rB@       iBG        L@S    7B8    v@G                      \n"
"               Lk.      i@O      .M@. ..     @@i    M@i    @B:  .                  \n"
"              rB@:     :@O.      0@u 7O     v@O    r@M    1BP 7J:                   \n"
"              uB2PXLrY8M7        vqk2v.    .5@r    uBL    iOSrL:                  \n";
int day = 1;
struct person {
	short affect;
	short curing;//in hos
	short cured;
	short dead;
	short iaff_r; //affeRate in the group,related to above
	bool affe;//no affected
	bool a_affe;//all affected
//	bool o_affe;//can spread out
} hubei[1601][1601];
int affe_rate;
int die_rate;
int cure_abi;
//0<above<100
int move_times =
25;//the number of a day's swaps,getting lower when the level_lim++
int hosCap;
int inhos = 0;
int affecount = 20;
int curcount = 0;//cure count
int deadcount = 0;
//int pl=800,pr=800,pu=800,pd=800;//point leftrightupdown
const int hidetime = 14;
//int level_lim=0;
//with the name of strange things are all useless!!!
int main()
{
	system("mode con cols=100");
	printf("%s", Aoligei);
	srand(time(0));
	hubei[800][800].affect = 20;
	hubei[800][800].a_affe = true;
	hubei[800][800].affe = true;//hubei[800][800].o_affe=true;
	int a = rand() % 16 + 30;
	char rub;
	printf("\n");
	lao8hanbao
		bool dui = true;
	//Sleep(3000);
//	system("cls");
	//movexy(10,5);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("\n\n\n\n          The simulation of virus transmission,maybe different to the real situation");
	//movexy(13,7);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("\n\n             Due to coding problem,we can't use Chinese temporarily");
	//movexy(21,9);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("\n\n                [Press any key to continue]");
	while (!kbhit());
	rub = getch();

//	system("cls");
	printf("set the data\n");
a1:
	printf("input the affect rate(30<=n<=70):");
	scanf("%d", &affe_rate);
	if (affe_rate < 30 || affe_rate>70) {
		printf("pay some attention!\n");
		goto a1;
	}
a2:
	printf("input the die rate(30<=n<=70):");
	scanf("%d", &die_rate);
	if (die_rate < 30 || die_rate>70) {
		printf("pay some attention!\n");
		goto a2;
	}
a3:
	printf("input the cure ability(30<=n<=70):");
	scanf("%d", &cure_abi);
	if (cure_abi < 30 || cure_abi>70) {
		printf("pay some attention!\n");
		goto a3;
	}
a4:
	printf("Now you can set the number of initial hospital's beds(0<=n<2^32)\n");
	scanf("%d", &hosCap);
	if (hosCap < 0) {
		printf("Are you lixi???Pay much attention!!!\n");
		goto a4;
	}
	while (day++) {

		//event
		if (day == a) {
			printf("Gov:The hospital of Huoshenshan has been built\n");
			printf("The number of beds available in the hospital has increased\n");
			lao8hanbao
				hosCap += 1400;

			cure_abi += 5;
		}
		if (affecount > 500 && dui == true) {
			dui = false;
			move_times -= 5;
			affe_rate *= 0.85;
			printf("Gov:the government has noticed the illness and taken action\n");
			printf("The infection rate has decreased\n");
			lao8hanbao
		}

		//event end
		int ti = move_times;
		//swap
		while (ti--) {
			int s1 = rand() % 1600 + 1;
			int s2 = rand() % 1600 + 1;
			int s3 = rand() % 1600 + 1;
			int s4 = rand() % 1600 + 1;

			hubei[0][0] = hubei[s1][s2];
			hubei[s1][s2] = hubei[s3][s4];
			hubei[s3][s4] = hubei[0][0];
		}
		//swap end
		for (int i = 1; i <= 1600; i++)
			for (int j = 1; j <= 1600; j++) {
				//** who don't go to the hospital
				if (day > 10) {
					int sb = q.affect - q.dead - q.curing - q.cured;
					while (sb--) {
						int big_rand = rand() % 2800 + 1;
						if (big_rand > 1000 && big_rand <= 1000 + die_rate / 2 * 3) {
							q.dead++;
							deadcount++;
						}
					}
				}
				int zdy;
				if (q.affe == false) { 
					continue;
					dbg1();
				}

				if (q.a_affe == false) {
					dbg2();
					zdy = day > 10 ? 480 : 240;
					int kdzdy = (q.affect + 3) / 4;
					while (kdzdy--) {
						if (rand() % zdy > affe_rate) continue;
						q.affect++;
						affecount++;
					}
					if (q.affect >= 20) {
						affecount = affecount - q.affect + 20;
						q.affect = 20;
						q.a_affe = true;
					}
				}
				// spreading

				dbg3();
				zdy = day > 10 ? 520 : 260;
				int kdzdy = (q.a_affe - q.dead - q.cured + 4) / 3;//ke dei zhu dian yi le
				if (i - 1 != 0 && hubei[i - 1][j].a_affe == false) {
					int k = kdzdy;
					dbg5();
					while (k--) {
						if (rand() % zdy > affe_rate) {
							printf_s("k is %d\n", k);
							dbgq();
							continue;
						}
						if (hubei[i - 1][j].affe == false) {
							dbgw(); hubei[i - 1][j].affe = true;
						}
						hubei[i - 1][j].affect++; dbge();
						affecount++;
					}
					dbg5();
				}
				if (i != 1600 && hubei[i + 1][j].a_affe == false) {
					int k = kdzdy;
					dbg6();
					while (k--) {
						if (rand() % zdy > affe_rate) {
							printf_s("k is %d\n", k);
							dbgq();
							continue;
						}
						if (hubei[i + 1][j].affe == false) {
							dbgw(); hubei[i + 1][j].affe = true;
						}
						hubei[i + 1][j].affect++; dbge();
						affecount++;
					}
					dbg6();
				}
				if (j - 1 != 0 && hubei[i][j - 1].a_affe == false) {
					int k = kdzdy;
					dbg7();
					while (k--) {
						if (rand() % zdy > affe_rate) {
							printf_s("k is %d\n", k);
							dbgq();
							continue;
						}
						if (hubei[i][j - 1].affe == false) {
							dbgw(); hubei[i][j - 1].affe = true;
						}
						hubei[i][j - 1].affect++; dbge();
						affecount++;
					}
					dbg7();
				}
				if (j != 1600 && hubei[i][j + 1].a_affe == false) {
					int k = kdzdy;
					dbg8();
					while (k--) {
						if (rand() % zdy > affe_rate) {
							printf_s("k is %d\n", k);
							dbgq();
							continue;
						}
						if (hubei[i][j + 1].affe == false) {
							dbgw(); hubei[i][j + 1].affe = true;
						}
						hubei[i][j + 1].affect++; dbge();
						affecount++;
					}
					dbg8();
				}
				dbg4();
				//  go to the hospital!!!
				if (day < 10) continue;
				int lixi = q.affect - q.curing - q.cured - q.dead;
				while (lixi--) {
					if (hosCap > inhos) {
						int lzj = rand() % 9;
						if (lzj != 1) {
							q.curing++;
							inhos++;
						}
					}
				}
				//cured and dead
				int u1s1 = q.curing;
				while (u1s1--) {
					int z = rand() % 4000 + 1;
					if (z > 1000 && z <= 1000 + cure_abi * 3 / 2) {
						curcount++;
						inhos--;
						q.curing--;
						q.cured++;
					}
					if (z > 300 && z <= 300 + die_rate * 10 / 9) {
						deadcount++;
						q.dead++;
						q.curing--;
						inhos--;
					}
				}
			}
		//print  situation

			printf("The day:%d\nDeath count:%d\nCured count:%d\nThe number in the hospital:%d\nTotal affected number:%d\n",
			day, deadcount, curcount, inhos, affecount);
//		lao8hanbao
//			system("cls");
		//the chance to change the data
		if (day == 30 || day == 80 || day == 150 || day == 250) {
			printf("Now you have the chance to build the hospital\nyou can add the number of hospital's beds\ninput a number to add(0<=n<=15000)");
			int ww;
		kehaixing:
			scanf("%d", &ww);
			if (ww < 0 || ww>15000) {
				printf("Being a person please.Input the number again!!!\nThe number:");
				goto kehaixing;
			}
			hosCap += ww;
//			system("cls");
		}
	}
}
