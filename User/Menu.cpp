#include "Menu.h"
#include "Visitors.h"
#include "Operations.h"
#include "Errors.h"
#include "Trainers.h"
#include "VisualComponent.h"
#include "Decorator.h"
#include <iostream>
using namespace std;

void  Menu::Show_Menu_Gym()
{

	char input;

	do {
		window.Draw(&decorator);
		//window.SetColor(&decorator, 2);
		mainMenu();

		cin >> input;

		Safe_Selection(input);

		cout << endl;


	} while (input != '0');
}

void Menu::mainMenu()
{
	cout << "<--------------------------------------------------------------->" << endl;
	cout << "| " << "Hello! This is your favorite gym \"Perfect Body\"" << "               |" << endl;
	cout << "| " << "Choose an operation: " << "                                         |" << endl;
	cout << "| " << "1 - To view registered visitors" << "                               |" << endl;
	cout << "| " << "2 - To view trainers" << "                                          |" << endl;
	cout << "| " << "3 - To set text color" << "                                         |" << endl;
	cout << "| " << "M - To view the most experience trainer" << "                       |" << endl;
	cout << "| " << "0 - To exit." << "                                                  |" << endl;
	cout << "<--------------------------------------------------------------->" << endl;
}


void Menu::Safe_Selection(char input)
{
	try
	{
		Selection(input);
	}
	catch (Errors& error)
	{
		cout << "Ups... we found an error! " << error.ShowErrors() << endl;
	}
	catch (...)
	{
		cout << "Some errors were found! " << endl;
	}
}

void Menu::SetTextColor()
{
	int temp_num = 0;
	cout << "Enter a number to set new text color: ";
	cin >> temp_num;
	window.SetColor(&decorator, temp_num);
}

void Menu::Selection(char input)
{
	switch (input)
	{
	case '1':
		operation.show_Visitors();
		cout << endl;
		break;
	case '2':
		operation.show_Trainers();
		break;
	case '3':
		SetTextColor();
		break;
	case 'M':
		operation.the_most_experienced_trainer();
		break;
	case '0':
		break;
	default:
		cout << "Error! You chose wrong operation!\n";
		break;
	}
}

