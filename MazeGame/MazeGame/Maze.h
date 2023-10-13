#pragma once
#include <vector>
class Room;

class Maze
{
public:
	void AddRoom(Room* r);
	Room* RoomNo(int i);
private:
	std::vector<Room*> RoomList;
};