#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "TeamHandler.h"

class Person
{
public:
	static	TeamHandler teams;
	static	std::vector<std::vector<char>> locs;

	Person();
	~Person();

	void	move(bool * env);
	void	smartMove();
	void	setPosition(int x, int y);
	void	setTeam(int t);
	void	setStrength(double s);

	void	getPosition(int & x, int & y);
	int		getTeam();
	double	getStrength();
	double	getAge();
	bool	getIsHealthy();
	bool	getIsDead();

private:

	int		pos[2] = { 0,0 };
	int		team;
	double	strength = 1;
	double	age = 0;

	bool	is_healthy = true;
	bool	is_dead = false;

	void	updateLocation(double set);
};
