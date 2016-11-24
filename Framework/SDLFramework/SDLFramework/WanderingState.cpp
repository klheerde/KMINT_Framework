#include "WanderingState.h"
#include "AEntity.h"

void WanderingState::Perform(AEntity* entity) const
{
	entity->StepRandom();
}
