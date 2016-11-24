#include "Engine.h"
#include "Creator.h"
#include "Random.h"
#include "Config.h"
#include <SDL.h>
#include "IdleState.h"
#include "ChasingState.h"

Engine::Engine(int dropRate) :
	app {new FWApplication},
	graph {Creator {}.Create()},
	cow {new Cow {graph->GetRoot()}},
	rabbit {new Rabbit {graph->GetRoot()->NextRandom()}},
	visualiser {new Visualiser{app, graph}},
	isRunning {false},
	dropRate {dropRate}
{
	pills = new Pill*[dropRate];
	swords = new Sword*[dropRate];
	for (int i = 0; i < dropRate; ++i)
	{
		Pill* pill = pills[i] = new Pill {graph->GetRoot()};
		pill->StepRandom(Random::GetRandom(200));
		//NOTE: dont spawn if vertex already has entity.
		while (AEntity::GetEntities(pill->GetVertex()).size() > 1) 
			pill->StepRandom(Random::GetRandom(200));

		Sword* sword = swords[i] = new Sword {graph->GetRoot()};
		sword->StepRandom(Random::GetRandom(200));
		//NOTE: dont spawn if vertex already has entity.
		while (AEntity::GetEntities(sword->GetVertex()).size() > 1)
			sword->StepRandom(Random::GetRandom(200));
	}
}

Engine::~Engine()
{
	delete app;
	delete cow;
	delete rabbit;
	delete visualiser;

	for (int i = 0; i < dropRate; ++i)
	{
		delete pills[i];
		delete swords[i];
	}
}

int Engine::Start()
{
	if (isRunning)
		return EXIT_FAILURE;
	isRunning = true;

	if (!app->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}

	app->SetTargetFPS(60);
	app->SetColor(Color(255, 10, 40, 255));
	app->AddRenderable(cow);
	app->AddRenderable(rabbit);

	for (int i = 0; i < dropRate; ++i)
	{
		app->AddRenderable(pills[i]);
		app->AddRenderable(swords[i]);
	}

	int state = EXIT_SUCCESS;
	while (isRunning && app->IsRunning())
	{
		int state = Run();
		if (state != EXIT_SUCCESS)
			break;
	}

	isRunning = false;
	return state;
}

int Engine::Run()
{
	app->StartTick();

	int pollState = PollEvents();
	if (pollState != EXIT_SUCCESS)
		return pollState;

	//TODO place somewhere else
	//NOTE: if cow found rabbit move rabbit to new random vertex.
	while (cow->GetVertex() == rabbit->GetVertex())
		rabbit->StepRandom(Random::GetRandom(100));

	app->UpdateGameObjects();
	visualiser->Draw();
	app->EndTick();

	return EXIT_SUCCESS;
}

int Engine::PollEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				app->Quit();
				break;

			case SDL_KEYDOWN:
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						app->Quit();
						return EXIT_SUCCESS;

					//NOTE: press R to move both animals randomly.
					case SDLK_r:
						cow->StepRandom();
						rabbit->StepRandom();
						break;

					//NOTE: press S to start chase.
					case SDLK_s:
						rabbit->SetState(new IdleState);
						cow->SetState(new ChasingState {rabbit});
						break;

					//NOTE: press space to move cow by state //A* algoritm.
					case SDLK_SPACE:
						cow->GetState().Perform(cow);
						rabbit->GetState().Perform(rabbit);

						//NOTE: entire path searched every time space pressed.
						//							cow->StepSearch();
						break;
				}
			}
		}
	}

	return EXIT_SUCCESS;
}
