#include "VerticalMove.h"

#define TITLE 	system("cls");cout << "\n 4. �����Ӧ^���ʷƹ�\n(�����@�UF2�]�w�_�I�A�A���@�UF2�]�w���I�A��S�Ȱ�/�~��AESC�^���)\n\n";

void VerticalMove::run(){
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
			GO = 0;
			TITLE;
			cout << "\n ��S�~��AESC�^���\n\n";
			keybd_event('S', 0, KEYEVENTF_KEYUP, 0);
		}

		if (GetKeyState('S') < 0 && !GO){
			GO = 1;
			TITLE;
			cout << "\n ��S�Ȱ��AESC�^���\n\n";
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