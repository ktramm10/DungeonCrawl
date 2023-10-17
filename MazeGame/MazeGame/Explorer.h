#pragma once
#include <iostream>
#include <string>
#include <vector>
enum EDirection;
class Room;
class Maze;
class GameState;
class Interactables;
class Explorer
{
public:
	Explorer(Maze* maze);
	void SayLocation();
	void Move(EDirection direction);
	void Unlock(EDirection direction);
	void AddToLootList(Interactables* interactable);
	void CheckForLoot();
public:
	//Getters and Setters
	Room* GetLocation() { return CurrentRoomLocation; }
	Maze* GetMaze() { return GameMaze; }
	void SetLocation(Room* r) { CurrentRoomLocation = r; }
	int GetHealth() { return health; }
	void SetHealth(int i) { health = i; }
	int GetMagicPoints() { return magicPoints; }
	void SetMagicPoints(int i) { magicPoints = i; }
	std::vector<Interactables*> GetLootList() { return interactableLootList; }
	int GetCoinsCollected() { return CoinsCollected; }
	void SetCoinsCollected(int i) { CoinsCollected = i; }
	int GetKeys() { return keys; }
	void SetKeys(int i) { keys = i; }
private:
	Room* CurrentRoomLocation;
	Maze* GameMaze;
	int health;
	int maxHealth = 100;
	std::string name;   
	int magicPoints;
	int maxMagicPoints = 100;
	std::vector<Interactables*> interactableLootList;
	int CoinsCollected;
	int keys;
};