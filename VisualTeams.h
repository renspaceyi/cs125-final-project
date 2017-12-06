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

private:
	bool do_trippy_view = false;

	std::vector<sf::Color> team_colors = { sf::Color::Red, sf::Color::Blue, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan, sf::Color::White };
	sf::RenderWindow * window;

	sf::Image im;
	sf::Texture tex;
	sf::Sprite spr;
	sf::Text text;
	sf::Font font;
};

