#ifndef _GAME_H_
#define _GAME_H_

int numplayers;
Character player[15];

enum COUNTERS {
	villagercounter,
	wolfcounter,
	devinercounter,
	girlcounter,
	huntercounter,
	MAX_COUNTERS
};

int counters[MAX_COUNTERS];

void play();

ROL putarol();
void tellNumPlayers();
void assignRoles();
void countRoles();

#endif // !_GAME_H_

