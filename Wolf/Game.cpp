#include "Game.h"
#include "Character.h"

#define CLEAR system("clr")

using namespace std;

#include <iostream>

void tellNumPlayers(){
	cout << "How many players do you want? ";
	cin >> numplayers;
	CLEAR;
}

void countRoles() {
	for (int i = 0; i < numplayers; i++)
	{
		if (player[i].rol == VILLAGER) {
			counters[villagercounter] += 1;
		}
		else if (player[i].rol == WOLF) {
			counters[wolfcounter] += 1;
		}
		else if (player[i].rol == DEVINER) {
			counters[devinercounter] += 1;
		}
		else if (player[i].rol == GIRL) {
			counters[girlcounter] += 1;
		}
		else if (player[i].rol == HUNTER) {
			counters[huntercounter] += 1;
		}
	}
}

void resetCounters() { //AL TANTO QUE ESTO LO USARAS ALGUN DIA
	for (int i = 0; i < MAX_COUNTERS; i++)
	{
		counters[i] = 0;
	}
}

ROL putarol(){
	countRoles();
	switch (getRandome(3))
	{

	case 1://WOLF
		if (counters[wolfcounter] <= (numplayers / 3)) {
			return WOLF;
		}
		else if (counters[devinercounter] != 1) {
			return DEVINER;
		}
		else if (counters[girlcounter] != 1) {
			return GIRL;
		}
		else if (counters[huntercounter] != 1) {
			return HUNTER;
		}
		else {
			return VILLAGER;
		}
		break;

	case 2://SPECIAL
		if (counters[devinercounter] != 1) {
			return DEVINER;
		}
		else if (counters[girlcounter] != 1) {
			return GIRL;
		}
		else if (counters[huntercounter] != 1) {
			return HUNTER;
		}
		else if (counters[wolfcounter] <= (numplayers / 3)) {
			return WOLF;
		}
		else {
			return VILLAGER;
		}
		break;

	case 3://VILLAGER
		if (counters[villagercounter] <= ((numplayers / 4) * 3)) {
			return VILLAGER;
		}else if (counters[wolfcounter] <= (numplayers / 3)) {
			return WOLF;
		}
		else if (counters[devinercounter] != 1) {
			return DEVINER;
		}
		else if (counters[girlcounter] != 1) {
			return GIRL;
		}
		else if (counters[huntercounter] != 1) {
			return HUNTER;
		}
		else {
			return VILLAGER;
		}
		break;
	default:
		break;
	}
}

void assignRoles() {
	for (int i = 0; i < numplayers; i++)
	{
		player[i].name = "Player 1";//areglar
		player[i].alive = true;
		player[i].numplayer = 1;
		player[i].rol = putarol();
	}
}


void play() {
	srand(time(NULL));

	tellNumPlayers();
	assignRoles();


	resetCounters();//AL FINAL DE TODO RESETEAS LOS CONTADORES PA QUE NO DE ERROR Y PUEDAS VOLVER A JUGAR
}
