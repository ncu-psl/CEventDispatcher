/*
Example 2
Using CED to handle Keyboard input
*/
#include "../src/CED.h"
#include <ncurses.h>
#include <stdio.h>

void KeyboardInput_Subscriber();
void KeyboardInput_Dispatcher();

void Move(int);
void Run();
void Attack();

void initial()
{
	initscr();			   // Initialize curse scheme
	noecho();			   // No echo in curse
	nodelay(stdscr, TRUE); // work in a non-blocking manner
	// keypad(stdscr, TRUE); // Using special keys
	refresh(); // Update the screen
}

int main()
{
	initial();
	KeyboardInput_Subscriber();
	KeyboardInput_Dispatcher();
	return 0;
}

/* KeyboardInput_Dispatcher */

Dispatcher(keyboardInput);

void KeyboardInput_Subscribe()
{
	add(&keyboardInput, Move, ch == 'a' || ch == 's' || ch == 'd' || ch == 'w');
	add(&keyboardInput, Run, ch == 'r');
	add(&keyboardInput, Attack, ch == 'j');
}
void KeyboardInput_Dispatcher()
{
	int ch[1] = {0};
	do
	{
		if ((ch[0] = getch()) == ERR)
		{
		}
		else
		{
			clear();
			run(&keyboardInput, ch);
			refresh();
		}

	} while (ch[0] != 'q');
	getchar();
	endwin();
}

void Move(int direct)
{
	printw("%d Move ", direct);

	switch (direct)
	{
	case 'a':
		printw("left");
		break;
	case 'd':
		printw("right");
		break;
	case 's':
		printw("down");
		break;
	case 'w':
		printw("up");
		break;
	}
	printw("\n");
}
void Run()
{
	printw("Run\n");
}

void Attack()
{
	printw("Attack\n");
}