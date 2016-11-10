#pragma once

#include <memory>

class Vertex
{
private:
	int x;
	int y;

public:
	Vertex(int x, int y);
	~Vertex();
};

typedef std::shared_ptr<Vertex> vtx_ptr;

