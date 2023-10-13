#include "Door.h"
#include "Room.h"
void Door::Enter(Explorer* e)
{
	if (e)
	{
		std::cout << "You Pass through a door into a room" << std::endl;
		e->SetLocation(OtherSideFrom(e->GetLocation()));
	}
}
bool Door::IsDoor()
{
	return true;
}
Door::Door()
{
}
Door::Door(Room* r1, Room* r2)
{
	_room1 = r1;
	_room2 = r2;
}

Room* Door::OtherSideFrom(Room* r)
{
	if (r == _room1) {
		return _room2;
	}
	else
	{
		return _room1;
	}
}
