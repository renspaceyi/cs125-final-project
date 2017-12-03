#pragma once
#include "Person.h"
#include <SFML/Graphics.hpp>

class VisualTeams
{
public:
	VisualTeams(sf::RenderWindow * w);
	~VisualTeams();

	void draw();

private:
	std::vector<sf::Color> team_colors = { sf::Color::Red, sf::Color::Blue, sf::Color::Yellow, sf::Color::Black, sf::Color::Cyan, sf::Color::White };
	sf::RenderWindow * window;

	sf::Image im;
	sf::Texture tex;
	sf::Sprite spr;
};

