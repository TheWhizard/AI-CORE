#include "ai-core.h"

using namespace std;

AiManager::AiManager(int id):BaseGameEntity(id),location(0.0, 0.0, 0.0)
	{
		cout << "Stuff";
		m_pStateMachine = new StateMachine<AiManager>(this);
		m_pStateMachine->SetCurrentState(AiExplore::Instance());
	}
