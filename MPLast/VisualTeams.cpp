#include "VisualTeams.h"



VisualTeams::VisualTeams(sf::RenderWindow * w)
{
	window = w;
}
VisualTeams::~VisualTeams()
{
}

void VisualTeams::draw()
{
	im.create(Person::teams.getWidth(), Person::teams.getHeight(), sf::Color::Green);

	for (int i = 0; i < Person::teams.getWidth(); i++) {
		for (int j = 0; j < Person::teams.getHeight(); j++) {
			for (int k = 0; k < Person::teams.getTeams(); k++) {
				if (Person::teams.getElement(i, j, k)) { im.setPixel(i, j, team_colors[k]); }
			}
		}
	}

	tex.loadFromImage(im);
	spr.setTexture(tex);
	spr.setScale(window->getSize().x / Person::teams.getWidth(), window->getSize().y / Person::teams.getHeight());

	window->clear();
	window->draw(spr);
	window->display();
}
