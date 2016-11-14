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

	vtx_ptr GetRoot() const;
	std::vector<vtx_ptr> GetVertices() const;
	std::vector<edg_ptr> GetEdges() const;
};

typedef std::shared_ptr<Graph> grp_ptr;
