#ifndef MENU_H
#define MENU_H

#include "Operations.h"

class Menu
{
public:
	void Show_Menu_Gym();
private:
	Operations operation;
	void mainMenu();
	void Menu_Visitor_Add();
	void Menu_Trainer_Add();
	void Menu_Visitor_Delete();
	void Menu_Visitor_Delete_BY_INDEX();
	void Menu_Trainer_Delete_BY_INDEX();
	void Selection(char input);
	void Safe_Selection(char input);
	void Delete_Selection(char input_delete_char_tmp);

};

#endif