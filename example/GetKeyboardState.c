// /*
//  * GetAsyncKeyState() function in Windows.h library
//  * Can't use in Linux environment
// */
#include <Windows.h>
#include <stdio.h>
#include "../src/CED.h"

#define keydown 0x8000
#define A_KEY 0x41
#define D_KEY 0x44
#define S_KEY 0x53
#define W_KEY 0x57
#define J_KEY 0x4A
#define Q_KEY 0x51

enum driect{up, down, left, right};
const char* direct_[]={"up", "down", "left", "right"};

void move(int);
void run(int);
void attack();

void example(){
	unsigned short buff[256] = {0};
    unsigned short kval;
    int i;
	
    printf("example\n");

	while (!(GetAsyncKeyState(Q_KEY) & keydown)) {
        for(i=0; i<256; i++) {
            kval = GetAsyncKeyState(i);
            if(kval != buff[i]) {
                printf("%02X:%04X\n", i, kval);
                buff[i] = kval;
            }
        }
    }
}

void if_else1(){
    printf("if_else1\n");

    while(!(GetAsyncKeyState(Q_KEY) & keydown)){
		if((GetAsyncKeyState(A_KEY) & keydown) && (GetAsyncKeyState(VK_SHIFT) & keydown)){
			run(left);
		}else if((GetAsyncKeyState(D_KEY) & keydown) && (GetAsyncKeyState(VK_SHIFT) & keydown)){
			run(right);
		}else if((GetAsyncKeyState(S_KEY) & keydown) && (GetAsyncKeyState(VK_SHIFT) & keydown)){
			run(down);
		}else if((GetAsyncKeyState(W_KEY) & keydown) && (GetAsyncKeyState(VK_SHIFT) & keydown)){
			run(up);
		}else if(GetAsyncKeyState(A_KEY) & keydown){
			move(left);
		}else if(GetAsyncKeyState(D_KEY) & keydown){
			move(right);
		}else if(GetAsyncKeyState(S_KEY) & keydown){
			move(down);
		}else if(GetAsyncKeyState(W_KEY) & keydown){
			move(up);
		}
		if((GetAsyncKeyState(J_KEY) & keydown)){
			attack();
		}
	}
}

void if_else2(){
    printf("if_else2\n");

    while (!(GetAsyncKeyState(Q_KEY) & keydown))
	{
		if ((GetAsyncKeyState(A_KEY) & keydown) 
		 || (GetAsyncKeyState(D_KEY) & keydown) 
		 || (GetAsyncKeyState(S_KEY) & keydown) 
		 || (GetAsyncKeyState(W_KEY) & keydown))
		{
			if (GetAsyncKeyState(VK_SHIFT) & keydown)
			{
				run(0);
			}
			else
			{
				move(0);
			}
		}
        else if(GetAsyncKeyState(J_KEY) & keydown){
			attack();
        }
	}
}

void dispatcher(){
    Handler1(action);
    add(&action, move(), GetAsyncKeyState(A_KEY) & keydown));

}

void move(int direct)
{
	printf("move %s\n", direct_[direct]);
}

void run(int direct)
{
	printf("run %s\n", direct_[direct]);
}

void attack()
{
	printf("attack\n");
}

int main()
{
    // example();
    // if_else1();
    // if_else2();
    dispatcher();
	return 0;
}