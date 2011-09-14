#include "ai-core.h"

// Name of AiChase Class
class AiChase : public State<AiManager>
{
	// Declare Private Methods
private:
	AiChase(){}
	AiChase(const AiChase*);
	AiChase& operator=(const AiChase&);

	// Declare Public Methods
public:
	// Singleton
	static AiChase* Instance();
	virtual void Enter(AiManager* aimanager);
	virtual void Execute(AiManager* aimanager);
	virtual void Exit(AiManager* aimanager);
};

void AiChase::Enter(AiManger* aimanager)
{
// Write Code Here
}

void AiChase::Execute(AiManger* aimanager)
{
// Write Code Here
}

void AiChase::Exit(AiManger* aimanager)
{
// Write Code Here
}

// Name of AiExplore Class
class AiExplore : public State<AiManager>
{
	// Declare Private Methods
private:
	AiExplore(){}
	AiExplore(const AiExplore*);
	AiExplore& operator=(const AiExplore&);

	// Declare Public Methods
public:
	// Singleton
	static AiExplore* Instance();
	virtual void Enter(AiManager* aimanager);
	virtual void Execute(AiManager* aimanager);
	virtual void Exit(AiManager* aimanager);
};

void AiExplore::Enter(AiManger* aimanager)
{
// Write Code Here
}

void AiExplore::Execute(AiManger* aimanager)
{
// Write Code Here
}

void AiExplore::Exit(AiManger* aimanager)
{
// Write Code Here
}

// Name of AiFollowPath Class
class AiFollowPath : public State<AiManager>
{
	// Declare Private Methods
private:
	AiFollowPath(){}
	AiFollowPath(const AiFollowPath*);
	AiFollowPath& operator=(const AiFollowPath&);

	// Declare Public Methods
public:
	// Singleton
	static AiFollowPath* Instance();
	virtual void Enter(AiManager* aimanager);
	virtual void Execute(AiManager* aimanager);
	virtual void Exit(AiManager* aimanager);
};

void AiFollowPath::Enter(AiManger* aimanager)
{
// Write Code Here
}

void AiFollowPath::Execute(AiManger* aimanager)
{
// Write Code Here
}

void AiFollowPath::Exit(AiManger* aimanager)
{
// Write Code Here
}


// Name of AiAvoid Class
class AiAvoid : public State<AiManager>
{
	// Declare Private Methods
private:
	AiAvoid(){}
	AiAvoid(const AiAvoid*);
	AiAvoid& operator=(const AiAvoid&);

	// Declare Public Methods
public:
	// Singleton
	static AiAvoid* Instance();
	virtual void Enter(AiManager* aimanager);
	virtual void Execute(AiManager* aimanager);
	virtual void Exit(AiManager* aimanager);
};

void AiAvoid::Enter(AiManger* aimanager)
{
// Write Code Here
}

void AiAvoid::Execute(AiManger* aimanager)
{
// Write Code Here
}

void AiAvoid::Exit(AiManger* aimanager)
{
// Write Code Here
}

// Name of AiEvade Class
class AiEvade : public State<AiManager>
{
	// Declare Private Methods
private:
	AiEvade(){}
	AiEvade(const AiEvade*);
	AiEvade& operator=(const AiEvade&);

	// Declare Public Methods
public:
	// Singleton
	static AiEvade* Instance();
	virtual void Enter(AiManager* aimanager);
	virtual void Execute(AiManager* aimanager);
	virtual void Exit(AiManager* aimanager);
};

void AiEvade::Enter(AiManger* aimanager)
{
// Write Code Here
}

void AiEvade::Execute(AiManger* aimanager)
{
// Write Code Here
}

void AiEvade::Exit(AiManger* aimanager)
{
// Write Code Here
}