#pragma once

#include <memory>
#include "Vertex.h"

class Edge
{
private:
	int amount;
	vtx_ptr vertices[2];
	int weight;

public:
	Edge(vtx_ptr one, vtx_ptr two, int weight, int amount = 2);
	~Edge();

	vtx_ptr GetVertex(int index) const;
	int GetWeight() const;
};

typedef std::shared_ptr<Edge> edg_ptr;