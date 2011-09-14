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
	cout << "AiChase::Enter";
}
void AiChase::Execute(AiManager* aimanager)
{
	// put code here
		cout << "AiChase::Execute";

}
void AiChase::Exit(AiManager* aimanager)
{
	// put code here
	cout << "AiChase::Exit";
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
	cout << "AiExplore::Enter";
}
void AiExplore::Execute(AiManager* aimanager)
{
	// put code here
		cout << "AiExplore::Execute";

}
void AiExplore::Exit(AiManager* aimanager)
{
	// put code here
	cout << "AiExplore::Exit";
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
	cout << "AiEvade::Enter";
}
void AiEvade::Execute(AiManager* aimanager)
{
	// put code here
		cout << "AiEvade::Execute";

}
void AiEvade::Exit(AiManager* aimanager)
{
	// put code here
	cout << "AiEvade::Exit";
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
	cout << "AiAvoid::Enter";
}
void AiAvoid::Execute(AiManager* aimanager)
{
	// put code here
		cout << "AiAvoid::Execute";

}
void AiAvoid::Exit(AiManager* aimanager)
{
	// put code here
	cout << "AiAvoid::Exit";
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
	cout << "AiFollowPath::Enter";
}
void AiFollowPath::Execute(AiManager* aimanager)
{
	// put code here
		cout << "AiFollowPath::Execute";

}
void AiFollowPath::Exit(AiManager* aimanager)
{
	// put code here
	cout << "AiFollowPath::Exit";
}
