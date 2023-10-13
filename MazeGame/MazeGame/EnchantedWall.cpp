#include "EnchantedWall.h"
#include "Explorer.h"

EnchantedWall::EnchantedWall()
{
	enchantedWallDamage = 10;
}

void EnchantedWall::Enter(Explorer* e)
{
	if (e)
	{
		std::cout << "Your run into a magically charged wall. You take 10 points of damage!" << std::endl;
		e->SetHealth(e->GetHealth() - GetEnchantedWallDamage());
	}
}
