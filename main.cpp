#include <SFML/Graphics.hpp>

#include "Person.h"
#include "World.h"
#include "VisualTeams.h"
#include "World.h"

int main()
{
	int display_x = 2000;
	int display_y = 2000;

	int environment_x = 400;
	int environment_y = 400;

	int initial_population_size = 500;
	int number_of_teams = 6;

	bool do_trippy_view = true;

	sf::RenderWindow window(sf::VideoMode(display_x, display_y), "SFML works!");
	VisualTeams vt = VisualTeams(&window, do_trippy_view);
	World w = World(&vt, environment_x, environment_y, initial_population_size, number_of_teams);
	vt.updateSize();

	std::clock_t start;

	while (true) {
		//start = clock();
		w.step();
		//std::cout << 1000 / (clock() - start) << std::endl;
	}

	system("pause");
	return 0;
}
