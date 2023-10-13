#include "Maze.h"
#include "Room.h"
void Maze::AddRoom(Room* r)
{
	RoomList.push_back(r);
}

Room* Maze::RoomNo(int i)
{
	for (Room* room : RoomList)
	{
		if (room->GetRoomNumber() == i)
		{
			return room;
		}
	}
	return NULL;
}
