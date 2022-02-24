#pragma once
#include <iostream>
#include "VisualComponent.h"
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

class Decorator : public VisualComponent 
{
public:
	HANDLE hConsole;
	void Draw() override
	{
		cout << "----------------------------------------------->" << endl;
		cout << "----------------------------------------------------------->" << endl << endl << endl;
		cout << "<------------------------------------------------------------" << endl << endl << endl;
		cout << "<------------------------------------------------------------------" << endl << endl << endl;

	}
	void SetColor(int&temp) override
	{
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, temp);
	}

};

