//
// UThread.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/thread
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sun Dec  6 16:45:23 2015 SOIDIKI Djamil
// Last update Fri Dec 11 19:12:01 2015 SOIDIKI Djamil
//

#ifndef		_UTHREAD_HH_
# define	_UTHREAD_HH_

#include	<iostream>
#include	<pthread.h>
#include	"../exception/Exception.hh"
#include	"IThread.hh"

namespace	Thread {

  enum		EThread {
    CREATED = 0,
    CANCELED = 1,
  };
    
  class		UThread : public Thread::IThread
  {

  private:
    int		_id;
    pthread_t	_thread;
    int		_state;

  public:
    UThread();
    UThread(int id);
    virtual ~UThread();

    void	create(void* (*start_routine)(void*), void* arg);
    void	join();
    void	cancel();

    int		getId() const;
  };
}

#endif		/* _UTHREAD_HH_ */
