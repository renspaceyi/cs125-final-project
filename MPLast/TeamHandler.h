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

	void addSize(int t);
	void removeSize(int t);
	int getSize(int t);

	void addStrength(double s, int t);
	void removeStrength(double s, int t);
	double getAverageStrength(int t);
private:

	std::vector<std::vector<std::vector<double>>> teams;
	std::vector<double> strength;
	std::vector<int> team_size;
};

