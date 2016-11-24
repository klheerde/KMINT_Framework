#pragma once

#include "AEntityState.h"
#include "Vertex.h"

class ChasingState : public AEntityState
{
protected:
	AEntity* target;

public:
	ChasingState(AEntity* target);

	void Perform(AEntity* entity) const override;
};

