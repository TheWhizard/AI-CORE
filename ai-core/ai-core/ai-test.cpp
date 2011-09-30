#include "ai-core.h"

int main () 
{
	//
	// Setting an initial vector
	//
	Vector3D vec(0.00, 0.00, 0.00);
	int vector_array_size = 5;
	Vector3D * vector_array = NULL;

	vector_array = new Vector3D[vector_array_size];
	for (int i=0; i<vector_array_size; i++) {
		vector_array[i]=Vector3D::Vector3D(i,i,i);
	}
	
	//
	// Instantiate an AiManager bot named Warren with an ID of 1
	//
	AiManager Warren(1);
	//
	// Set the initial STATE MACHINE state to Explore
	//
	cout << "SetStateExplore()\n";
	Warren.SetStateExplore();
	Warren.Update(1,2,3,4,vec,true);
	Sleep(800);
	cout << "SetStateChase()\n";
	Warren.SetStateChase();
	Warren.Update(1,2,3,4,vec,true);
	Sleep(800);
	cout << "SetStateEvade()\n";
	Warren.SetStateEvade();
	Warren.Update(1,2,3,4,vec,true);
	Sleep(800);
	cout << "SetStateFollowPath()\n";
	Warren.SetStateFollowPath();
	Warren.Update(1,2,3,4,vec,true);
	Sleep(800);
	cout << "SetStateAvoid()\n";
	Warren.SetStateAvoid();
	Warren.Update(1,2,3,4,vec,true);
	Sleep(800);
//cout << "GetLocation " << Warren.GetLocation() << "\n";
	//cout << "GetFacing " << Warren.GetFacing() << "\n";
	//cout << "GetPlayerPos " << Warren.GetPlayerPos() << "\n";

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
