#include <ncurses.h>
#include <string>

int main() {
	initscr();

	curses::stdscr
	erase();
	move(10, 20);
	refresh();

	timeout(-1);
	getch();

	endwin();
	return 0;
}
