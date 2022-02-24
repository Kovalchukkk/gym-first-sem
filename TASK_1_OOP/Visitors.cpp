#include "Visitors.h"
#include "Errors.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;


Visitors::Visitors(string Name, string Ticket, int Time, int Abonement_price)
{
	this->name = Name;
	this->ticket = Ticket;
	if (Time < 0)
		throw Errors(ErrorsName::Neg_year);
	this->time = Time;
	this->abonement_price = Abonement_price;
}

string Visitors::TotalPrice(string ticket)
{
	if (this->ticket == "cheap")
		return "Total price: " + to_string(300 * time);
	else if (this->ticket == "average")
		return "Total price: " + to_string(800 * time);
	else if (this->ticket == "premium")
		return "Total price: " + to_string(1500 * time);
	else
		return "Total price: Error";
}

Visitors& Visitors::operator+(Visitors& other)
{
	this->abonement_price = this->abonement_price * this->time + other.abonement_price * other.time;
	if (this->abonement_price < 0)
		throw Errors(ErrorsName::Neg_price);
	return *this;
}

Visitors& Visitors::operator-(Visitors& other)
{
	this->abonement_price = this->abonement_price * this->time - other.abonement_price * other.time;
	if (this->abonement_price < 0)
		throw Errors(ErrorsName::Neg_price);
	return *this;
}

Visitors& Visitors::operator=(const Visitors& other)
{
	this->name = other.name;
	this->ticket = other.ticket;
	this->time = other.time;

	return *this;
}

ostream& Visitors::operator<<(ostream& out)
{
	return out << "Visitours name: " << name << "; Ticket: " << ticket << "; Time: " << time << " year/years" << "; " << TotalPrice(ticket) + "\n";
}


string Visitors::GetUserInfo()
{
	return "Visitours name: " + name + ";" + " Ticket: " + ticket + ";" + " Time: " + to_string(time) + " year/years" + ";" + " " + Visitors::TotalPrice(ticket) + "\n";

}

string Visitors::GetAbonementPriceFamily()
{
	return this->name + "  Family abonement price :  " + to_string(this->abonement_price) + "\n";
}

ostream& operator<<(ostream& out, Visitors& other)
{
	return other << cout;
}

istream& operator>>(istream& in, Visitors& other)
{
	string Name;
	string Ticket;
	int Time;

	cout << "Name: ";
	in >> Name;
	cout << "Ticket: ";
	in >> Ticket;
	cout << "Time: ";
	in >> Time;

	other = Visitors(Name, Ticket, Time);

	return in;
}

ofstream& operator<<(ofstream& fout, Visitors& other)
{
	fout << other.name << "," << other.ticket << "," << other.time;
	return fout;
}

ifstream& operator>>(ifstream& fin, Visitors& other)
{
	int max = 100;
	char* buff = new char[max + 1];

	fin.get(buff, max, ',');
	other.name = buff;
	fin.get();

	fin.get(buff, max, ',');
	other.ticket = buff;
	fin.get();

	fin.getline(buff, max);
	other.time = atoi(buff);

	delete[] buff;
	return fin;
}
