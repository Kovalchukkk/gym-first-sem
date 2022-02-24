#include "Menu.h"
#include "Visitors.h"
#include "Operations.h"
#include "Errors.h"
#include "Trainers.h"
#include <iostream>
using namespace std;

void  Menu::Show_Menu_Gym()
{
	char input;
	string password;
	do
	{
		cout << "Enter a password: ";
		cin >> password;
	} while (password != "admin");

	do 
	{
		mainMenu();

		cin >> input;

		Safe_Selection(input);

		cout << endl;


	} while (input != '0');
}

void Menu::mainMenu()
{
	cout << "Hello! This is your favorite gym \"Perfect Body\" \n";
	cout << "Choose an operation: \n";
	cout << "1 - To register a visitor;\n";
	cout << "2 - To view registered visitors;\n";
	cout << "3 - To open delete menu for visitors;\n";
	cout << "4 - To delete visitor by index;\n";
	cout << "5 - To view trainers;\n";
	cout << "6 - To delete a trainer by index;\n";
	cout << "7 - To add a trainer;\n";
	cout << "M - To view the most experience trainer;\n";
	cout << "0 - To exit.\n";
}


void Menu::Menu_Visitor_Add()
{
	Visitors temp;

	cin >> temp;

	operation.add_Visitor(temp);

	cout << endl;
	cout << "Visitor added!\n";
}

void Menu::Menu_Trainer_Add()
{
	Trainers temp;

	cin >> temp;

	operation.add_Trainer(temp);

	cout << endl;
	cout << "Trainer added!\n";
}

void Menu::Menu_Visitor_Delete_BY_INDEX()
{
	cout << "Please enter an index of visitor you would like to delete:\n";
	int delete_indx;

	try
	{
		cin >> delete_indx;
	}
	catch (Errors& error)
	{
		cout << "Ups... we found an error! " << error.ShowErrors() << endl;
	}
	catch (...)
	{
		cout << "Some errors were found! " << endl;
	}

	operation.delete_Visitor(delete_indx);

	cout << endl;
	cout << "Visitor deleted!\n";
}

void Menu::Menu_Trainer_Delete_BY_INDEX()
{
	cout << "Please enter an index of trainer you would like to delete:\n";
	int delete_indx_2;

	try
	{
		cin >> delete_indx_2;
	}
	catch (Errors& error)
	{
		cout << "Ups... we found an error! " << error.ShowErrors() << endl;
	}
	catch (...)
	{
		cout << "Some errors were found! " << endl;
	}

	operation.delete_Trainer(delete_indx_2);

	cout << endl;
	cout << "Trainer deleted!\n";
}

void Menu::Menu_Visitor_Delete()
{
	char input_delete_char;

	cout << "Please enter F to delete FIRST visitor you entered:\n";
	cout << "Please enter L to delete LAST visitor you entered:\n";
	cout << "Please enter A to delete ALL visitor you entered:\n";

	cin >> input_delete_char;
	Delete_Selection(input_delete_char);

	cout << "Visitor deleted!\n";
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

void Menu::Selection(char input)
{
	switch (input)
	{
	case '1':
		Menu_Visitor_Add();
		break;
	case '2':
		operation.show_Visitors();
		cout << endl;
		break;
	case '3':
		Menu_Visitor_Delete();
		break;
	case '4':
		Menu_Visitor_Delete_BY_INDEX();
		break;
	case '5':
		operation.show_Trainers();
		break;
	case '6':
		Menu_Trainer_Delete_BY_INDEX();
		break;
	case '7':
		Menu_Trainer_Add();
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

void Menu::Delete_Selection(char input_delete_char_tmp)
{

	switch (input_delete_char_tmp)
	{
	case 'F':
		operation.delete_first_entered_Visitor();
		break;
	case 'L':
		operation.delete_last_entered_Visitor();
		break;
	case 'A':
		operation.delete_all_entered_Visitors();
		break;
	default:
		cout << "Error! You chose wrong operation!\n";
		break;
	}
}