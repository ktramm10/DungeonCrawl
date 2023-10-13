#pragma once
#include <iostream>
#include "MazeBuilder.h"

enum EDirection;
class Room;

class StandardMazeBuilder : public MazeBuilder
{
public:
	StandardMazeBuilder();

	virtual void BuildMaze() override;
	virtual void BuildRoom(int roomNo) override;
	virtual void BuildDoor(int roomFrom, int roomTo, EDirection roomFromDirection) override;

	virtual Maze* GetMaze() { return _currentMaze; }
	virtual void SetMaze(Maze* m) { _currentMaze = m; }
protected:

private:
	Maze* _currentMaze;
};