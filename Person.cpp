#include "Person.h"

std::vector<std::vector<char>> Person::locs = { { -1,-1 },{ 0,-1 },{ 1,-1 },
												{ -1,0 },			{ 1,0 },
												{ -1,1 },{ 0,1 },{ 1,1 }, 
												{ 0,0 } };
TeamHandler Person::teams = TeamHandler();

Person::Person()
{
}
Person::~Person()
{
}

void	Person::move(bool * env)
{
	unsigned char counter = 0;
	for (int i = 0; i < 8; i++) {
		if (env[i]) { counter++; }
	}
	counter = rand() % (counter + 1) + 1;
	for (int i = 0; i < 8; i++) {
		if (env[i]) { counter--; }
		if (counter == 0) { counter = i; break; }
		if (i == 7) { counter = 8; }
	}
	updateLocation(0);
	pos[0] += locs[counter][0];
	pos[1] += locs[counter][1];
	pos[0] = (pos[0] + teams.getWidth()) % teams.getWidth();
	pos[1] = (pos[1] + teams.getHeight()) % teams.getHeight();
	updateLocation(strength);
}
void	Person::smartMove()
{
	age++;
	if (getIsDead()) { return; }
	bool b[8];
	for (int i = 0; i < 8; i++) {
		b[i] = !teams.getElement(pos[0] + locs[i][0], pos[1] + locs[i][1], team);
	}
	move(b);
}

void	Person::setPosition(int x, int y)
{
	if (!teams.getElement(x, y)) {
		updateLocation(0);
		pos[0] = x;
		pos[1] = y;
		updateLocation(strength);
	} else {
		//std::cout << "Placement conflict." << std::endl;
	}
}
void	Person::setTeam(int t)
{
	team = t;
	teams.addSize(t);
	teams.addStrength(strength, t);
}
void	Person::setStrength(double s)
{
	teams.removeStrength(strength, team);
	strength = s;
	teams.addStrength(strength, team);
}

void	Person::getPosition(int & x, int & y)
{
	x = pos[0];
	y = pos[1];
}
int		Person::getTeam()
{
	return team;
}
double	Person::getStrength()
{
	return strength;
}
double	Person::getAge()
{
	return age;
}
bool	Person::getIsHealthy()
{
	return is_healthy;
}
bool	Person::getIsDead()
{
	if (is_dead) { return is_dead; }
	updateLocation(0);
	if (teams.getStrength(pos[0], pos[1]) >= strength || age > strength) {
		updateLocation(0);
		teams.removeStrength(strength, team);
		teams.removeSize(team);
		is_dead = true;
	} else {
		updateLocation(strength);
	}
	return is_dead;
}

void	Person::updateLocation(double set)
{
	teams.setElement(pos[0], pos[1], team, set);
}
