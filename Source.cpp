#include "HorizontalMove.h"
#include "keyboardClick.h"
#include "MouseLeftClick.h"
#include "MouseRightClick.h"
#include "ShuffleHorizontalMove.h"
#include "ShuffleVerticalMove.h"
#include "VerticalMove.h"

int legal(){
	string charToChange;
	int num = 0;
	cin >> charToChange;
	cout << endl;

	if (charToChange.length() > 1){ charToChange.clear(); return 0; }

	for (int i = charToChange.length() - 1, pow = 1; i >= 0; i--, pow *= 10){
		if (!isdigit(charToChange[i]))return 0;
		num += (charToChange[i] - '0') * pow;
	}

	return num;
}

int main()
{
	char choiceStr[100];
	while (true){
		cout << " 1. �ƹ�����s�I\n"
			 << " 2. �ƹ��k��s�I\n"
			 << " 3. �����Ӧ^���ʷƹ�\n"
			<< " 4. �����Ӧ^���ʷƹ�\n"
			<< " 5. �����즲�Ӧ^���ʷƹ�\n"
			<< " 6. �����즲�Ӧ^���ʷƹ�\n"
			<< " 7. ����L�W�Y�ӫ���ós��\n\n";
		Auto *action;

		switch (legal())
		{
		case 1:
			action = new MouseLeftClick;
			action->run();
			delete action;
			break;
		case 2:
			action = new MouseLeftClick;
			action->run();
			delete action;
			break;
		case 3:
			action = new HorizontalMove;
			action->run();
			delete action;
			break;
		case 4:
			action = new VerticalMove;
			action->run();
			delete action;
			break;
		case 5:
			action = new ShuffleHorizontalMove;
			action->run();
			delete action;
			break;
		case 6:
			action = new ShuffleVerticalMove;
			action->run();
			delete action;
			break;
		case 7:
			action = new keyboardClick;
			action->run();
			delete action;
			break;

		default:
			break;
		}
		keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0);

		system("CLS");
	}

	return 0;
}