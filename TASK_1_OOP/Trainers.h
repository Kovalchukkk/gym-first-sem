#ifndef TRAINERS_H
#define TRAINERS_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Trainers
{
public:
	string name_trainer;
	int experience;

	Trainers(string NAME_TRAINER = "", int experience = 0);
	string Trainers_Info();
	ostream& operator<<(ostream& out); // ����� ��'���� � ������
	friend ostream& operator<<(ostream& out, Trainers& other);
	friend istream& operator>>(istream& in, Trainers& other);
	friend ofstream& operator << (ofstream& fout, Trainers& other); // ����� ����� � ����
	friend ifstream& operator >> (ifstream& fin, Trainers& other); // ������� ����� � �����
};
#endif
