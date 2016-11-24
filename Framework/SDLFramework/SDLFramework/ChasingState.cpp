#include "ChasingState.h"
#include "AEntity.h"

ChasingState::ChasingState(AEntity* target) :
	target{target}
{ }

void ChasingState::Perform(AEntity* entity) const
{
	vtx_ptr vertex = entity->GetVertex();
	std::vector<vtx_ptr> path = vertex->PathTo(target->GetVertex());
	//NOTE: 0 = current vertex, 1 = next.
	entity->SetVertex(path[1]);
}
