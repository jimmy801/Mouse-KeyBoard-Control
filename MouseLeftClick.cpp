#include "MouseLeftClick.h"

#define TITLE system("cls");cout << "\n 1. �ƹ�����s�I\n(��S�Ȱ�/�~��AESC�^���)\n\n";
#define START cout << "\n�C��� " << 1000 / num << "��\n";cout << "\n��s�Ȱ�\n";
#define END cout << "\n��s�~��\n";

void MouseLeftClick::run(){

	int GO = 1;
	do{
		TITLE;
		cout << "�C�X�@����@��?\n";
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