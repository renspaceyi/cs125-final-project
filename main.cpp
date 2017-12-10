#include <SFML/Graphics.hpp>

#include "Person.h"
#include "World.h"
#include "VisualTeams.h"
#include "World.h"

int main()
{
	int display_x = 1200;
	int display_y = 900;

	int environment_x = 400;
	int environment_y = 300;

	int initial_population_size = 500;
	int number_of_teams = 6;

	bool do_trippy_view = false;

	sf::RenderWindow window(sf::VideoMode(display_x, display_y), "World Simulator", sf::Style::Titlebar | sf::Style::Close);
	VisualTeams vt = VisualTeams(&window, do_trippy_view);
	World w = World(&vt, environment_x, environment_y, initial_population_size, number_of_teams);
	vt.updateSize();

	std::clock_t start;

	while (window.isOpen()) {
		//start = clock();
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
		w.step();
                sf::sleep(sf::seconds(0.017)); //60 fps
		//std::cout << 1000 / (clock() - start) << std::endl;
	}

	//system("pause");
	return 0;
}
