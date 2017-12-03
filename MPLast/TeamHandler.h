#pragma once
#include <vector>

class TeamHandler
{
public:
	TeamHandler();
	~TeamHandler();

	void resize(int w, int h, int t);

	int getWidth();
	int getHeight();
	int getTeams();

	void resetElement(int w, int h);
	void setElement(int w, int h, int t, double b);
	bool getElement(int w, int h, int t);
	bool getElement(int w, int h);

	void setStrength(int w, int h, int t, double s);
	double getStrength(int w, int h, int t);
	double getStrength(int w, int h);
private:

	std::vector<std::vector<std::vector<double>>> teams;
};

