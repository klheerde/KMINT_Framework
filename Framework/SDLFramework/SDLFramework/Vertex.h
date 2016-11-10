#pragma once

#include <memory>

typedef std::shared_ptr<Vertex> vtx_ptr;

class Vertex
{
private:
	int x;
	int y;

public:
	Vertex(int x, int y);
	~Vertex();
};

