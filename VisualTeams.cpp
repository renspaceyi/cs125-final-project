#include "VisualTeams.h"



VisualTeams::VisualTeams(sf::RenderWindow * w, bool do_trippy_view)
{
	window = w;
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}
	text.setFont(font);
	this->do_trippy_view = do_trippy_view;
}
VisualTeams::~VisualTeams()
{
}

void VisualTeams::draw()
{
	if (!do_trippy_view) { updateSize(); }

	std::string stats = "";
	for (int i = 0; i < Person::teams.getTeams(); i++) {
		stats += "\nTeam " + std::to_string(i+1) + ": " + std::to_string(Person::teams.getAverageStrength(i));
	}
	text.setString(stats);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Black);

	for (int i = 0; i < Person::teams.getWidth(); i++) {
		for (int j = 0; j < Person::teams.getHeight(); j++) {
			for (int k = 0; k < Person::teams.getTeams(); k++) {
				if (Person::teams.getElement(i, j, k)) {
					im.setPixel(i, j, team_colors[k]);
					break;
				}
			}
		}
	}

	tex.loadFromImage(im);
	spr.setTexture(tex);
	spr.setScale(window->getSize().x / Person::teams.getWidth(), window->getSize().y / Person::teams.getHeight());

	window->clear();
	window->draw(spr);
	window->draw(text);
	window->display();
}

void VisualTeams::updateSize()
{
	im.create(Person::teams.getWidth(), Person::teams.getHeight(), sf::Color::Green);
}
