#pragma once
#include "Interactables.h"
#include <random>

class Room;

class Coin : public Interactables
{
public:
	Coin();
	Coin(Room* owningRoom);
	virtual void Interact(Explorer* e) override;
	void RandomizeNumOfCoins();
	
protected:
private:
	int numOfCoins;
	std::default_random_engine eng;
	Room* owningRoom;

};