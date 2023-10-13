#pragma once
#include <iostream>
#include <string>
enum EDirection;
class Room;
class Maze;
class GameState;

class Explorer
{
public:
	Explorer(Maze* maze);
	void SayLocation();
	void Move(EDirection direction);
	Room* GetLocation() { return CurrentRoomLocation; }
	Maze* GetMaze() { return GameMaze; }
	void SetLocation(Room* r) { CurrentRoomLocation = r; }
	void Unlock(EDirection direction);
	int GetHealth() { return health; }
	void SetHealth(int i) { health = i; }
	int GetMagicPoints() { return magicPoints; }
	void SetMagicPoints(int i) { magicPoints = i; }
private:
	Room* CurrentRoomLocation;
	Maze* GameMaze;
	int health;
	int maxHealth = 100;
	std::string name;   
	int magicPoints;
	int maxMagicPoints = 100;

};