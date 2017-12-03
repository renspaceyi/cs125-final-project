#include <SFML/Graphics.hpp>

#include "Person.h"
#include "World.h"
#include "VisualTeams.h"
#include "World.h"

int main()
{
	int display_x = 2000;
	int display_y = 2000;

	int environment_x = 500;
	int environment_y = 500;

	int initial_population_size = 500;
	int number_of_teams = 6;

	sf::RenderWindow window(sf::VideoMode(display_x, display_y), "SFML works!");
	VisualTeams vt = VisualTeams(&window);
	World w = World(&vt, environment_x, environment_y, initial_population_size, number_of_teams);

	while (true) {
		w.step();
	}

	system("pause");
	return 0;
}