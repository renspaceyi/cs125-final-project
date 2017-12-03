#pragma once
#include "Person.h"
#include "VisualTeams.h"
#include <thread>

class World
{
public:
	World(VisualTeams * v, int w, int h, int pop_size, int number_of_teams);
	~World();

	void step();

private:
	void moveTeam(int t);

	std::vector<Person> population;
	VisualTeams * vt;

	int width = 0;
	int height = 0;

	void move();
	void reproduce(int i);
};

