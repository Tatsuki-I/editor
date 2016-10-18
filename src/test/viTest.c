#include <curses.h>

int main(void)
{
	int x = 0;
    int y = 0;
    int key;

    initscr();       // ウィンドウの初期化
    noecho();        // キーボードのエコーをしない
	keypad(stdscr, TRUE);

    for (;;) {       // 終わり方がわからん(汗)
        key = getch(); // getcharみたいな

        switch (key) {
        case KEY_LEFT : x--; break;
        case KEY_DOWN : y++; break;
        case KEY_UP : y--; break;
        case KEY_RIGHT : x++; break;
        }

        move(10, 20);             // デバッグ用
        printw("(%d, %d)", x, y); // x,y座標だと違和感アリ

        move(y, x); // 行、列
        refresh();  // 描画
    }

    return 0;
}
