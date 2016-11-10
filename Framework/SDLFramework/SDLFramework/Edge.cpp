#include "Edge.h"

Edge::Edge(vtx_ptr one, vtx_ptr two, int weight) :
	vertices {one, two}, weight {weight}
{ }

Edge::~Edge()
{ }
