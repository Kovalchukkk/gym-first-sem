#include "Operations.h"
#include "Errors.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void Operations::add_Visitor(Visitors& other)
{
	repos_visitor.add(other);
}

void Operations::add_Trainer(Trainers& trainer)
{
	repos_trainer.add(trainer);
}

void Operations::delete_Trainer(int ind)
{
	repos_trainer.del(ind);
}

void Operations::delete_Visitor(int index)
{
	repos_visitor.del(index);
}

void Operations::delete_all_entered_Visitors()
{
	repos_visitor.del_all();
}

void Operations::delete_first_entered_Visitor()
{
	repos_visitor.del_first();
}

void Operations::delete_last_entered_Visitor()
{
	repos_visitor.del_last();
}

void Operations::the_most_experienced_trainer()
{
	repos_trainer.max_trainer();
}

void Operations::show_Visitors()
{
	cout << endl;
	repos_visitor.show();
}

void Operations::show_Trainers()
{
	cout << endl;
	repos_trainer.show();
}





