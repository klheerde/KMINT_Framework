#include "Sword.h"
#include "SwordBehaviour.h"

Sword::Sword(vtx_ptr vertex, Engine* engine) :
	ADropEntity(vertex, "gun-metal.png")
{
	SetState(new SwordBehaviour {engine});
}
