#include "stdafx.h"
#include "funkcje.h"
#include "klasy.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void show(Board space) {
	Position x, y;
	x = (rand() % 49) + 1;
	y = (rand() % 49) + 1;
}
void createSpace(Board *s, Astronaut *AsName) {
	srand(time(NULL));
	Position x, y;
	for (int j = 0; j < 50; j++) {
		for (int i = 0; i < 50; i++) {
			s->space[i][j] = 0;
		}
	}
	s->space[AsName->x][AsName->y] = 1;
}
void showAfter(Board s) {
	for (int j = 0; j < 50; j++) {
		for (int i = 0; i < 50; i++) {
			switch (s.space[i][j]) {
			case 0:
				cout << " ";
				break;
			case 1:
				cout << "Gracz";
				break;
			case 2:
				cout << "Planeta 1";
				break;
			case 3:
				cout << "Planeta 2";
				break;
			case 4:
				cout << "Planeta 3";
				break;
			case 5:
				cout << "tarcza";
				break;
			case 6:
				cout << "Meteoryt";
				break;
			case 7:
				cout << "Meteoryt";
				break;
			case 8:
				cout << "Meteoryt";
				break;
			case 9:
				cout << "Meteoryt";
				break;
			case 10:
				cout << "Meteoryt";
				break;
			case 11:
				cout << "Meteoryt";
				break;
			case 12:
				cout << "Meteoryt";
				break;
			case 13:
				cout << "Meteoryt";
				break;
			case 14:
				cout << "Meteoryt";
				break;
			case 15:
				cout << "Meteoryt";
				break;
			default:
				cout << "error";
				break;
			}
		}
		cout << "|" << endl;
	}
	cout << "****************";
}
void showStats(Astronaut AsName){
	cout << endl << "Poziom= " << AsName.level << " Punkty: " << AsName.points;
	cout << endl << endl << "Menu:[h] - help, [z] - zamknij gre, sterowanie: W,A,S,D";
	}
void destroy(Board *space, Astronaut *AsName, Planet *PlanetName){

	}
void protect(Board *space, Astronaut *AsName) {}
void controlKeys(char key, Astronaut *AsName, Board *space){
	if (key == 'a') {
		if (space->space[AsName->x - 1][AsName->y] == 0) {
			space->space[AsName->x - 1][AsName->y] = 1;
			space->space[AsName->x][AsName->y] = 0
				AsName->x--;
		}
		else {


		}
}
	if (key == 'w') {
		if (space->space[AsName->x][AsName->y - 1] == 0) {
			space->space[AsName->x][AsName->y - 1] = 1;
			space->space[AsName->x][AsName->y] = 0
				AsName->y--;
		}
		else {}
	}
		if (key == 'd') {
			if (space->space[AsName->x + 1][AsName->y] == 0) {
				space->space[AsName->x + 1][AsName->y] = 1;
				space->space[AsName->x][AsName->y] = 0
					AsName->x++;
			}
			else {}
		}
		if (key == 's') {
			if (space->space[AsName->x][AsName->y + 1] == 0) {
				space->space[AsName->x][AsName->y + 1] = 1;
				space->space[AsName->x][AsName->y] = 0
					AsName->y++;
			}
			else {}
		}
		if (key == 'h') {
			system("CLS");
			cout << endl;
			cout << "Legenda:";
			cout << endl;
			cout << "Aby wrocic nacisnij klawisz";
			_getch();
		}


