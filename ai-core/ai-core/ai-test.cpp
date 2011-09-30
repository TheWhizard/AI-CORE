#include "ai-core.h"
#include <iostream>

int main () 
{
	Vector3D vec(1.00, 2.00, 3.00);
	Vector3D vec2(0, 0, 0);
	
	AiManager Warren(1);
	Warren.Spawn(270, vec, vec2, true);
	Warren.SetStateExplore();
	for (int i=0; i<1; ++i)
	{
			Warren.Update(1,2,3,4,vec,false);
			Sleep(800);
	}
	cout << Warren.GetFacing() << endl << Warren.GetLocation().x << ", " << Warren.GetLocation().z << endl << Warren.GetVelocity().x << ", " << Warren.GetVelocity().z << endl << Warren.GetAggressive();

	system("PAUSE");
	return 0;
}

