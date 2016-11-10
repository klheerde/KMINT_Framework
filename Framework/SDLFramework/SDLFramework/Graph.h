#pragma once

#include <vector>
#include "Vertex.h"

class Graph
{
private:
	std::vector<vtx_ptr> vertices;

public:
	Graph();
	~Graph();

	void AddVertex(vtx_ptr vertex);
};

