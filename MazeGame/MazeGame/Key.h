#pragma once
#include "Interactables.h"
#include "Explorer.h"

class Room;

class Key : public Interactables
{
public:
	Key();
	Key(Room* room);
	virtual void Interact(Explorer* e) override;
protected:
private:
	Room* owningRoom;
};