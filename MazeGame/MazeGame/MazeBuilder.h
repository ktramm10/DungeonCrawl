#pragma once
enum EDirection;
class Maze;

class MazeBuilder
{
public:
	virtual void BuildMaze() {}
	virtual void BuildRoom(int room) {}
	virtual void BuildDoor(int roomFrom, int roomTo, EDirection roomFromDirection){}

	virtual Maze* GetMaze() { return 0; }
protected:
	MazeBuilder();
};