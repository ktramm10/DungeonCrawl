#pragma once
#include <vector>
class Room;

class Maze
{
public:
	Maze();
	void AddRoom(Room* r);
	Room* RoomNo(int i);
	std::vector<Room*> GetRoomList() { return RoomList; }
	static int nextRoomNumber;
private:
	std::vector<Room*> RoomList;
};