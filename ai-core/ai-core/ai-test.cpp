#include "ai-core.h"

int main () 
{
	AiManager Warren(1);
	for (int i=0; i<20; ++i)
	{ 
			Warren.Update();
			Sleep(800);
	}
	return 0;
}

