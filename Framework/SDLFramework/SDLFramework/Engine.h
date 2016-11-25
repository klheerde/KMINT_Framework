#pragma once
#include "FWApplication.h"
#include "Graph.h"
#include "Cow.h"
#include "Rabbit.h"
#include "Pill.h"
#include "Visualiser.h"
#include "Sword.h"

class Engine
{
private:
	FWApplication* app;
	grp_ptr graph;

	Cow* cow;
	Rabbit* rabbit;

	int dropRate;
	Pill** pills;
	Sword** swords;

	Visualiser* visualiser;

	/**
	 * Only Start() may alter this variable.
	 */
	bool isRunning;

public:
	Engine(int dropRate = 10);
	~Engine();

	int Start();

	Cow* GetCow() const;
	Rabbit* GetRabbit() const;

private:
	int Run();
	int PollEvents();
};

