#include "Cow.h"
#include "WanderingState.h"

Cow::Cow(vtx_ptr vertex) :
	AEntity(vertex, "cow-2.png")
{ 
	SetState(new WanderingState);
}
