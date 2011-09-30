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

	//passive or aggressive (sets Chase or Evade)
	bool						passive;
	Vector3D					location;
	int							facing;
	Vector3D					velocity;
	//update() world information
	int							magF, magB, magL, magR;
	Vector3D					playerPos;
	bool						visible;

	
	// Declare Public Methods
public:
	void ChangeState(State<AiManager>* pNewState);
	void RevertToPreviousState();
	//Constructor with id and passive/aggressive setting
	AiManager(int id, bool pas);
	//Constructor with id, passive/aggressive setting, and initial facing (preferred)
	AiManager(int id, bool pas, int fac);
	
	void Update(int, int, int, int, Vector3D, bool);
	void Update(void);

	void SetStateExplore(void);

	StateMachine<AiManager>*  GetFSM()const{return m_pStateMachine;}

	//fetch aimanager attributes
	Vector3D GetLocation() {return location;}
	int GetFacing() {return facing;}
	Vector3D GetPlayerPos() {return playerPos;}
	bool GetVisible() {return visible;}
	int GetMagF() {return magF;}
	int GetMagB() {return magB;}
	int GetMagL() {return magL;}
	int GetMagR() {return magR;}
	Vector3D GetVelocity() {return velocity;}
	bool GetPassive() {return passive;}
	State<AiManager>* GetPrevious() {return m_pPreviousState;}

	//set velocity for AI depending on facing
	void SetVelocity(int vel)
	{
		switch(facing)
		{
		case 0:
			velocity.x = vel;
			velocity.z = 0;
			break;
		case 90:
			velocity.x = 0;
			velocity.z = vel;
			break;
		case 180:
			velocity.x = -vel;
			velocity.z = 0;
			break;
		case 270:
			velocity.x = 0;
			velocity.z = -vel;
			break;
		}
	}

	//avoid wall collisions by hugging the right wall
	//turns right if available, turns around if dead end
	void WallAvoid()
	{
		if(magR > 0)
		{
			facing += 90;
			facing = facing % 360;
		}

		if(magF == 0 && magR == 0)
		{
			if(magL > 1)
			{
				facing +=270;
				facing = facing % 360;
			}
			else
			{
				facing += 180;
				facing = facing % 360;
			}
		}
	}

	//set facing by adding to current facing
	//make sure it is in increments of 90
	void SetFacing(int addFace)
	{
		facing += addFace;
	}

	
	~AiManager(){delete m_pStateMachine;}
};


#endif