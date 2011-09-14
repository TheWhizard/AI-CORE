#include <iostream>
#include <math.h>

#include "Vector3d.h"
#include "StateMachine.h"
#include "BaseGameEntity.h"

using namespace std;

// Name of AiManager Class
class AiManager : public BaseGameEntity
{
	
	// Declare Private Methods
private:
	State<AiManager>*	m_pCurrentState;
	State<AiManager>*	m_pPreviousState;
	State<AiManager>*	m_pGlobalState;
	StateMachine<AiManager>*	m_pStateMachine;

	// Declare Public Methods
public:
	void ChangeState(State<AiManager>* pNewState);
	void RevertToPreviousState();
	AiManager(int id):BaseGameEntity(id)
	{
		m_pStateMachine = new StateMachine<AiManager>(this);
	}

};



// Name of AiChase Class
class AiChase
{
	// Declare Public Methods
public:
	AiChase();
	~AiChase();

	// Declare Private Methods
private:

};


// Name of AiExplore Class
class AiExplore
{
	// Declare Public Methods
public:
	AiExplore();
	~AiExplore();

	// Declare Private Methods
private:

};


// Name of AiFollowPath Class
class AiFollowPath
{
	// Declare Public Methods
public:
	AiFollowPath();
	~AiFollowPath();

	// Declare Private Methods
private:

};


// Name of AiAvoid Class
class AiAvoid
{
	// Declare Public Methods
public:
	AiAvoid();
	~AiAvoid();

	// Declare Private Methods
private:

};


// Name of AiEvade Class
class AiEvade
{
	// Declare Public Methods
public:
	AiEvade();
	~AiEvade();

	// Declare Private Methods
private:

};



