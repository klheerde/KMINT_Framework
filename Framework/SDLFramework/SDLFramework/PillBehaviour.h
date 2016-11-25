#pragma once

#include "AEntityState.h"

class PillBehaviour : public AEntityState
{
public:
	void Perform(AEntity* entity) const override;
};

