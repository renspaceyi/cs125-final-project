#include "World.h"



World::World(VisualTeams * v, int w, int h, int pop_size, int number_of_teams)
{
	Person::teams.resize(w, h, number_of_teams);

	srand(time(NULL));

	width = Person::teams.getWidth();
	height = Person::teams.getHeight();

	vt = v;
	for (int i = 0; i < pop_size; i++) {
		population.push_back(Person());
		population[i].setTeam(i % number_of_teams);
		population[i].setStrength(rand()%1000000);
		population[i].setPosition(rand() % width, rand() % height);
	}
}
World::~World()
{
}

void World::step()
{
	//std::clock_t start = std::clock();
	move();
	//std::cout << std::clock() - start << std::endl;
	//start = std::clock();

	for (int i = 0; i < population.size(); i++) {
		reproduce(i);
	}
	//std::cout << std::clock() - start << std::endl;
	//start = std::clock();
	vt->draw();
	//std::cout << std::clock() - start << std::endl;
	//std::cout << "----" << std::endl;
}

void World::moveTeam(int t)
{
	for (int i = 0; i < population.size(); i++) {
		if (population[i].getTeam() == t) {
			population[i].smartMove();
		}
	}
}

void World::move()
{
	for (int i = 0; i < population.size(); i++) {
		population[i].smartMove();
	}

	for (int i = 0; i < population.size(); i++) {
		if (population[i].getIsDead()) {
			population[i] = population[population.size() - 1];
			population.pop_back();
			i--;
		}
	}

}
void World::reproduce(int ind)
{
	
	if (rand() % 20 > 0) { return; }

	int x;
	int y;
	population[ind].getPosition(x, y);

	bool b[8];
	char counter = 0;
	for (int i = 0; i < 8; i++) {
		b[i] = !Person::teams.getElement(x + Person::locs[i][0], y + Person::locs[i][1]);
		counter += b[i];
	}
	if (counter == 0) { return; }
	counter = rand() % counter + 1;
	for (int i = 0; i < 8; i++) {
		if (b[i]) { counter--; }
		if (counter == 0) { counter = i; break; }
	}
	
	population.push_back(Person());

	int pos[2];

	pos[0] = x + Person::locs[counter][0];
	pos[1] = y + Person::locs[counter][1];
	pos[0] = (pos[0] + Person::teams.getWidth()) % Person::teams.getWidth();
	pos[1] = (pos[1] + Person::teams.getHeight()) % Person::teams.getHeight();

	population[population.size() - 1].setTeam(population[ind].getTeam());
	population[population.size() - 1].setStrength(Person::teams.getStrength(x, y) + rand() % 20 - rand() % 40);
	population[population.size() - 1].setPosition(pos[0], pos[1]);
}
