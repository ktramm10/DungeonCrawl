#pragma once
#include "Interactables.h"
#include <iostream>
#include "Items.h"
#include <random>

class RNG;

class Chest : public Interactables
{
public:
	Chest();
	virtual void Interact(Explorer* e) override;
	void OpenChest(Explorer* e);
	bool ValidateInput(std::string str);

public:
	bool GetIsLocked() { return isLocked; }
	void SetIsLocked(bool b) { isLocked = b; }
protected:
private:
	bool isLocked;
	Items* loot;
	RNG* rng;
	std::default_random_engine eng;
};