#ifndef _CREATURE_H_
#define  _CREATURE_H_
#include"Entity.h"
#include"Room.h"
#include<Windows.h>
class Creature : public Entity{
public:
	int health, damage, accuracy;
	Room* position;
	TYPE typeof;

public:
	unsigned int timing = GetTickCount();
	unsigned int timenow;
	void Update();
	Creature::Creature(const char* name, const char* description, const int health, const int damage, const int accuracy, TYPE entitytype, Room* position) : Entity(name, description, entitytype), health(health), damage(damage), accuracy(accuracy), position(position){

	}
	

};
#endif