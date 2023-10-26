#pragma once
#include "MapSite.h"
class Enemy;

class Room: public Mapsite
{
public:
	Room(int roomNo);
	Room(int roomNo, Interactables* loot);
	Room(int roomNo, Interactables* loot, Enemy* theEnemy);

	virtual void Enter(Explorer* e) override;
	bool CheckIfDoor(EDirection e);
	virtual bool IsDoor() override;
public:
	Mapsite* GetSide(EDirection e) const;
	void SetSide(EDirection e, Mapsite* m);
	int GetRoomNumber() { return roomNumber; }\
	Interactables* GetRoomLoot() { return roomLoot; }
	void SetRoomLoot(Interactables* interactable) { roomLoot = interactable; }
	Enemy* GetEnemy() { return enemy; }
	void SetEnemy(Enemy* e) { enemy = e; }
private:
	Mapsite* sides[4];
	int roomNumber;
	Interactables* roomLoot;
	Enemy* enemy;
};