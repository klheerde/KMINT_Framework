#pragma once

#include <vector>
#include "Vertex.h"
#include "Edge.h"

class Graph
{
private:
	std::vector<vtx_ptr> vertices;
	std::vector<edg_ptr> edges;

public:
	Graph();
	~Graph();

	void AddVertex(vtx_ptr vertex);
	void AddEdge(edg_ptr edge);

	std::vector<vtx_ptr> GetVertices() const;
	std::vector<edg_ptr> GetEdges() const;
};

