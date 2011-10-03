#ifndef _ai_core_h_
#define _ai_core_h_

#include <iostream>
#include <math.h>

#include "Vector3d.h"
#include "StateMachine.h"
#include "BaseGameEntity.h"
#include "ai-states.h"

#include <string>

// Name of AiManager Class
class AiManager : public BaseGameEntity
{
	
	// Declare Private Methods
private:
	State<AiManager>*			m_pCurrentState;
	State<AiManager>*			m_pPreviousState;
	State<AiManager>*			m_pGlobalState;
	StateMachine<AiManager>*	m_pStateMachine;

	//
	// location is the Location of the bot, facing is the direction 
	// the bot is facing, velocity is the speed the bot is 
	// moving, and aggressive is the aggressive or passive state of the bot
	//
	Vector3D					location;
	int							facing;
	Vector3D					velocity;
	bool						aggressive;
	//
	// Update() world information
	// This is how the bot sees the world, as a collection of 
	// Magnitudes which are how many units the bot is from an 
	// obsticle either in front, back. left or right and if the
	// player is visible.  If the player is visible, what is the
	// player's position
	//
	int							magF, magB, magL, magR;
	Vector3D					playerPos;
	bool						visible;

	
	// Declare Public Methods
public:
	void ChangeState(State<AiManager>* pNewState);
	void RevertToPreviousState();
	State<AiManager>* GetPrevious() {return m_pPreviousState;}
	//
	// Aimanager requires an id
	//
	AiManager(int id);
	
	// Prototype member functions for Update, overloaded Update,
	void Update(int, int, int, int, Vector3D, bool);
	void Update(void);

	void ReadArray(Vector3D* a, int& n, int maxsize);
	// Prototype member functions for Setting the initial state
	// machine state
	void SetStateExplore(void);
	void SetStateEvade(void);
	void SetStateAvoid(void);
	void SetStateChase(void);
	void SetStateFollowPath(void);
	//string StateName;

	

	StateMachine<AiManager>*  GetFSM()const{return m_pStateMachine;}

	// Public member functions to return bot information
	// fetch aimanager attributes
	Vector3D GetLocation() {return location;}
	int GetFacing() {return facing;}
	Vector3D GetPlayerPos() {return playerPos;}
	bool GetVisible() {return visible;}
	int GetMagF() {return magF;}
	int GetMagB() {return magB;}
	int GetMagL() {return magL;}
	int GetMagR() {return magR;}

	//set aggressive or passive to determine Chase or Evade
	void SetAggressive(bool aggro)
	{
		aggressive = aggro;
	}

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
	
	//setup all initial parameters of the bot
	void Spawn(int face, Vector3D loc, int vel, bool aggro)
	{
		facing = face;
		location = loc;
		SetVelocity(vel);
		aggressive = aggro;
	}
	
	~AiManager(){delete m_pStateMachine;}
};


#endif