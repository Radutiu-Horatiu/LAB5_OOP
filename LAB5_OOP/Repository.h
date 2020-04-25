#pragma once
#include "Controller.h"
#include "Film.h"
#include <vector>

using namespace std;

class Repository
{
private:
	vector <Film> films;

public:

	vector <Film> get_films() { return films; }

	Repository();
	~Repository();

};

