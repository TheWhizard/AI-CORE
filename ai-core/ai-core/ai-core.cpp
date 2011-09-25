#include "ai-core.h"

using namespace std;

//AiManager::AiManager(int id):BaseGameEntity(id),location(0.0, 0.0, 0.0),facing(1.0,0.0,0.0),m_pCurrentState(AiExplore::Instance())
AiManager::AiManager(int id):BaseGameEntity(id)
	{
		cout << "Creating State machine.\n";
		m_pStateMachine = new StateMachine<AiManager>(this);
	}

//updates the AI by processing world information fed to it
void AiManager::Update(int f, int b, int l, int r, Vector3D pos, bool vis)
{
	//number of spaces available for movement in each direction
	magF = f;
	magB = b;
	magL = l;
	magR = r;
	//player position
	playerPos = pos;
	//is the player visible?
	visible = vis;

	m_pStateMachine->Update();
}

void AiManager::Update(void)
{
	m_pStateMachine->Update();
}

void AiManager::SetStateExplore()
{
	m_pStateMachine->SetCurrentState(AiExplore::Instance());
}
