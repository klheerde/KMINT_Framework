#pragma once

#include <vector>
#include "Vertex.h"
#include "Edge.h"

class Graph
{
private:
	std::vector<edg_ptr> edges;
	std::vector<vtx_ptr> vertices;

public:
	Graph();
	~Graph();

	void AddEdge(edg_ptr edge);
	void AddVertex(vtx_ptr vertex);

	vtx_ptr GetRoot() const;
	std::vector<edg_ptr> GetEdges() const;
	std::vector<vtx_ptr> GetVertices() const;
};

typedef std::shared_ptr<Graph> grp_ptr;
