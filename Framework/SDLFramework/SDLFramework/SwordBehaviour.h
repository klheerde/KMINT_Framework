#pragma once
#include "AEntityState.h"

class Engine;

class SwordBehaviour : public AEntityState
{
	Engine* engine;
public:
	SwordBehaviour(Engine* engine);

	void Perform(AEntity* entity) const override;
};

