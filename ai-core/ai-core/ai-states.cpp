#include "ai-states.h"
#include "State.h"
#include "ai-core.h"

#include <iostream>
#include <string>
using namespace std;

#define _DEBUG_

// AiChase
AiChase* AiChase::Instance()
{
	static AiChase instance;
	return &instance;
}

void AiChase::Enter(AiManager* aimanager)

{
	// put code here
#ifdef _DEBUG_
	cout << "AiChase::Enter()\n";
#endif
}
void AiChase::Execute(AiManager* aimanager)
{
	// put code here
#ifdef _DEBUG_
	cout << "AiChase::Execute()\n";
#endif

	//if the player is visible, increase velocity to 2 in the player direction
	//else go back to exploring
	if(aimanager->GetLocation() != aimanager->GetPlayerPos() && aimanager->GetVisible() == true)
		aimanager->SetVelocity(2);
	else
		aimanager->GetFSM()->ChangeState(AiExplore::Instance());

}
void AiChase::Exit(AiManager* aimanager)
{
	// put code here
#ifdef _DEBUG_
	cout << "AiChase::Exit()\n";
#endif
}


// AiExplore
AiExplore* AiExplore::Instance()
{
	static AiExplore instance;
	return &instance;
}

void AiExplore::Enter(AiManager* aimanager)

{
	// put code here
	{
		cout << "Woot. We did it!\n";
	}
#ifdef _DEBUG_
	cout << "AiExplore::Enter()\n";
#endif
}
void AiExplore::Execute(AiManager* aimanager)
{
	//Runs wall avoid (hugs right wall) and wanders
#ifdef _DEBUG_
		cout << "AiExplore::Execute()\n";
#endif
		aimanager->WallAvoid();
		aimanager->SetVelocity(1);

		//if player is seen, change to Chase or Evade based on aggressive
		if(aimanager->GetVisible() == true)
			if(aimanager->GetAggressive() == true)
				aimanager->GetFSM()->ChangeState(AiChase::Instance());
			else
				aimanager->GetFSM()->ChangeState(AiEvade::Instance());

}
void AiExplore::Exit(AiManager* aimanager)
{
	// put code here
#ifdef _DEBUG_
	cout << "AiExplore::Exit()\n";
#endif
}


// AiEvade
AiEvade* AiEvade::Instance()
{
	static AiEvade instance;
	return &instance;
}

void AiEvade::Enter(AiManager* aimanager)

{
	// put code here
#ifdef _DEBUG_
	cout << "AiEvade::Enter()\n";
#endif
}
void AiEvade::Execute(AiManager* aimanager)
{
	// put code here
#ifdef _DEBUG_
	cout << "AiChase::Execute()\n";
#endif

	//if the player is seen, run away
	//else go back to exploring
	if(aimanager->GetLocation() != aimanager->GetPlayerPos() && aimanager->GetVisible() == true)
	{
		//set velocity negative to player direction
		aimanager->SetVelocity(-2);
		//run custom wall avoidance for when it hits a wall running away
		if(aimanager->GetMagB() == 0)
		{
			if(aimanager->GetMagL() > 0)
				aimanager->SetFacing(270);
			else if(aimanager->GetMagR() > 0)
				aimanager->SetFacing(90);
		}
	}
	else
		aimanager->GetFSM()->ChangeState(AiExplore::Instance());

}
void AiEvade::Exit(AiManager* aimanager)
{
	// put code here
#ifdef _DEBUG_
	cout << "AiEvade::Exit()\n";
#endif
}


// AiAvoid
AiAvoid* AiAvoid::Instance()
{
	static AiAvoid instance;
	return &instance;
}

void AiAvoid::Enter(AiManager* aimanager)

{

#ifdef _DEBUG_
	cout << "AiAvoid::Enter()\n";
#endif
}
void AiAvoid::Execute(AiManager* aimanager)
{
#ifdef _DEBUG_
	cout << "AiAvoid::Execute()\n";
	Point3D temp;
	for (int i=0; i<aimanager->GetObstacleCount(); i++)
	{
		temp=aimanager->GetObstacleLocation(i);
		cout << "Obstacle #" << i << "\n";
		cout << "--------------\n" ;
		cout << "x=" << temp.x << "\n";
		cout << "y=" << temp.y << "\n";
		cout << "z=" << temp.z << "\n";
		cout << "\n\n";
#endif
	}

	// put code here

}
void AiAvoid::Exit(AiManager* aimanager)
{
	// put code here
#ifdef _DEBUG_
	cout << "AiAvoid::Exit()\n";
#endif
}


// AiFollowPath
AiFollowPath* AiFollowPath::Instance()
{
	static AiFollowPath instance;
	return &instance;
}

void AiFollowPath::Enter(AiManager* aimanager)

{
	// put code here
#ifdef _DEBUG_
	cout << "AiFollowPath::Enter()\n";
#endif
}

void AiFollowPath::Execute(AiManager* aimanager)
{

#ifdef _DEBUG_
	cout << "AiFollowPath::Execute()\n";
	Point3D temp;

	for (int i=0; i<aimanager->GetWayPointCount(); i++)
	{
		temp=aimanager->GetWayPointLocation(i);
		cout << "Way Point #" << i << "\n";
		cout << "--------------\n" ;
		cout << "x=" << temp.x << "\n";
		cout << "y=" << temp.y << "\n";
		cout << "z=" << temp.z << "\n";
		cout << "\n\n";
	}
#endif

	// put code here
}
void AiFollowPath::Exit(AiManager* aimanager)
{
	// put code here
#ifdef _DEBUG_
	cout << "AiFollowPath::Exit()\n";
#endif
}
