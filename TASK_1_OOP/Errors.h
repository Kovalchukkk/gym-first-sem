#ifndef ERRORS_H
#define ERRORS_H

#include <string>
using namespace std;

enum ErrorsName
{
	Neg_year,
	Max_size,
	INDEX_OUT_OF_RANGE,
	Neg_price

};


class Errors
{
private:
	ErrorsName error;
public:
	Errors(ErrorsName error);
	string ShowErrors();
};

#endif

