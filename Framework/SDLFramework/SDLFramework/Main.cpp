#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>

#include "ExampleGameObject.h"
#include "Visualiser.h"
#include "Creator.h"
#include "Cow.h"
#include "Rabbit.h"
#include "Random.h"
#include "ChasingState.h"
#include "IdleState.h"
#include "Pill.h"
#include "Engine.h"


int main(int args[])
{
	Engine engine;
	int state = engine.Start();
	return state;

//	//auto window = Window::CreateSDLWindow();
//	auto application = new FWApplication();
//	if (!application->GetWindow())
//	{
//		LOG("Couldn't create window...");
//		return EXIT_FAILURE;
//	}
//
//	//NOTE: setup.
//	application->SetTargetFPS(60);
//	application->SetColor(Color(255, 10, 40, 255));
//
//	grp_ptr graph = Creator{}.Create();
//	Visualiser visualiser{application, graph};
//
//	//NOTE: create new rabbit.
//	Rabbit* rabbit = new Rabbit{graph->GetRoot()->NextRandom()};
//	application->AddRenderable(rabbit);
//
//	//NOTE: create cow.
//	Cow* cow = new Cow {graph->GetRoot()};
//	application->AddRenderable(cow);
//
//	//NOTE: create pill.
//	Pill* pill = new Pill {graph->GetRoot()};
//	//NOTE: spawn in random place
//	pill->StepRandom(Random::GetRandom(200));
//	application->AddRenderable(pill);
//	//
//	while (application->IsRunning())
//	{
//		application->StartTick();
//
//		SDL_Event event;
//		while (SDL_PollEvent(&event))
//		{
//			switch (event.type)
//			{
//				case SDL_QUIT:
//					application->Quit();
//					break;
//
//				case SDL_KEYDOWN:
//				{
//					switch (event.key.keysym.sym)
//					{
//						//NOTE: press R to move both animals randomly.
//						case SDLK_r:
//							cow->StepRandom();
//							rabbit->StepRandom();
//							break;
//
//						//NOTE: press S to start chase.
//						case SDLK_s:
//							rabbit->SetState(new IdleState);
//							cow->SetState(new ChasingState {rabbit});
//							break;
//
//						//NOTE: press space to move cow by state //A* algoritm.
//						case SDLK_SPACE:
//							cow->GetState().Perform(cow);
//							rabbit->GetState().Perform(rabbit);
//
//							//NOTE: entire path searched every time space pressed.
////							cow->StepSearch();
//							break;
//					}
//				}
//			}
//		}
//
//		//NOTE: if cow found rabbit move rabbit to new random vertex.
//		while (cow->GetVertex() == rabbit->GetVertex())
//			rabbit->StepRandom(Random::GetRandom(100));
//
//
//		application->UpdateGameObjects();
//		visualiser.Draw();
//		application->EndTick();
//	}
//
//	return EXIT_SUCCESS;
}
