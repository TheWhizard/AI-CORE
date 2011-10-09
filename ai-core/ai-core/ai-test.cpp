#include "ai-core.h"

int main () 
{
	// Create a vector for Bot to Spawn
	Vector3D botVec(1.0, 0.0, 3.0);
	// Create a velocity for the Bot to be moving when it spawns
	double botVel = 1.0;
	// Create a direction for the bot to be facing
	double facing = 90;
	// Set bot to aggressive 1 or not aggressive 0
	bool aggressive = 1;

	// Create a location for the player
	Vector3D vec(0.0, 0.0, 0.0);
	//
	// Instantiate an AiManager bot named Warren with an ID of 1
	//
	AiManager Warren(1);
	
	// Spawn the Bot at the botVec location, etc.
	Warren.Spawn(facing, botVec, botVel, aggressive);
	// Set the initial bot state to Explore
	Warren.SetStateExplore();
	// Tell the bot it can't see any direction to go 
	// be sure to update this in your game loop
	Warren.Update(0,0,0,0,vec,false);
	// Other possibilities
	// Warren.SetStateChase();
	// Warren.SetStateEvade();
	// Warren.SetStateFollowPath();
	// Warren.SetStateAvoid();

	Point3D me;
	me.x=1.2;
	me.y=2.4;
	me.z=3.5;
	Warren.AddAvoidObstacle(me);

	me.x=4.1;
	me.y=5.2;
	me.z=6.3;
	Warren.AddAvoidObstacle(me);

	me.x=9.0;
	me.y=7.7;
	me.z=8.6;
	Warren.AddAvoidObstacle(me);

	Warren.SetStateAvoid();
	Warren.Update(0,0,0,0,vec,false);
//
	me.x=9.9;
	me.y=0.0;
	me.z=10.23;
	Warren.AddWayPoint(me);

	me.x=10.71;
	me.y=0.0;
	me.z=33.33;
	Warren.AddWayPoint(me);

	me.x=0.0;
	me.y=0.0;
	me.z=0.0;
	Warren.AddWayPoint(me);

	Warren.SetStateFollowPath();
	Warren.Update(0,0,0,0,vec,false);
	//
	// Normally this would be some sort of almost infinite loop
	// This runs through 20 times, and calls update
	//
	/*for (int i=0; i<20; ++i)
	{
		//
		// The Instantiation of AiManager called Warren
		// gets update by running Warren.Update
		//
	
		// Calculate magF, magB, magL, magR, the player position (if seen)
		// and the player visible to TRUE if we can see the player

		// You will have to calculate the Line of Sight 
		// Hint: the bots location is Warren.GetLocation() and returns Vector3D
		Warren.Update(1,2,3,4,vec,true);

	}
	*/
	return 0;
}
