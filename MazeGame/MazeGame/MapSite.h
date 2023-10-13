#pragma once
#include "MazeTypes.h"
#include "Explorer.h"
#include <iostream>
#include <stdexcept>
class Mapsite
{
public:
	virtual void Enter(Explorer* e) = 0;
	virtual bool IsDoor() = 0;
};