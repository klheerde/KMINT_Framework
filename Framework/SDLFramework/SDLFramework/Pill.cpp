#include "Pill.h"
#include "Random.h"
#include "PillBehaviour.h"

Pill::Pill(vtx_ptr vertex) :
	ADropEntity(vertex, "pill.png")
{
	SetState(new PillBehaviour);
}
