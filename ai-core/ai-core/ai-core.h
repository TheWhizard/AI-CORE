#ifndef _ai_core_h_
#define _ai_core_h_

#include <iostream>
#include <math.h>
#include <string>
#include <vector>

#include "Vector3d.h"
#include "StateMachine.h"
#include "BaseGameEntity.h"
#include "ai-states.h"


struct Point3D
    {
        float x;
        float y;
        float z;
    };


// Name of AiManager Class
class AiManager : public BaseGameEntity
{
	
	// Declare Private Methods
private:
	State<AiManager>*			m_pCurrentState;  // Used by State machine
	State<AiManager>*			m_pPreviousState; // Used by State machine
	State<AiManager>*			m_pGlobalState;   // Used by State machine
	StateMachine<AiManager>*	m_pStateMachine;  // Used by State machine

	//
	// location is the Location of the bot, facing is the direction 
	// the bot is facing, velocity is the speed the bot is 
	// moving, and aggressive is the aggressive or passive state of the bot
	//

	//
	// Vector3D location
	//
	// Location of the bot as a Vector3D which has the members x, y, and z. 
	// Vector can be set via: Vector3D vec (x, y, z);
	Vector3D location;  
	
	//
	// int facing
	//
    // The bot’s facing in the world. This works off of increments of 90 (degrees) in the following way:
	// 0 = bot is facing toward the positive x-axis
	// 90 = bot is facing toward the positive z-axis
	// 180 = bot is facing toward the negative x-axis
	// 270 = bot is facing toward the negative z-axis
	int	facing;

	//
	// Vector3D velocity
	//
	// Velocity of the bot as a Vector3D which has the members x, y, and z. 
	// Vector can be set via: Vector3D vec(x, y, z);
	Vector3D velocity;

	//
	// bool agressive
	//
	// Whether or not the bot to aggressive if true or passive if false. 
	// Aggressive bots will chase players, while passive bots will evade them.
	bool aggressive;

	//
	// Update() world information
	// This is how the bot sees the world, as a collection of 
	// Magnitudes which are how many units the bot is from an 
	// obsticle either in front, back. left or right and if the
	// player is visible.  If the player is visible, what is the
	// player's position
	//
	
	//
	// int	magF, magB, magL, magR
	//
	// int magF	- The magnitude of movable spaces in front of the bot depending on the bot’s facing.
	// int magB	- The magnitude of movable spaces behind of the bot depending on the bot’s facing.
	// int magL	- The magnitude of movable spaces right of the bot depending on the bot’s facing.
	// int magR	- The magnitude of movable spaces left of the bot depending on the bot’s facing.
	int	magF, magB, magL, magR;

	//
	// Vector3D playerPos
	//
	// Location of the player as a Vector3D which has the members x, y, and z. 
	// Vector can be set via: Vector3D vec (x, y, z);
	Vector3D playerPos;
	
	//
	// bool visible
	//
	// Whether or not the bot can see the player. If the player is in the bot’s line-of-sight, this should be set to true.
	// Used to switch between Explore and Chase/Evade states.
	bool visible;

	//
	// "Smart" Arrays to hold way points and obtacles to avoid
	//
	vector<Point3D> wayPointArray;
	vector<Point3D> obstacleLocationArray;


	
	// Declare Public Methods
public:
	void ChangeState(State<AiManager>* pNewState); // Syntax is scary, do not use
	void RevertToPreviousState(); // Syntax is scary, do not use
	State<AiManager>* GetPrevious() {return m_pPreviousState;}
	//
	// Aimanager requires a unique id
	//
	AiManager(int id);
	
	// Prototype member functions for Update, overloaded Update,
	//
	// void Update(int magF, int magB, int magL, int magR, Vector3D playerPosition, bool visible)
	//		Inputs: int magF, magB, magL, magR – Magnitudes for movable spaces in front of, 
	//			behind, to the left of, and to the right of the bot.
	//			Vector3D playerPosition - The player's position as a Vector3D
	//			bool visible - True if the player is visible to the bot, otherwise false
	//		Outputs: N/A
	//		General Operation: Updates the bot with new world data (recommended)
	void Update(int, int, int, int, Vector3D, bool);

	void Update(void); // Will run the current state without any new information

	
	// Prototype member functions for Setting the initial state
	// machine state
	void SetStateExplore(void); // Set bot state to AiExplore
	void SetStateEvade(void); // Set bot state to AiEvade
	void SetStateAvoid(void); // Set bot state to AiAvoid
	void SetStateChase(void);// Set bot state to AiChase
	void SetStateFollowPath(void); // Set bot state to AiFollowPath

