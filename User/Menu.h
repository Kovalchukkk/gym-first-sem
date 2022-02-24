#ifndef MENU_H
#define MENU_H

#include "Operations.h"
#include "Window.h"
#include "Decorator.h"

class Menu
{
public:
	void Show_Menu_Gym();
private:
	Operations operation;
	void mainMenu();
	void Selection(char input);
	void Safe_Selection(char input);
	void SetTextColor();
	Window window;
	Decorator decorator;
};

#endif
