/*
Example 1
Using switch-case to handle Keyboard input
*/
#include <ncurses.h>
#include <stdio.h>

void switch_case();
void dispatcher();

void Move(int);
void Run();
void Attack();

void initial()
{
	initscr(); // Initialize curse scheme
	noecho(); // No echo in curse
	nodelay(stdscr, TRUE); // work in a non-blocking manner
	// keypad(stdscr, TRUE); // Using special keys
	refresh(); // Update the screen
}

int main()
{
	initial();
	switch_case();
	return 0;
}

void switch_case()
{
	int ch;
	do
	{
		if ((ch = getch()) == ERR)
		{
			//   user hasn't responded
            continue;
		}
		else
		{
			//   user has pressed a key ch
			clear(); // Clean the screen
			// printw("ch=%d\n", ch); // Print input character
			switch (ch)
			{
			case 'a':
			case 'd':
			case 's':
			case 'w':
                Move(ch);
				break;
			case 'r':
				Run();
                break;
			case 'j':
				Attack();
				break;
			}
		}
		refresh();
	} while (ch != 'q');
	// end curses scheme
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