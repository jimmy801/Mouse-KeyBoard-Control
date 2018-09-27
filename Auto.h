#ifndef AUTO_H
#define AUTO_H

#include <iostream>
#include <string>
#include "GohanConsoleHelper.h"

using namespace std;

class Auto{
public:
	virtual void run() = 0;

	int legal(int less){

		num = 0;
		cin >> charToChange;
		cout << endl;

		if (charToChange.length() > 99)return 0;

		for (int i = charToChange.length() - 1, pow = 1; i >= 0; i--, pow *= 10){
			if (!isdigit(charToChange[i]))return 0;
			num += (charToChange[i] - '0') * pow;
		}
		if (num < less)return 0;
		return num;
	}

protected:
	double num;

private:
	string charToChange;
};

#endif