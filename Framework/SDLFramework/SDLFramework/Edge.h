#pragma once

#include <memory>
#include <vector>
#include "Vertex.h"

class Edge
{
private:
	int weight;
	std::vector<vtx_ptr> vertices;

public:
	Edge(vtx_ptr one, vtx_ptr two, int weight);
	~Edge();

	int GetWeight() const;
	
	vtx_ptr GetVertex(int index) const;
	std::vector<vtx_ptr> GetVertices() const;
};

typedef std::shared_ptr<Edge> edg_ptr;