#pragma once
#include "MapSite.h"
class Room: public Mapsite
{
public:
	Room(int roomNo);
	Mapsite* GetSide(EDirection e) const;
	void SetSide(EDirection e, Mapsite* m);
	int GetRoomNumber() { return roomNumber; }
	virtual void Enter(Explorer* e) override;
	bool CheckIfDoor(EDirection e);
	virtual bool IsDoor() override;
private:
	Mapsite* sides[4];
	int roomNumber;
};