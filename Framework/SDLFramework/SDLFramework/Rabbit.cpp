#include "Rabbit.h"
#include "WanderingState.h"

Rabbit::Rabbit(vtx_ptr vertex) :
	AEntity(vertex, "rabbit-3.png")
{
	SetState(new WanderingState);
}
