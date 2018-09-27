#include "ShuffleVerticalMove.h"

#define TITLE 	system("cls");cout << "\n 6. 垂直拖曳來回移動滑鼠\n(先按一下F2設定起點，再按一下F2設定終點，按S暫停/繼續，ESC回選單)\n\n";

void ShuffleVerticalMove::run(){
	POINT a;
	POINT b;
	POINT c;

	TITLE;
	cout << "\n請按F2設定起點\n";
	while (GetKeyState(VK_F2) <= 0){
		GetCursorPos(&a);
		keybd_event(VK_F2, 0, KEYEVENTF_KEYUP, 0);
	}
	TITLE;
	cout << "\n請按F2設定終點\n";
	while (GetKeyState(VK_F2) >= 0)GetCursorPos(&b);

	SetCursorPos(a.x, a.y);
	int GO = 1;

	keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0);

	TITLE;
	cout << "\n 按S暫停，ESC回選單\n\n";

	while (GetKeyState(VK_ESCAPE) >= 0){

		if (GetKeyState('S') < 0 && GO){ /* Press S now */
			TITLE;
			cout << "\n 按S繼續，ESC回選單\n\n";
			GO = 0;
			keybd_event('S', 0, KEYEVENTF_KEYUP, 0);
			GetCursorPos(&c);
			mouse_event(MOUSEEVENTF_LEFTUP, c.x, c.y, 0, 0);
		}

		if (GetKeyState('S') < 0 && !GO){
			TITLE;
			cout << "\n 按S暫停，ESC回選單\n\n";
			GO = 1;
			keybd_event('S', 0, KEYEVENTF_KEYUP, 0);
		}

		if (GO){
			mouse_event(MOUSEEVENTF_LEFTDOWN, a.x, a.y, 0, 0);
			GetCursorPos(&c);
			if (a.y < b.y){
				if (c.y >= b.y || c.y < a.y)SetCursorPos(c.x, a.y);
				mouse_event(MOUSEEVENTF_MOVE, 0, 10, 0, 0);
			}
			if (a.y > b.y){
				if (c.y <= b.y || c.y > a.y)SetCursorPos(c.x, a.y);
				mouse_event(MOUSEEVENTF_MOVE, 0, -10, 0, 0);
			}
		}
	}
}