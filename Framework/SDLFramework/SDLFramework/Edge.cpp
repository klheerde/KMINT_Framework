#include "Edge.h"

Edge::Edge(vtx_ptr one, vtx_ptr two, int weight, int amount) :
	vertices {one, two}, weight {weight}, amount {amount}
{ }

Edge::~Edge()
{ }

vtx_ptr Edge::GetVertex(int index) const
{
	if (index < amount)
		return vertices[index];

	return nullptr;
}

int Edge::GetWeight() const
{
	return weight;
}