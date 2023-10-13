#pragma once
#include "Wall.h"

class Explorer;

class EnchantedWall : public Wall
{
public:
	EnchantedWall();
	virtual void Enter(Explorer* e) override;
	int GetEnchantedWallDamage() { return enchantedWallDamage; }
	void SetEnchantedWallDamage(int d) { enchantedWallDamage = d; }
protected:
private:
	int enchantedWallDamage;

};