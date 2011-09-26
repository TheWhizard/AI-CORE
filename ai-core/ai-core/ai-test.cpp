#include "ai-core.h"

int main () 
{
	//
	// Setting an initial vector
	//
	Vector3D vec(0.00, 0.00, 0.00);
	
	//
	// Instantiate an AiManager bot named Warren with an ID of 1
	//
	AiManager Warren(1);
	//
	// Set the initial STATE MACHINE state to Explore
	//
	Warren.SetStateExplore();
	//
	// Normally this would be some sort of almost infinite loop
	// This runs through 20 times, and calls update
	//
	for (int i=0; i<20; ++i)
	{
		//
		// The Instantiation of AiManager called Warren
		// gets update by running Warren.Update
		//
		Warren.Update(1,2,3,4,vec,true);
		Sleep(800);
	}
	return 0;
}

