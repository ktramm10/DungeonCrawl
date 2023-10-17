#include "Key.h"
#include <iostream>

Key::Key()
{
}

void Key::Interact(Explorer* e)
{
	int currentKeys = e->GetKeys();
	e->SetKeys(currentKeys+=1);
	std::cout << "You pickup a key on the floor of this room." << std::endl;
}
