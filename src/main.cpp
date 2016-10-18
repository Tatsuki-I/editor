/*
 * #Editor
 * Author Tatsuki-I
 *
 * ##about
 * This is (will be) a Text Editor.
 * It's my practice about C++.
 *
 * ##compile option
 * ` clang++ main.cpp -lncurses -std=c++1y `
 */
#include <iostream>
#include <string>
#include <ncurses.h>

#include <fstream>
#include <sstream>

int main(int argc, char** argv) {
	std::string filename = argv[1];
	std::string spacebar;
	std::string number;
	int x, y, w, h;
	int key;
	
	//initialise terminal
	initscr();
	
	//set colors
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_YELLOW, COLOR_BLUE);
	
	//get window size
	getmaxyx(stdscr, h, w);

	//set x in the center
	x = (w - filename.length()) / 2;
	
	//set y
	y = 0;

	//male spacebar
	for(int i = 0; i < w; i++){
		spacebar.insert(0, " ");
	}

	//display titlebar
	attrset(COLOR_PAIR(1));
	attron(A_BOLD);
	mvprintw(y, 0, spacebar.c_str());
	mvprintw(y, x, filename.c_str());
	attrset(0);
	attroff(A_BOLD);
	y++;
		
	//display line number
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

	//open file
	std::ifstream readFile;
	readFile.open(filename.c_str(), std::ios::in);
	std::string readLineBuffer;
	y = 1;
	while(!readFile.eof()) {
		std::getline(readFile, readLineBuffer);
		mvprintw(y, 4, readLineBuffer.c_str());
		y++;
	}
	
	//display tool bar
	attrset(COLOR_PAIR(1));
	attron(A_BOLD);
	mvprintw((h - 1), 0, spacebar.c_str());
    mvprintw((h - 1), (w - 10), "%2d,%1d", y, x - 4);
	attrset(0);
	attroff(A_BOLD);

	//make enable cursor keys
    noecho();
	keypad(stdscr, TRUE);
	move(1, 4);
    while(1) {
        key = getch();
		if (key == 'q')
			return 0;
//			break;
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
		mvprintw((h - 1), 0, spacebar.c_str());
        mvprintw((h - 1), (w - 10), "%2d,%1d", y, x - 4);
		attrset(0);
		attroff(A_BOLD);

        move(y, x);
        refresh();
    }


	endwin();
	return 0;
}