	StateMachine<AiManager>*  GetFSM()const{return m_pStateMachine;}

	// Public member functions to return bot information
	// fetch aimanager attributes

	/*Vector3D GetLocation(void)
	Inputs: N/A
	Outputs: Vector3D location
	General Operation: Returns location as a Vector3D*/
	Vector3D GetLocation() {return location;}

	/*int GetFacing(void)
	Inputs: N/A
	Outputs: int facing
	General Operation: Returns facing as an int*/
	int GetFacing() {return facing;}

	/*Vector3D GetPlayerPos(void)
	Inputs: N/A
	Outputs: Vector3D playerPos
	General Operation: Returns playerPos as a Vector3D*/
	Vector3D GetPlayerPos() {return playerPos;}

	/*bool GetVisible(void)
	Inputs: N/A
	Outputs: bool visible
	General Operation: Returns true or false for if the player is
					   visible - used to switch states*/
	bool GetVisible() {return visible;}

	/*int GetMagF(void)
	Inputs: N/A
	Outputs: int magF
	General Operation: Returns magF as an int*/
	int GetMagF() {return magF;}

	/*int GetMagB(void)
	Inputs: N/A
	Outputs: int magB
	General Operation: Returns magB as an int*/
	int GetMagB() {return magB;}

	/*int GetMagL(void)
	Inputs: N/A
	Outputs: int magL
	General Operation: Returns magL as an int*/
	int GetMagL() {return magL;}

	/*int GetMagR(void)
	Inputs: N/A
	Outputs: int magR
	General Operation: Returns magR as an int*/
	int GetMagR() {return magR;}

	/*Vector3D GetVelocity(void)
	Inputs: N/A
	Outputs: Vector3D velocity
	General Operation: Returns velocity as a Vector3D*/
	Vector3D GetVelocity() {return velocity;}

	/*bool GetAggressive(void)
	Inputs: N/A
	Outputs: bool aggressive
	General Operation: Returns true or false for if the bot is aggressive
					   - used to switch states*/
	bool GetAggressive() {return aggressive;}

	/*void SetAggressive(bool aggro)
	Inputs: bool aggro
	Outputs: N/A
	General Operation: Used to set bool aggressive*/
	void SetAggressive(bool aggro)
	{
		aggressive = aggro;
	}

	/*void SetVelocity(int vel)
	Inputs: int vel
	Outputs: N/A
	General Operation: Used to set bot velocity according
					   to current facing*/
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

	/*void WallAvoid(void)
	Inputs: N/A
	Outputs: N/A
	General Operation: Runs a wall avoidance algorithm; turns
					   right when able and turns around when stuck*/
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

	/*void SetFacing(int addFace)
	Inputs: int addFace
	Outputs: N/A
	General Operation: Used to set bot facing*/
	//make sure it is in increments of 90
	void SetFacing(int addFace)
	{
		facing += addFace;
	}
	
	/*void Spawn(int face, Vector3D loc, int vel, bool aggro)
	Inputs: int face - desired facing to be set
		Vector3D loc - desired bot location
		int vel - desired initial velocity
		bool aggro - desired aggressive attribute
	Outputs: N/A
	General Operation: Used to set the initial attributes of the bot;
					   call after instantiating bot*/
	void Spawn(int face, Vector3D loc, int vel, bool aggro)
	{
		facing = face;
		location = loc;
		SetVelocity(vel);
		aggressive = aggro;
	}
	
	void AddWayPoint(Point3D wayPoint);
	// void AddWayPoint(Vector3D wayPoint)
	/*	Inputs: Vector3D waypoint
		Outputs: N/A
		General Operation: Adds a waypoint (x,y,z) to the WayPointArray*/

	void AddAvoidObstacle(Point3D obstacleLocation);
	// AddAvoidObstacle(Vector3d obstacleLocation)
	/*
		Inputs: Vector3d obstacleLocation
		Outputs: N/A
		General Operation: Adds the location of an obstacle to avoid (x,y,z) */

	int GetObstacleCount()
	{
		return obstacleLocationArray.size();
	}

	Point3D GetObstacleLocation(int number)
	{
		return obstacleLocationArray[number];
	}
//

		int GetWayPointCount()
	{
		return wayPointArray.size();
	}

	Point3D GetWayPointLocation(int number)
	{
		return wayPointArray[number];
	}

	/*~AiManager(void)
	Inputs: N/A
	Outputs: N/A
	General Operation: Deconstructor*/
	~AiManager(){delete m_pStateMachine;}
};


#endif