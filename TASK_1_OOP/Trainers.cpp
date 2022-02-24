#include "Trainers.h"
#include "Errors.h"
#include <iostream>
#include <fstream>
using namespace std;

Trainers::Trainers(string NAME_TRAINER, int experience)
{
	this->name_trainer = NAME_TRAINER;
	this->experience = experience;
	if (experience < 0)
		throw Errors(ErrorsName::Neg_year);
}

string Trainers::Trainers_Info()
{
	return "Trainers name: " + name_trainer + " Experience: " + to_string(experience) + " year/years\n";
}


ostream& Trainers::operator<<(ostream& out)
{
	return out << "Trainers name: " << name_trainer << " Experience " << experience << " year/years\n";
}


ostream& operator<<(ostream& out, Trainers& other)
{
	return other << cout;
}

istream& operator>>(istream& in, Trainers& other)
{
	string name_trainer;
	int experience_trainer;

	cout << "Name: ";
	in >> name_trainer;
	cout << "Experience: ";
	in >> experience_trainer;

	other = Trainers(name_trainer, experience_trainer);

	return in;
}

ofstream& operator<<(ofstream& fout, Trainers& other)
{
	fout << other.name_trainer << "," << other.experience;
	return fout;
}

ifstream& operator>>(ifstream& fin, Trainers& other)
{
	int max = 100;
	char* buff = new char[max + 1];

	fin.get(buff, max, ',');
	other.name_trainer = buff;
	fin.get();

	fin.getline(buff, max);
	other.experience = atoi(buff);

	delete[] buff;
	return fin;
}
