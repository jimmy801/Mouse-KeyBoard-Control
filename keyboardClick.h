#pragma once
#define KEYBOARDCLICK_H

#include <map>
#include "Auto.h"

class keyboardClick :public Auto{
public:
	keyboardClick();
	void run();
private:
	void ReadKey(GohanConsoleHelper&);
	void ShowKey(GohanConsoleHelper&a);
	map <string, int> keyName;
};