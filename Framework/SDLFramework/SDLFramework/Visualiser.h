#pragma once

#include "Graph.h"
#include "FWApplication.h"

class Visualiser
{
private:
	FWApplication* app;
	grp_ptr graph;

public:
	Visualiser(FWApplication* app, grp_ptr graph);
	~Visualiser();

	void Draw() const;
};

