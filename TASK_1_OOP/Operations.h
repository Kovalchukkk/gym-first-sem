#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "Visitors.h"
#include "Trainers.h"
#include "Repository.h"
#include "VisitorRepository.h"
#include "TrainerRepository.h"
#include <vector>
#include <sstream>

using namespace std;

class Operations
{
private:
	VisitorRepository repos_visitor;
	TrainerRepository repos_trainer;

public:
	void add_Visitor(Visitors& other);
	void add_Trainer(Trainers& trainer);

	void delete_Visitor(int index);
	void delete_Trainer(int ind);
	void show_Visitors();
	void show_Trainers();
	void delete_all_entered_Visitors();
	void delete_first_entered_Visitor();
	void delete_last_entered_Visitor();
	void the_most_experienced_trainer();
};

#endif
