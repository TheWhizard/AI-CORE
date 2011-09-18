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
	Vector3D					facing;
	Vector3D					velocity;
	//update() world information
	int							magF, magB, magL, magR;
	Vector3D					playerPos;
	bool						visible;

	
	// Declare Public Methods
public:
	void ChangeState(State<AiManager>* pNewState);
	void RevertToPreviousState();
	AiManager(int id);
	void Update(int, int, int, int, Vector3D, bool);
	StateMachine<AiManager>*  GetFSM()const{return m_pStateMachine;}

	//fetch aimanager attributes
	Vector3D GetLocation() {return location;}
	Vector3D GetFacing() {return facing;}
	Vector3D GetPlayerPos() {return playerPos;}
	bool GetVisible() {return visible;}
	int GetMagF() {return magF;}
	int GetMagB() {return magB;}
	int GetMagL() {return magL;}
	int GetMagR() {return magR;}
	State<AiManager>* GetPrevious() {return m_pPreviousState;}

	//set velocity
	void SetVelocity(Vector3D vel) {velocity = vel;}
	
	~AiManager(){delete m_pStateMachine;}



};

#endif