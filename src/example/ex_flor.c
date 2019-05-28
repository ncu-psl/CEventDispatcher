#include <stdio.h>
#include <iostream>

using namespace std;

bool mode = 1;
bool match = 0;
bool isFinish = false;

int r0 = 1, r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0;
int x0 = 1, x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0;
int x10 = 1, x11 = 0, x12 = 0;
int x20 = 1, x21 = 0, x22 = 0;
int x30 = 1, x31 = 0, x32 = 0, x33 = 0, x34 = 0;
int x40 = 1, x41 = 0, x42 = 0, x43 = 0;
int x50 = 1, x51 = 0, x52 = 0;

void grafcet();

void grafcet_Configurator();
void grafcet_Color_Matching();
void grafcet_FG_Pixel_Matching();
void grafcet_His_Matching();
void grafcet_ShowResult();

void action0();
void action1();
void action2();
void action3();
void action4();
void action5();

/*COLOR*/
void BGR2IHS();
void compare_H();
/*fgp*/
void Blur_compute_stddev();
void Find_fgPixel();
void compare_fg_pixel();
/*HIS*/
void action4();
void initialize();
void calculation();
void comparison();

int main(void)
{
	while(1){
		isFinish = false;
		r5=0;
		r0=1;
		cout << "mode = " << mode << endl;
		cout << "r0 = " << r0 << " r1 = " << r1 << " r2 = " << r2 << " r3 = " << r3 << " r4 = " << r4 << " r5 = " << r5 << endl;
		cout << "x0 = " << x0 << " x1 = " << x1 << " x2 = " << x2 << " x3 = " << x3 << " x4 = " << x4 << " x5 = " << x5 << endl;
		cout << "x10 = " << x10 << " x11 = " << x11 << endl;
		cout << "x20 = " << x20 << " x21 = " << x21 << " x22 = " << x22 << endl;
		cout << "x30 = " << x30 << " x31 = " << x31 << " x32 = " << x32 << " x33 = " << x33 << endl;
		cout << "x40 = " << x40 << " x41 = " << x41 << " x42 = " << x42 << " x43 = " << x43 << endl;
		cout << "x50 = " << x50 << " x51 = " << x51 << endl;
		system("pause");
		while(!isFinish){
			grafcet();
			//cout << isFinish << endl;
			cout << "r0 = " << r0 << " r1 = " << r1 << " r2 = " << r2 << " r3 = " << r3 << " r4 = " << r4 << " r5 = " << r5 << endl;
			cout << "x0 = " << x0 << " x1 = " << x1 << " x2 = " << x2 << " x3 = " << x3 << " x4 = " << x4 << " x5 = " << x5 << endl;
			cout << "x10 = " << x10 << " x11 = " << x11 << endl;
			cout << "x20 = " << x20 << " x21 = " << x21 << " x22 = " << x22 << endl;
			cout << "x30 = " << x30 << " x31 = " << x31 << " x32 = " << x32 << " x33 = " << x33 << endl;
			cout << "x40 = " << x40 << " x41 = " << x41 << " x42 = " << x42 << " x43 = " << x43 << endl;
			cout << "x50 = " << x50 << " x51 = " << x51 << endl;
			system("pause");
		}
		cout << "finish" << endl;
		system("pause");
	}
}

void grafcet()
{
	if (x0 == 1 && r0 == 1) { x0 = 0; x1 = 1; }
	else if (x1 == 1 && r1 == 1) { x1 = 0; x2 = 1; }
	else if (x2 == 1 && r2 == 1) { x2 = 0; x3 = 1; }
	else if (x3 == 1 && r3 == 1) { x3 = 0; x4 = 1; }
	else if (x4 == 1 && r4 == 1) { x4 = 0; x5 = 1; }
	else if (x5 == 1 && r5 == 1) { x5 = 0; x0 = 1; isFinish = true; }
	action0();
}

void grafcet_Configurator()
{
	if (x1 == 1 && x10 == 1) { x10 = 0; x11 = 1; }
	else if (x1 == 1 && x11 == 1) { x11 = 0; x10 = 1; }
	action1();
}

