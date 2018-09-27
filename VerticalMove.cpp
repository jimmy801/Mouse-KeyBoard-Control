#include "VerticalMove.h"

#define TITLE 	system("cls");cout << "\n 4. 垂直來回移動滑鼠\n(先按一下F2設定起點，再按一下F2設定終點，按S暫停/繼續，ESC回選單)\n\n";

void VerticalMove::run(){
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
			GO = 0;
			TITLE;
			cout << "\n 按S繼續，ESC回選單\n\n";
			keybd_event('S', 0, KEYEVENTF_KEYUP, 0);
		}

		if (GetKeyState('S') < 0 && !GO){
			GO = 1;
			TITLE;
			cout << "\n 按S暫停，ESC回選單\n\n";
			keybd_event('S', 0, KEYEVENTF_KEYUP, 0);
		}

		if (GO){
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