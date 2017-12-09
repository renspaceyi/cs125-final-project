#pragma once
#include "Person.h"
#include <SFML/Graphics.hpp>

class VisualTeams
{
public:
	VisualTeams(sf::RenderWindow * w, bool do_trippy_view);
	~VisualTeams();

	void draw();
	void updateSize();
	std::vector<sf::Color> team_colors = { sf::Color::Red, sf::Color(255,165, 0), sf::Color::Yellow, sf::Color::Green, sf::Color::Blue, sf::Color(75,0,130) };

private:
	bool do_trippy_view = false;

	sf::RenderWindow * window;

	sf::Image im;
	sf::Texture tex;
	sf::Sprite spr;
	sf::Text text;
	sf::Font font;
};

