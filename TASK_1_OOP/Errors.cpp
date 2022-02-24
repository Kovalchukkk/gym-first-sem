#include "Errors.h"
#include <string>
using namespace std;

Errors::Errors(ErrorsName error)
{
	this->error = error;
}

string Errors::ShowErrors()
{
	switch (error)
	{
	case Neg_year:
		return "Error! YOU ENTERED NEGATIVE YEAR!";
	case Max_size:
		return "Error! MAX SIZE IS REACHED!";
	case INDEX_OUT_OF_RANGE:
		return "Error! INDEX IS UNDEFINED!";
	case Neg_price:
		return "Error! PRICE IS NEGATIVE!";
	default:
		return "";
	}
}