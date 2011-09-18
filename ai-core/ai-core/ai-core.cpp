#include "ai-core.h"

using namespace std;

AiManager::AiManager(int id):BaseGameEntity(id),location(0.0, 0.0, 0.0),facing(1.0,0.0,0.0),m_pCurrentState(AiExplore::Instance())
	{
		cout << "Creating State machine.\n";
		m_pStateMachine = new StateMachine<AiManager>(this);
		m_pStateMachine->SetCurrentState(AiExplore::Instance());
	}


void AiManager::Update(int f, int b, int l, int r, Vector3D pos, bool vis)
{
	magF = f;
	magB = b;
	magL = l;
	magR = r;
	playerPos = pos;
	visible = vis;

	cout << "AiManager::Update()\n";
	m_pStateMachine->Update();
}