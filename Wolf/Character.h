#ifndef _CHARACTER_H
#define _CHARACTER_H_

#include <time.h>
#include <stdlib.h>


enum ROL
{
	VILLAGER,
	WOLF,
	DEVINER,
	GIRL,
	HUNTER,
	MAX_ROLE
};




class  Character
{
private:
	bool alive = true;
	char* name = "Player";
	int numplayer;
	ROL rol;
public:
	 Character(bool alive, char* name, int numplayer, ROL rol);
	~ Character();
	bool isAlive();
	char* getName();
	int getNumPlayer();
	ROL getRol();

};

int getRandome(int maxrandome) {
	return (rand() % maxrandome) + 1;//meter semilla en main
}



#endif // !_CHARACTER_H


