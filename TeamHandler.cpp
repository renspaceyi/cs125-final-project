#include "TeamHandler.h"



TeamHandler::TeamHandler()
{
	//resize(1000, 1000, 3);
}
TeamHandler::~TeamHandler()
{
}

void TeamHandler::resize(int w, int h, int t)
{
	std::vector<double> height;
	height.resize(h, 0);
	std::vector<std::vector<double>> width;
	width.resize(w, height);
	teams.resize(t, width);

	strength.resize(t, 0);
	team_size.resize(t, 0);
}

int TeamHandler::getWidth()
{
	return teams[0].size();
}
int TeamHandler::getHeight()
{
	return teams[0][0].size();
}
int TeamHandler::getTeams()
{
	return teams.size();
}

void TeamHandler::resetElement(int w, int h)
{
	for (int i = 0; i < teams.size(); i++) {
		teams[i][w][h] = false;
	}
}
void TeamHandler::setElement(int w, int h, int t, double b)
{
	teams[t][w][h] = b;
}
bool TeamHandler::getElement(int w, int h, int t)
{
	w = (w + getWidth()) % getWidth();
	h = (h + getHeight()) % getHeight();
	return teams[t][w][h] != 0;
}
bool TeamHandler::getElement(int w, int h)
{
	bool ret = false;
	w = (w + getWidth()) % getWidth();
	h = (h + getHeight()) % getHeight();
	for (int i = 0; i < teams.size() && !ret; i++) {
		ret = ret || (teams[i][w][h] != 0);
	}
	return ret;
}

void TeamHandler::setStrength(int w, int h, int t, double s)
{
	teams[t][w][h] = s;
}
double TeamHandler::getStrength(int w, int h, int t)
{
	return teams[t][w][h];
}
double TeamHandler::getStrength(int w, int h)
{
	double ret = 0;
	for (int i = 0; i < teams.size(); i++) {
		if (teams[i][w][h] > ret) {
			ret = teams[i][w][h];
		}
	}
	return ret;
}

void TeamHandler::addSize(int t)
{
	team_size[t]++;
}
void TeamHandler::removeSize(int t)
{
	team_size[t]--;
}
int TeamHandler::getSize(int t)
{
	return team_size[t];
}

void TeamHandler::addStrength(double s, int t)
{
	strength[t] += s;
}
void TeamHandler::removeStrength(double s, int t)
{
	strength[t] -= s;
}
double TeamHandler::getAverageStrength(int t)
{
        if (team_size[t] <= 0) {
                return 0.0;
        }
	return strength[t] / team_size[t];
}