void grafcet_Color_Matching()
{
	if (x2 == 1 && x20 == 1) { x20 = 0; x21 = 1; }
	else if (x2 == 1 && x21 == 1) { x21 = 0; x22 = 1; }
	else if (x2 == 1 && x22 == 1) { x22 = 0; x20 = 1; }
	action2();
}

void grafcet_FG_Pixel_Matching()
{
	if (x3 == 1 && x30 == 1) { x30 = 0; x31 = 1; }
	else if (x3 == 1 && x31 == 1) { x31 = 0; x32 = 1; }
	else if (x3 == 1 && x32 == 1) { x32 = 0; x33 = 1; }
	else if (x3 == 1 && x33 == 1) { x33 = 0; x30 = 1; }
	action3();
}

void grafcet_His_Matching()
{
	if (x4 == 1 && x40 == 1) { x40 = 0; x41 = 1; }
	else if (x4 == 1 && x41 == 1) { x41 = 0; x42 = 1; }
	else if (x4 == 1 && x42 == 1 && mode == 0) { x42 = 0; x40 = 1; }
	else if (x4 == 1 && x42 == 1 && mode == 1) { x42 = 0; x43 = 1; }
	else if (x4 == 1 && x43 == 1) { x43 = 0; x40 = 1; }
	action4();
}

void grafcet_ShowResult()
{
	if (x5 == 1 && x50 == 1) { x50 = 0; x51 = 1; }
	else if (x5 == 1 && x51 == 1) { x51 = 0; x50 = 1; }
	action5();
}

void action0()
{
	if (x1 == 1) { grafcet_Configurator(); }
	else if (x2 == 1) { grafcet_Color_Matching(); }
	else if (x3 == 1) { grafcet_FG_Pixel_Matching(); }
	else if (x4 == 1) { grafcet_His_Matching(); }
	else if (x5 == 1) { grafcet_ShowResult(); }
}

void action1()
{
	//////////
	r0 = 0;
	r1 = 1;
}

void action2()
{
	if (x21 == 1) { BGR2IHS(); }
	else if (x22 == 1 && mode == 1) { compare_H(); }
}

void action3()
{
	if (x31 == 1) { Blur_compute_stddev(); }
	else if (x32 == 1) { Find_fgPixel(); }
	else if (x33 == 1 && mode == 1) { compare_fg_pixel(); }
}

void action4()
{
	if (x41 == 1) { initialize(); }
	else if (x42 == 1) { calculation(); }
	else if (x43 == 1) { comparison(); }
}

void action5()
{
	//////
	r4 = 0;
	r5 = 1;
}

void BGR2IHS()
{
	cout << "BGR2IHS" << endl;
	if(mode == 0){
		r1=0;
		r2=1;
	}
}

void compare_H()
{
	cout << "compare_H" << endl;
	r1=0;
	r2=1;
}

void Blur_compute_stddev()
{
	cout << "Blur_compute_stddev" << endl;
}

void Find_fgPixel()
{
	cout << "Find_fgPixel" << endl;
	if(mode == 0){
		r2=0;
		r3=1;
	}
}

void compare_fg_pixel()
{
	cout << "compare_fg_pixel" << endl;
	r2=0;
	r3=1;
}

void initialize()
{
	printf("initialize OK\n");
}

void calculation()
{
	printf("calculation OK\n");
	if (mode == 0) {
		r3 = 0;
		r4 = 1;
	}
}

void comparison()
{
	printf("comparison OK\n");
	r3=0;
	r4=1;
}





/************************************************************************************/
int main(){
    handler action1, action2, action3;
    int x[5], r[5], x2[2];
    add(action0, grafcet_Configurator,      x[1] == 1 && r[1] == 1);
    add(action0, grafcet_Color_Matching,    x[2] == 1 && r[2] == 1);
    add(action0, grafcet_FG_Pixel_Matching, x[3] == 1 && r[3] == 1);
    add(action0, grafcet_His_Matching,      x[4] == 1 && r[4] == 1);
    add(action0, grafcet_ShowResult,        x[5] == 1 && r[5] == 1);
    add(action2, BGR2IHS    , x[2] == 1 && x2[1] == 1);
    add(action2, compare_H  , x[2] == 1 && x2[2] == 1);

    while(!finish){
        run(action0, x, r);
        run(action1, x);
        run(action2, x, x2);
    }
    return 0;
}