#pragma once

#include <iostream>
#include "Visitors.h"
#include "Repository.h"
#include <string>
#include <fstream>
using namespace std;

class VisitorRepository : public Repository <Visitors>
{
private:
	
	string GetFileName() override
	{
		return "D:\\��������� �������� 2 ����\\gym-first-sem\\TASK_1_OOP\\Debug\\visitors.txt";
	}

public:
	VisitorRepository()
	{
		ReadFromFile();
	}

	~VisitorRepository()
	{
		WriteToFile();
	}
};
