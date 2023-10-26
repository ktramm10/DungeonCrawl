#include "Key.h"
#include <iostream>
#include "Room.h"

Key::Key()
{
}

Key::Key(Room* room)
{
	owningRoom = room;
}

void Key::Interact(Explorer* e)
{
	int currentKeys = e->GetKeys();
	e->SetKeys(currentKeys+=1);
	std::cout << "You pickup a key on the floor of this room." << std::endl;
	owningRoom->SetRoomLoot(0);
	delete this;
}
