#ifndef STATE_H
#define STATE_H
//------------------------------------------------------------------------
//
//  Name:   State.h
//
//  Desc:   abstract base class to define an interface for a state
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
/*Template source: Programming Game AI by Example, pp.64-65
    Author: Mat Buckland
    Publisher: Jones & Bartlett Learning; 1 edition (September 30, 2004)
    ISBN-10: 1556220782
    ISBN-13: 978-1556220784
*/

template <class entity_type>
class State
{
public:

  virtual ~State(){}

  //this will execute when the state is entered
  virtual void Enter(entity_type*)=0;

  //this is the states normal update function
  virtual void Execute(entity_type*)=0;

  //this will execute when the state is exited. (My word, isn't
  //life full of surprises... ;o))
  virtual void Exit(entity_type*)=0;
};

#endif