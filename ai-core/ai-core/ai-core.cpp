#include "ai-core.h"

using namespace std;

//AiManager::AiManager(int id):BaseGameEntity(id),location(0.0, 0.0, 0.0),facing(1.0,0.0,0.0),m_pCurrentState(AiExplore::Instance())
AiManager::AiManager(int id):BaseGameEntity(id)
	{
		//
		// Debug
		//
		cout << "Creating State machine.\n";
		m_pStateMachine = new StateMachine<AiManager>(this);
	}

//
// Updates the AI by processing world information fed to it
// This is an overloaded member function ( a new version of Update) 
//
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

void AiManager::Update(void)
{
	// Required 
	m_pStateMachine->Update();
}


void AiManager::ReadArray(Vector3D* a, int& n, int maxsize) {
    //n = 0;  // start with an empty array.
    //int* limit = a + maxsize;  // address after last element
    //while (a < limit  &&  cin >> *a) {
    //    a++;
    //    n++;
   // }
    return;
}
//readArray(temps, size, 1000);





//
// Set initial state to AiExplore
//
void AiManager::SetStateExplore()
{
	m_pStateMachine->SetCurrentState(AiExplore::Instance());
}

//
// Set initial state to AiChase
//
void AiManager::SetStateChase()
{
	m_pStateMachine->SetCurrentState(AiChase::Instance());
}

//
// Set initial state to AiEvade
//
void AiManager::SetStateEvade()
{
	m_pStateMachine->SetCurrentState(AiEvade::Instance());
}

//
// Set initial state to AiAvoid
//
void AiManager::SetStateAvoid()
{
	m_pStateMachine->SetCurrentState(AiAvoid::Instance());
}

//
// Set initial state to AiFollowPath
//
void AiManager::SetStateFollowPath()
{
	m_pStateMachine->SetCurrentState(AiFollowPath::Instance());
}
