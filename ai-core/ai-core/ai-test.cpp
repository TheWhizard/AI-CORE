#include "ai-core.h"

int main () 
{
	Vector3D vec(0.00, 0.00, 0.00);
	
	AiManager Warren(1, false);
	Warren.SetStateExplore();
	for (int i=0; i<20; ++i)
	{
			Warren.Update(1,2,3,4,vec,true);
			Sleep(800);
	}
	return 0;
}

