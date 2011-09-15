#include "ai-states.h"
#include "State.h"
#include "ai-core.h"

#include <iostream>
using namespace std;

// AiChase
AiChase* AiChase::Instance()
{
	static AiChase instance;
	return &instance;
}

void AiChase::Enter(AiManager* aimanager)

{
	// put code here
	cout << "AiChase::Enter()\n";
}
void AiChase::Execute(AiManager* aimanager)
{
	// put code here
		cout << "AiChase::Execute()\n";

}
void AiChase::Exit(AiManager* aimanager)
{
	// put code here
	cout << "AiChase::Exit()\n";
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
	cout << "AiExplore::Enter()\n";
}
void AiExplore::Execute(AiManager* aimanager)
{
	// put code here
		cout << "AiExplore::Execute()\n";

}
void AiExplore::Exit(AiManager* aimanager)
{
	// put code here
	cout << "AiExplore::Exit()\n";
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
	cout << "AiEvade::Enter()\n";
}
void AiEvade::Execute(AiManager* aimanager)
{
	// put code here
		cout << "AiEvade::Execute()\n";

}
void AiEvade::Exit(AiManager* aimanager)
{
	// put code here
	cout << "AiEvade::Exit()\n";
}


// AiAvoid
AiAvoid* AiAvoid::Instance()
{
	static AiAvoid instance;
	return &instance;
}

void AiAvoid::Enter(AiManager* aimanager)

{
	// put code here
	cout << "AiAvoid::Enter()\n";
}
void AiAvoid::Execute(AiManager* aimanager)
{
	// put code here
		cout << "AiAvoid::Execute()\n";

}
void AiAvoid::Exit(AiManager* aimanager)
{
	// put code here
	cout << "AiAvoid::Exit()\n";
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
	cout << "AiFollowPath::Enter()\n";
}
void AiFollowPath::Execute(AiManager* aimanager)
{
	// put code here
		cout << "AiFollowPath::Execute()\n";

}
void AiFollowPath::Exit(AiManager* aimanager)
{
	// put code here
	cout << "AiFollowPath::Exit()\n";
}
