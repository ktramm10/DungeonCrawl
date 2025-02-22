#pragma once
#include <iostream>
#include <string>
#include <vector>
enum EDirection;
class RNG;
class Room;
class Maze;
class GameState;
class Interactables;
class Items;
class Weapons;


class Explorer
{
public:
	Explorer(Maze* maze);
	void SayLocation();
	void Move(EDirection direction);
	void Unlock(EDirection direction);
	void AddToLootList(Interactables* interactable);
	void CheckForLoot();
	void AddToInventory(Items* item) { inventory.push_back(item); }
	void Attack();
public:
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
	Weapons* GetEquippedWeapon() { return equippedWeapon; }
	void SetEquippedWeapon(Weapons* weapon) { equippedWeapon = weapon; }
	std::vector<Items*> GetInventoryList() { return inventory; }
	int GetArmorClass() { return armorClass; }
	void SetArmorClass(int i) { armorClass = i; }
	bool GetInCombat() { return inCombat; }
	void SetInCombat(bool b) { inCombat = b; }
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
	std::vector<Items*> inventory;
	Weapons* equippedWeapon;
	int armorClass = 12;
	bool inCombat = false;
	int attackModifier = 5;
	RNG* rng;
};