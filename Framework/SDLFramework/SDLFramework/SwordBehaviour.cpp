#include "SwordBehaviour.h"
#include "AEntity.h"
#include "ChasingState.h"
#include "Cow.h"
#include "Engine.h"

SwordBehaviour::SwordBehaviour(Engine* engine) :
	engine {engine}
{ }

void SwordBehaviour::Perform(AEntity* entity) const
{
	Cow* cow = dynamic_cast<Cow*>(entity);

	//NOTE: if is not cow, do nothing.
	if (cow == nullptr)
		return;

	cow->SetState(new ChasingState {engine->GetRabbit()});

	//NOTE: comment block hier niet weghalen:
////	AEntity* target = cow == nullptr ? engine->GetCow() : engine->GetRabbit();
//	AEntity* target;
//	//NOTE: if is cow catch rabbit and vice versa.
//	if (cow == nullptr)
//		target = engine->GetCow();
//	else
//		target = engine->GetRabbit();
//
//	entity->SetState(new ChasingState {target});
}
