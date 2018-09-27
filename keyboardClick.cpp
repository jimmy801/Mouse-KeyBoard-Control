#include "keyboardClick.h"

#define TITLE system("cls");cout << "\n 7. 按鍵盤上某個按鍵並連打\n(先按一下要連按的按鍵，按F2暫停/繼續，ESC回選單)\n\n";

keyboardClick::keyboardClick(){
	keyName["F1"] = VK_F1;
	keyName["F2"] = VK_F2;
	keyName["F3"] = VK_F3;
	keyName["F4"] = VK_F4;
	keyName["F5"] = VK_F5;
	keyName["F6"] = VK_F6;
	keyName["F7"] = VK_F7;
	keyName["F8"] = VK_F8;
	keyName["F9"] = VK_F9;
	keyName["F10"] = VK_F10;
	keyName["F11"] = VK_F11;
	keyName["F12"] = VK_F12;
	keyName["esc"] = VK_ESCAPE;
	keyName["`"] = 192;
	keyName["L_-"] = 189;
	keyName["="] = 187;
	keyName["Backspace"] = 8;
	keyName["tab"] = 9;
	keyName["["] = 219;
	keyName["]"] = 221;
	keyName["\\"] = 220;
	keyName["Caps Lock"] = 20;
	keyName[";"] = 186;
	keyName["'"] = 222;
	keyName["shift"] = 16;
	keyName[","] = 188;
	keyName["."] = 190;
	keyName["L_/"] = 191;
	keyName["Ctrl"] = 17;
	keyName["Win"] = 91;
	keyName["Alt"] = 18;
	keyName["Space"] = 32;
	keyName["Up"] = 25;
	keyName["Down"] = 40;
	keyName["Left"] = 37;
	keyName["Right"] = 39;
	keyName["Menu"] = 93;
	keyName["Enter"] = 13;
	keyName["Pause"] = 19;
	keyName["Del"] = 46;
	keyName["Home"] = 36;
	keyName["PgUp"] = 33;
	keyName["PgDn"] = 34;
	keyName["End"] = 35;
	keyName["R_/"] = 160;
	keyName["Num Lock"] = 144;
	keyName["*"] = 106;
	keyName["R_-"] = 109;
	keyName["Ins"] = 45;
	keyName["Scroll Lock"] = 145;
	keyName["."] = 110;
}

void keyboardClick::run(){

	GohanConsoleHelper a;
	int GO = 1;

	TITLE;
	cout << "\n 按F2暫停，ESC回選單\n\n";
	ReadKey(a);
	ShowKey(a);
	while (true){
		if (GetKeyState(VK_ESCAPE) >= 0){

			if (GO){
				keybd_event(a.VKey, 0, 0, 0);
				keybd_event(a.VKey, 0, KEYEVENTF_KEYUP, 0);
				Sleep(40);
			}

			if (GetKeyState(VK_F2) < 0 && GO){ /* Press F2 now */
				GO = 0;
				TITLE;
				cout << "\n 按F2繼續，ESC回選單\n\n";

				keybd_event(a.VKey, 0, KEYEVENTF_KEYUP, 0);
				keybd_event(VK_F2, 0, KEYEVENTF_KEYUP, 0);
			}

			if (GetKeyState(VK_F2) < 0 && !GO){
				TITLE;
				cout << "\n 按的按鍵是 ";
				ShowKey(a);
				cout << "\n 按F2暫停，ESC回選單\n\n";
				GO = 1;
				keybd_event(VK_F2, 0, KEYEVENTF_KEYUP, 0);
			}
		}
		else {
			keybd_event(a.VKey, 0, KEYEVENTF_KEYUP, 0);
			Sleep(100);
			break;
		}
	}
}

void keyboardClick::ReadKey(GohanConsoleHelper&a){
	cout << "\n 按的按鍵是 ";
	while (true){
		if (!(a.ReadKeyPush())){
			if (a.VKey == 0 || a.VKey == 19){ TITLE; continue; }
			break;
		}
	}
}

void keyboardClick::ShowKey(GohanConsoleHelper&a){

	if (isdigit(a.VKey))cout << "L_" << (char)a.VKey << endl;
	else if (isupper(a.VKey))cout << (char)a.VKey << endl;
	else if (a.VKey > 95 && a.VKey < 106)cout << "R_" << a.VKey - 96;
	else {
		for (map<string, int>::iterator it = keyName.begin(); it != keyName.end(); it++)
		if (it->second == a.VKey){ cout << it->first << endl; break; }
	}
	cout << "\n 開始連按...\n";
}