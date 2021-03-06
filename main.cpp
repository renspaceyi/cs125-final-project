#include <SFML/Graphics.hpp>

#include "Person.h"
#include "World.h"
#include "VisualTeams.h"
#include "World.h"

int main(int argc, char* argv[])
{
	int display_x = 900;
	int display_y = 900;

	int environment_x = 300;
	int environment_y = 300;
        
        int sleep = 30;
        if (argc == 4) {
                environment_x = atoi(argv[1]);
                environment_y = atoi(argv[2]);
                sleep = atoi(argv[3]);
        }
        if (argc == 3) {
                environment_x = atoi(argv[1]);
                environment_y = atoi(argv[2]);
        }

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
                if (sleep != 0)
                        sf::sleep(sf::seconds((double) 1.0/sleep)); //60 fps
		//std::cout << 1000 / (clock() - start) << std::endl;
	}

	//system("pause");
	return 0;
}
