#include "Character.h"

Character::Character(bool alive, char* name, int numplayer, ROL rol)
{
	this->alive = alive;
	this->name = name;
	this->numplayer = numplayer;
	this->rol = rol;
}

Character::~Character(){}

bool Character::isAlive() {
	if (alive)
	{
		return true;
	}
	else {
		return false;
	}
}

char* Character::getName() { return name; }
int Character::getNumPlayer() { return numplayer; }
ROL Character::getRol() { return rol; }
