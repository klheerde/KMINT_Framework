#pragma once

#include "Vertex.h"

class Edge
{
private:
	vtx_ptr vertices[2];

	int weight;
public:
	Edge(vtx_ptr one, vtx_ptr two, int weight);
	~Edge();
};

