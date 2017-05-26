#pragma once
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Position {
	int x, y;
};
class Object {
public:
	Position x, y;
};
class Astronaut:public Object  {
public:
	string AsName;
	int points;
	int level;
	int score;

	void getPoints() {

	}
	Astronaut();
	~Astronaut();
};

class Meteorite: public Object {
public:
	
	int m_strength;
	Meteorite(int id);
	~Meteorite();


};

class Planet: public Object {
public:
	int p_strength;
	string PlanetName;
	int p_id;
	Planet();
	~Planet();

};
class Shield : public Object {
public:
	Shield();
	~Shield();
};
class Board {
public:
	int space[50][50];
	Board();
	~Board();
};
