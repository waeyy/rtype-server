//
// UCondition.cpp for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/thread
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sun Dec  6 19:59:24 2015 SOIDIKI Djamil
// Last update Sun Dec  6 20:41:13 2015 SOIDIKI Djamil
//

#include	"UCondition.hh"

using namespace	Thread::Condition;

UCondition::UCondition()
{
}

UCondition::~UCondition()
{
}

void		UCondition::init()
{
  this->_cond = PTHREAD_COND_INITIALIZER;
}

void		UCondition::wait(pthread_mutex_t* mutex)
{
  int		rvalue;

  rvalue = pthread_cond_wait(&(this->_cond), mutex);
  if (rvalue != 0)
    throw ExceptionTrigger(errno, "pthread_cond_wait()");
}

void		UCondition::signal()
{
  int		rvalue;

  rvalue = pthread_cond_signal(&(this->_cond));
  if (rvalue != 0)
    throw ExceptionTrigger(errno, "pthread_cond_signal()");
}

void		UCondition::broadcast()
{
  int		rvalue;

  rvalue = pthread_cond_broadcast(&(this->_cond));
  if (rvalue != 0)
    throw ExceptionTrigger(errno, "pthread_cond_broadcoast()");
}
