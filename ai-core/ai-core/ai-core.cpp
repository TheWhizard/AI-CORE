#include <iostream>
#include <math.h>

#include "StateMachine.h"

using namespace std;

// Name of AiManager Class
class AiManager
{
	// Declare Public Methods
public:
	AiManager(int id)
	{
		SetID(id);
	}
	virtual ~AiManager(){};

	int	ID()const{return m_ID;}
	
	// Declare Private Methods
private:
	int	m_ID;
	static int m_iNextValidID;
	void SetID(int val);
};



// Name of AiChase Class
class AiChase
{
	// Declare Public Methods
public:
	AiChase();
	~AiChase();

	// Declare Private Methods
private:

};


// Name of AiExplore Class
class AiExplore
{
	// Declare Public Methods
public:
	AiExplore();
	~AiExplore();

	// Declare Private Methods
private:

};


// Name of AiFollowPath Class
class AiFollowPath
{
	// Declare Public Methods
public:
	AiFollowPath();
	~AiFollowPath();

	// Declare Private Methods
private:

};


// Name of AiAvoid Class
class AiAvoid
{
	// Declare Public Methods
public:
	AiAvoid();
	~AiAvoid();

	// Declare Private Methods
private:

};


// Name of AiEvade Class
class AiEvade
{
	// Declare Public Methods
public:
	AiEvade();
	~AiEvade();

	// Declare Private Methods
private:

};


int main () 
{
	return 0;
}


