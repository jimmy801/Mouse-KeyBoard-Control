#include "HorizontalMove.h"

#define TITLE system("cls");cout << "\n 3. �����Ӧ^���ʷƹ�\n(�����@�UF2�]�w�_�I�A�A���@�UF2�]�w���I�A��S�Ȱ�/�~��AESC�^���)\n\n";

void HorizontalMove::run(){
	POINT a;
	POINT b;
	POINT c;

	TITLE;
	cout << "\n�Ы�F2�]�w�_�I\n";

	while (GetKeyState(VK_F2) <= 0){
		GetCursorPos(&a);
		keybd_event(VK_F2, 0, KEYEVENTF_KEYUP, 0);
	}
	TITLE;
	cout << "\n�Ы�F2�]�w���I\n";
	while (GetKeyState(VK_F2) >= 0)GetCursorPos(&b);

	SetCursorPos(a.x, a.y);
	int GO = 1;

	keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0);
	TITLE;
	cout << "\n ��S�Ȱ��AESC�^���\n\n";

	while (GetKeyState(VK_ESCAPE) >= 0){

		if (GetKeyState('S') < 0 && GO){ /* Press S now */
			TITLE;
			cout << "\n ��S�~��AESC�^���\n\n";
			GO = 0;
			keybd_event('S', 0, KEYEVENTF_KEYUP, 0);
		}

		if (GetKeyState('S') < 0 && !GO){
			TITLE;
			cout << "\n ��S�Ȱ��AESC�^���\n\n";
			GO = 1;
			keybd_event('S', 0, KEYEVENTF_KEYUP, 0);
		}

		if (GO){
			GetCursorPos(&c);
			if (a.x < b.x){
				if (c.x >= b.x || c.x < a.x)SetCursorPos(a.x, c.y);
				mouse_event(MOUSEEVENTF_MOVE, 1, 0, 0, 0);
			}
			if (a.x > b.x){
				if (c.x <= b.x || c.x > a.x)SetCursorPos(a.x, c.y);
				mouse_event(MOUSEEVENTF_MOVE, -1, 0, 0, 0);
			}
		}
	}
}