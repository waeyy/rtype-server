//
// UThread.cpp for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/thread
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sun Dec  6 16:51:37 2015 SOIDIKI Djamil
// Last update Fri Dec 11 19:11:50 2015 SOIDIKI Djamil
//

#include	"UThread.hh"

using namespace	Thread;

UThread::UThread() : _state(CANCELED)
{
}

UThread::UThread(int id) : _id(id), _state(CANCELED)
{
}

UThread::~UThread()
{
}

void		UThread::create(void* (*start_routine)(void*), void* arg)
{
  int		rvalue;

  rvalue = pthread_create(&(this->_thread), NULL, start_routine, arg);
  if (rvalue != 0)
    throw ExceptionTrigger(errno, "pthread_create()");
  this->_state = CREATED;
}

void		UThread::join()
{
  int		rvalue;
 
  if (this->_state == CREATED)
    {
      rvalue = pthread_join(this->_thread, NULL);
      if (rvalue != 0)
	throw ExceptionTrigger(errno, "pthread_join()");
    }
  else
    throw ExceptionTrigger(NO_ERRNO, "thread seems non-initialized");
}

void		UThread::cancel()
{
  int		rvalue;

  if (this->_state == CREATED)
    {
      rvalue = pthread_cancel(this->_thread);
      if (rvalue != 0)
	throw ExceptionTrigger(errno, "pthread_cancel()");
      this->_state = CANCELED;
    }
  else
    throw ExceptionTrigger(NO_ERRNO, "thread seems non-initialized");
}

int		UThread::getId() const
{
  return (this->_id);
}
