#include "Wall.h"

Wall::Wall()
{
}

void Wall::Enter(Explorer* e)
{
	std::cout << "You Run Into a Wall" << std::endl;
}

bool Wall::IsDoor()
{
	return false;
}
