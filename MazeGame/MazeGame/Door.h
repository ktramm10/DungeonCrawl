#pragma once
#include "MapSite.h"
class Room;

class Door : public Mapsite
{
public:
	virtual void Enter(Explorer* e) override;
	virtual bool IsDoor() override;
	Door();
	Door(Room* r1, Room* r2);
	Room* OtherSideFrom(Room* r);
	void SetIsOpen(bool b) { _isOpen = b; }
	 
private:
	Room* _room1;
	Room* _room2;
	bool _isOpen = true;
};