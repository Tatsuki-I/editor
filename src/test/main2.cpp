#include <iostream>
#include <string>
#include <ncurses.h>

#include <fstream>
#include <sstream>

int main(int argc, char** argv) {
	std::string filename = argv[1];
	std::string title;
	std::string number;
	int x, y, w, h;
	int key;
	y = 0;

	initscr();
	
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_YELLOW, COLOR_BLUE);

	getmaxyx(stdscr, h, w);
	for(int i = 0; i < (w - filename.length()); i++){
		title.insert(0, " ");
	}
	title.insert((title.length() / 2), filename);

	attrset(COLOR_PAIR(1));
	attron(A_BOLD);
	mvprintw(y, 0, title.c_str());
	attrset(0);
	attroff(A_BOLD);
	y++;
		
	attrset(COLOR_PAIR(2));
	attron(A_BOLD);
	for(int i = 0; i < h - 2; i++){
		number = std::to_string(i + 1);
		if((i + 1) < 10){
			number.insert(0, " ");
		}
		number.insert(0, " ");
		number.insert(3, " ");
		mvprintw(y, 0, number.c_str());
		y++;
	}
	attrset(0);
	attroff(A_BOLD);

	std::ifstream readFile;
	readFile.open(filename.c_str(), std::ios::in);

	std::string readLineBuffer;
	y = 1;
	while(!readFile.eof()) {
		std::getline(readFile, readLineBuffer);
		mvprintw(y, 4, readLineBuffer.c_str());
		y++;
	}

	attrset(COLOR_PAIR(1));
	attron(A_BOLD);
    mvprintw((h - 1), (w - filename.length()), "(%2d, %2d)", x, y);
	attrset(0);
	attroff(A_BOLD);


    noecho();
	move(1, 4);
	keypad(stdscr, TRUE);
    for (;;) {
        key = getch();
        switch (key) {
   		 	case KEY_LEFT :
				if(x > 4)
					x--;
				break;
			case KEY_UP :
				if(y > 1)
					y--;
				break;
   		 	case KEY_RIGHT :
				if(x < (w - 2))
					x++;
				break;
			case KEY_DOWN :
				if(y < (h - 2))
					y++;
				break;
       	}

		attrset(COLOR_PAIR(1));
		attron(A_BOLD);
        mvprintw((h - 1), (w - filename.length()), "(%2d, %2d)", x, y);
		attrset(0);
		attroff(A_BOLD);

        move(y, x);
        refresh();
    }

	getch();

	endwin();
	return 0;
}
