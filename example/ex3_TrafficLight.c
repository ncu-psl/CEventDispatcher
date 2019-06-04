/*
Example 3
Using CED to make FSM of traffic light
*/
#include "../src/CED.h"
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

//  Traffic Light state
void RedLight();
void GreenLight();
void YellowLight();

void TrafficLight();

Dispatcher(trafficLight);

int main()
{
	add(&trafficLight, RedLight, (t % 10) == 0);
	add(&trafficLight, GreenLight, (t % 10) == 3);
	add(&trafficLight, YellowLight, (t % 10) == 8);
	TrafficLight();
	return 0;
}

void TrafficLight()
{
	int t[1]={-1};
	time_t start, now;
	start = time(NULL);
	while (1)
	{
		now = time(NULL);
		if (t[0] != (now - start))
		{
            t[0] = (int)(now - start);
			printf("%d\n", t[0]);
		    run(&trafficLight, t);
		}
	}
}

void RedLight()
{
	printf("    RED\n");
};
void GreenLight()
{
	printf("    GREEN\n");
};
void YellowLight()
{
	printf("    YELLOW\n");
};