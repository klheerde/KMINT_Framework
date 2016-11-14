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


int main(int args[])
{
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	//NOTE: setup.
	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));
	
	grp_ptr graph = Creator {}.Create();
	Visualiser visualiser {application, graph};

	//NOTE: create cow.
	Cow* cow = new Cow {graph->GetRoot()};
	application->AddRenderable(cow);
	//

	while (application->IsRunning())
	{
		application->StartTick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_r:
					cow->NextVertex();
					break;

				default:
					break;
				}
			}
		}
		

		application->UpdateGameObjects();

		visualiser.Draw();

		application->EndTick();


//		// This is example code, replace with your own!
//
//		// Dancing cow
//		ExampleGameObject *example = new ExampleGameObject();
//		application->AddRenderable(example);
//
//		// Text drawing
//		application->SetColor(Color(0, 0, 0, 255));
//		application->DrawText("Welcome to KMint", 400, 300);
//		
//		// Graph drawing
//		application->SetColor(Color(0, 0, 0, 255));
//		application->DrawLine(400, 350, 350, 400);
//		application->DrawLine(350, 400, 450, 400);
//		application->DrawLine(450, 400, 400, 350);
//
//		application->SetColor(Color(0, 0, 255, 255));
//		application->DrawCircle(400, 350, 10, true);
//		application->DrawCircle(350, 400, 10, true);
//		application->DrawCircle(450, 400, 10, true);
//
//		// For the background
//		application->SetColor(Color(255, 255, 255, 255));
//
//		application->UpdateGameObjects();
//		application->RenderGameObjects();
//		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}
