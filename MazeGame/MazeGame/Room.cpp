#include "Room.h"
#include "Door.h"
#include "Wall.h"
#include <typeinfo>
#include "Enemy.h"

Room::Room(int roomNo)
{
	roomNumber = roomNo;
}

Room::Room(int roomNo, Interactables* loot)
{
	roomNumber = roomNo;
	roomLoot = loot;
}

Room::Room(int roomNo, Interactables* loot, Enemy* theEnemy)
{
	roomNumber = roomNo;
	roomLoot = loot;
	enemy = theEnemy;
}


Mapsite* Room::GetSide(EDirection e) const
{
	switch (e)
	{
	case EDirection::ED_North:
		return sides[0];
		break;
	case EDirection::ED_South:
		return sides[1];
		break;
	case EDirection::ED_East:
		return sides[2];
		break;
	case EDirection::ED_West:
		return sides[3];
		break;
	default:
		return NULL;
		break;
	}
}

	void Room::SetSide(EDirection e, Mapsite* m)
	{
	switch (e)
	{
	case EDirection::ED_North:
		sides[0] = m;
		break;
	case EDirection::ED_South:
		sides[1] = m;
		break;
	case EDirection::ED_East:
		sides[2] = m;
		break;
	case EDirection::ED_West:
		sides[3] = m;
		break;
	}
}

void Room::Enter(Explorer* e)
{
	throw std::invalid_argument("CHARACTER TRIED TO ENTER A ROOM DIRECTLY (NOT THROUGH A DOOR)");
}

bool Room::CheckIfDoor(EDirection e)
{
	return GetSide(e)->IsDoor();
}

bool Room::IsDoor()
{
	return false;
}


