#include <stdbool.h>
#include <stdio.h>

void Event1_Register(){
    printf("1\n");
} // 加入事件1
void Event2_Register(){
    printf("2\n");
} // 加入事件2
void Event3_Register(){
    printf("3\n");
} // 加入事件3
void Event4_Register(){
    printf("4\n");
} // 加入事件4
void Event5_Register(){
    printf("5\n");
} // 加入事件5
void Event6_Register(){
    printf("6\n");
} // 加入事件6
void Event7_Register(){
    printf("7\n");
} // 加入事件7

void Event6_UnRegister(){
    printf("-6\n");
} // 取消事件6
void Event7_UnRegister(){
    printf("-7\n");
} // 取消事件7

bool VenderSubscribe2(int control)
{
	switch (control)
	{
	case 1:
		Event1_Register(); // 加入事件1
		Event2_Register(); // 加入事件2
		Event3_Register(); // 加入事件3
		Event4_Register(); // 加入事件4
		Event5_Register(); // 加入事件5
		break;
	case 2:
		Event6_Register(); // 加入事件6
		Event7_Register(); // 加入事件7
		break;
	case 3:
		Event6_UnRegister(); // 取消事件6
		Event7_UnRegister(); // 取消事件7
		break;
	}
}

int main()
{
	int n = 1;
	VenderSubscribe2(n);
	return 0;
}