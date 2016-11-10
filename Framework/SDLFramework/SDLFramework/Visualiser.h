#pragma once

#include "Graph.h"
#include "FWApplication.h"

class Visualiser
{
private:
	FWApplication const* app;

public:
	Visualiser(FWApplication const* app, std::unique_ptr<Graph const> graph);
	~Visualiser();

	void Draw() const;
};

