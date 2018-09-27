#include "MouseLeftClick.h"

#define TITLE system("cls");cout << "\n 1. 滑鼠左鍵連點\n(按S暫停/繼續，ESC回選單)\n\n";
#define START cout << "\n每秒按 " << 1000 / num << "次\n";cout << "\n按s暫停\n";
#define END cout << "\n按s繼續\n";

void MouseLeftClick::run(){

	int GO = 1;
	do{
		TITLE;
		cout << "每幾毫秒按一次?\n";
	} while (!legal(1));
	POINT a;

	keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0);

	TITLE;
	START;

	while (GetKeyState(VK_ESCAPE) >= 0){
		if (GetKeyState('S') < 0 && GO){ /* Press S now */
			TITLE;
			END;
			GO = 0;
			keybd_event('S', 0, KEYEVENTF_KEYUP, 0);
		}

		if (GetKeyState('S') < 0 && !GO){
			TITLE;
			START;
			GO = 1;
			keybd_event('S', 0, KEYEVENTF_KEYUP, 0);
		}

		if (GO){
			GetCursorPos(&a);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, a.x, a.y, 0, 0);
			Sleep(num);
		}
	}
}