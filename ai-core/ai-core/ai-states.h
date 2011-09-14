#ifndef _STATES_H_
#define _STATES_H_

#include "State.h"
#include "ai-core.h"

class AiManager;


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


#endif