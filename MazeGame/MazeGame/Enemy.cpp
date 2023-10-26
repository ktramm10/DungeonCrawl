#include "Enemy.h"
#include "Coin.h"

Enemy::Enemy()
{
	isAlive = true;
	loot = new Coin();
	loot->RandomizeNumOfCoins();     
}
