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