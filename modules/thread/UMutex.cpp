//
// UMutex.cpp for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/thread
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sun Dec  6 17:46:48 2015 SOIDIKI Djamil
// Last update Sun Dec  6 22:51:06 2015 SOIDIKI Djamil
//

#include	"UMutex.hh"

using namespace	Thread::Mutex;

UMutex::UMutex()
{
}

UMutex::~UMutex()
{
}

void		UMutex::init()
{
  this->_mutex = PTHREAD_MUTEX_INITIALIZER;
}

void		UMutex::lock()
{
  int		rvalue;
  
  rvalue = pthread_mutex_lock(&(this->_mutex));
  if (rvalue != 0)
    throw ExceptionTrigger(errno, "pthread_mutex_lock()");
}

void		UMutex::unlock()
{
  int		rvalue;
  
  rvalue = pthread_mutex_unlock(&(this->_mutex));
  if (rvalue != 0)
    throw ExceptionTrigger(errno, "pthread_mutex_unlock()");
}

pthread_mutex_t* UMutex::getMutex()
{
  return (&(this->_mutex));
}
