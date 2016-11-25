#pragma once

#include "ADropEntity.h"

class Engine;

class Sword : public ADropEntity
{
public:
	Sword(vtx_ptr vertex, Engine* engine);
};
