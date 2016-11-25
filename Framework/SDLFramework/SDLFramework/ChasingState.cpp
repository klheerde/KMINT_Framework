#include "ChasingState.h"
#include "AEntity.h"
#include "EntityVertex.h"
#include "Random.h"

ChasingState::ChasingState(AEntity* target) :
	target{target}
{ }

void ChasingState::Perform(AEntity* entity) const
{
	vtx_ptr vertex {entity->GetVertex()};
	std::vector<vtx_ptr> path {vertex->PathTo(target->GetVertex())};
	//NOTE: 0 = current vertex, 1 = next.
	if (path.size() > 1)
		entity->SetVertex(path[1]);

	std::shared_ptr<EntityVertex> entityVertex {EntityVertex::Cast(entity->GetVertex())};
	std::vector<AEntity*> entities;

	//NOTE: if target caught, relocate target and make sure not relocated to same.
	while ((entities = entityVertex->GetEntities()).size() > 1 &&
		std::find(entities.begin(), entities.end(), target) != entities.end()
	) {
		target->StepRandom(Random::GetRandom(100));
		target->SetState(new WanderingState);
	}

	CheckForDrop(entity);
}