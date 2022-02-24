#ifndef VISITORS_H
#define VISITORS_H

#include <string>
#include <fstream>
using namespace std;

class Visitors 
{ 
private:
	string name;
	string ticket;
	int time;
	int abonement_price;

public:
	Visitors(string Name = "", string Ticket = "", int Time = 0, int Abonement_price = 0);
	string GetUserInfo(); 
	string GetAbonementPriceFamily();
	string TotalPrice(string ticket);
	Visitors &operator + (Visitors& other);
	Visitors &operator - (Visitors& other);
	Visitors &operator = (const Visitors& other);
	ostream& operator<<(ostream& out); // запис об'єкта у вектор
	friend ostream& operator<<(ostream& out, Visitors& other);
	friend istream& operator>>(istream& in, Visitors& other);
	friend ofstream& operator << (ofstream& fout, Visitors& other); // запис даних у файл
	friend ifstream& operator >> (ifstream& fin, Visitors& other); // читання даних з файлу
};

#endif
