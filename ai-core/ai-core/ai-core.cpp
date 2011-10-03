#include "ai-core.h"

#define _DEBUG_
using namespace std;

//AiManager::AiManager(int id):BaseGameEntity(id),location(0.0, 0.0, 0.0),facing(1.0,0.0,0.0),m_pCurrentState(AiExplore::Instance())
AiManager::AiManager(int id):BaseGameEntity(id)
	{
		//
		// Debug
		//
#ifdef _DEBUG_
		cout << "Creating State machine.\n";
#endif
		m_pStateMachine = new StateMachine<AiManager>(this);
	}

//
// Updates the AI by processing world information fed to it
// This is an overloaded member function ( a new version of Update) 
//

/*void Update(int magF, int magB, int magL, int magR, Vector3D playerPosition, bool visible)
	Inputs: int magF, magB, magL, magR - Magnitudes for movable spaces in front of, behind, to the left of, and to the right of the bot
		Vector3D playerPosition - The player's position as a Vector3D
		bool visile - True if the player is visible to the bot, otherwise false
	Outputs: N/A
	General Operation: Updates the bot with new world data (recommended)*/
void AiManager::Update(int f, int b, int l, int r, Vector3D pos, bool vis)
{
	//
	// Number of units available for movement in each direction
	// F(orward), B(ackward), L(eft), R(ight)
	//
	magF = f;
	magB = b;
	magL = l;
	magR = r;
	//player position Vector3D
	playerPos = pos;
	//is the player visible (Boolean)
	visible = vis;

	m_pStateMachine->Update();
}

/*void Update(void)
Inputs: N/A
Outputs: N/A
General Operation: Updates the bot without
				   feeding in new world data (not recommended)*/
void AiManager::Update(void)
{
	// Required 
	m_pStateMachine->Update();
}


//
// Set initial state to AiExplore
//

/*void SetStateExplore(void)
Inputs: N/A
Outputs: N/A
General Operation: Sets bot state to Explore*/
void AiManager::SetStateExplore()
{
	m_pStateMachine->SetCurrentState(AiExplore::Instance());
}

//
// Set initial state to AiChase
//

/*void SetStateChase(void)
Inputs: N/A
Outputs: N/A
General Operation: Sets bot state to Chase*/
void AiManager::SetStateChase()
{
	m_pStateMachine->SetCurrentState(AiChase::Instance());
}

//
// Set initial state to AiEvade
//

/*void SetStateEvade(void)
Inputs: N/A
Outputs: N/A
General Operation: Sets bot state to Evade*/
void AiManager::SetStateEvade()
{
	m_pStateMachine->SetCurrentState(AiEvade::Instance());
}

//
// Set initial state to AiAvoid
//

/*void SetStateAvoid(void)
Inputs: N/A
Outputs: N/A
General Operation: Sets bot state to Avoid*/
void AiManager::SetStateAvoid()
{
	m_pStateMachine->SetCurrentState(AiAvoid::Instance());
}

//
// Set initial state to AiFollowPath
//

/*void SetStateFollowPath(void)
Inputs: N/A
Outputs: N/A
General Operation: Sets bot state to FollowPath*/
void AiManager::SetStateFollowPath()
{
	m_pStateMachine->SetCurrentState(AiFollowPath::Instance());
}
