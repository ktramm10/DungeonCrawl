#include "Coin.h"
#include "Explorer.h"
#include <random>
#include <chrono>
#include "Room.h"


Coin::Coin()
{
	numOfCoins = 0;
	eng.seed(std::chrono::system_clock::now().time_since_epoch().count());

}
Coin::Coin(Room* owningRoom)
{
	numOfCoins = 0;
	eng.seed(std::chrono::system_clock::now().time_since_epoch().count());
	this->owningRoom = owningRoom;
}
void Coin::Interact(Explorer* e)
{
	int currentCoins = e->GetCoinsCollected();
	RandomizeNumOfCoins();
	e->SetCoinsCollected(currentCoins += numOfCoins);
	std::cout << "You found " << numOfCoins << " coins!" << std::endl;
	owningRoom->SetRoomLoot(0);
	delete this;
	
}

void Coin::RandomizeNumOfCoins()
{
	std::uniform_int_distribution<int> uni(1, 10);
	numOfCoins = uni(eng);
}


