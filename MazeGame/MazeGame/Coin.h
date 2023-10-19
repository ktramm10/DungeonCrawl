#pragma once
#include "Interactables.h"
#include <random>


class Coin : public Interactables
{
public:
	Coin();
	virtual void Interact(Explorer* e) override;
	void RandomizeNumOfCoins();
	
protected:
private:
	int numOfCoins;
	std::default_random_engine eng;

};