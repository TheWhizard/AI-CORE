#ifndef _ai_core_h_
#define _ai_core_h_

#include <iostream>
#include <math.h>

#include "Vector3d.h"
#include "StateMachine.h"
#include "BaseGameEntity.h"
#include "ai-states.h"


// Name of AiManager Class
class AiManager : public BaseGameEntity
{
	
	// Declare Private Methods
private:
	State<AiManager>*			m_pCurrentState;
	State<AiManager>*			m_pPreviousState;
	State<AiManager>*			m_pGlobalState;
	StateMachine<AiManager>*	m_pStateMachine;

	Vector3D					location;
	
	// Declare Public Methods
public:
	void ChangeState(State<AiManager>* pNewState);
	void RevertToPreviousState();
	AiManager(int id);

	

	
	~AiManager(){delete m_pStateMachine;}



};

#endif