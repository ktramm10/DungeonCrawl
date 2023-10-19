#include "Coin.h"
#include "Explorer.h"
#include <random>
#include <chrono>


Coin::Coin()
{
	numOfCoins = 0;
	eng.seed(std::chrono::system_clock::now().time_since_epoch().count());

}
void Coin::Interact(Explorer* e)
{
	int currentCoins = e->GetCoinsCollected();
	std::uniform_int_distribution<int> uni(1, 10);
	numOfCoins = uni(eng);
	e->SetCoinsCollected(currentCoins += numOfCoins);
	std::cout << "You found " << numOfCoins << " coins!" << std::endl;
	delete this;
}

void Coin::RandomizeNumOfCoins()
{
	std::uniform_int_distribution<int> uni(1, 10);
	numOfCoins = uni(eng);
}


