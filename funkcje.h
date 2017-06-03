#pragma once
#include "klasy.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void show(Board space);
void createSpace(Board *space, Astronaut *AsName);
void showAfter(Board space);
void destroy(Board *space, Astronaut *AsName, Planet *PlanetName);
void protect(Board *space, Astronaut *AsName);
void showStats(Astronaut *AsName);
void controlKeys(char key, Astronaut *AsName, Board *space);