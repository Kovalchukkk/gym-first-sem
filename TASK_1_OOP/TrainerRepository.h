#pragma once

#include <iostream>
#include "Trainers.h"
#include "Repository.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class TrainerRepository : public Repository <Trainers>
{

protected:

	string GetFileName() override
	{
		return "D:\\Навчальна практика 2 курс\\gym-first-sem\\TASK_1_OOP\\Debug\\trainers.txt";
	}

public:

	TrainerRepository()
	{
		ReadFromFile();
	}

	~TrainerRepository()
	{
		WriteToFile();
	}

	void max_trainer()
	{
		int temp_exp = 0;
		int index = 0;
		int max = data[0].experience;

		for (int i = 0; i < data.size(); i++)
		{
			if (data[i].experience > max)
			{
				max = data[i].experience;
				index = i;
			}
		}

		cout << "The most experienced trainer is " << data[index].name_trainer << endl;
	}

};