#include "Orc.h"
#include <iostream>
#include "RNG.h"
#include <stdexcept>

Orc::Orc()
{
	SetEnemyName("Orc");
	SetArmorClass(armorClass);
	SetHealth(orcMaxHealth);
	rng = new RNG();
}

void Orc::Attack(Explorer* e)
{
	
	if (e->GetHealth() > 0 && GetIsAlive())
	{
		if (rng->GetNumInRange(1, 20) > e->GetArmorClass())
		{
			std::cout << "The orc slashes you for " << attackDamage << " damage!" << std::endl;
			int currenthp = e->GetHealth();
			e->SetHealth(currenthp -= attackDamage);
		}
		else 
		{
			std::cout << "The orc swing his mace at the player and misses!" << std::endl;
		}

	}
}

void Orc::Die()
{
	if (!GetIsAlive())
	{
		std::cout << "The orc falls to the ground slain!" << std::endl;
		delete rng;
		delete this;
	}
	else
	{
		throw std::invalid_argument("DEATH FUNCTION CALLED WHEN ENTITY IS ALIVE");
	}
}
