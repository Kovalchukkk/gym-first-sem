#pragma once
#include "Errors.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class Repository
{
protected:
	
	int maxSize = 200;
	vector<T> data;
	virtual string GetFileName() { return ""; }
	bool sync = true;

	void SyncWrite()
	{
		if (sync)
			WriteToFile();
	}

	void SyncRead()
	{
		if (sync)
		{
			data.clear(); // очищуємо вектор
			ReadFromFile();
		}
	}

public:
	
	~Repository()
	{
		cout << "Destructor Repository is called!" << endl;
	}

	void add(T& item)
	{
		if (data.size() >= maxSize)
			throw Errors(ErrorsName::Max_size);
		data.push_back(item);
		SyncWrite();
	}

	void del(int index)
	{
		if (data.size() < index || index < 0)
			throw Errors(ErrorsName::INDEX_OUT_OF_RANGE);
		data.erase(data.begin() + index);
		SyncWrite();
	}

	void del_all()
	{
		data.clear();
		SyncWrite();
	}

	void del_first()
	{
		data.erase(data.begin());
		SyncWrite();
	}

	void del_last()
	{
		data.pop_back();
		SyncWrite();
	}

	void show()
	{
		SyncRead();
		for (int i = 0; i < data.size(); i++)
		{
			cout << data[i];
		}
		cout << endl;
	}
	

	void WriteToFile()
	{
		ofstream fout(GetFileName());
		for (int i = 0; i < data.size(); i++)
		{
			fout << data[i];

			if (i + 1 != data.size())
				fout << endl;
		}
		fout.close();
	}


	void ReadFromFile()
	{
		bool prevSync = sync;
		sync = false;

		ifstream fin(GetFileName());
		while (!fin.eof())
		{
			T item;
			fin >> item;
			add(item);
		}
		fin.close();

		sync = prevSync;
	}
};

