//
// IThread.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/thread
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sun Dec  6 16:32:02 2015 SOIDIKI Djamil
// Last update Sun Dec  6 17:04:40 2015 SOIDIKI Djamil
//

#ifndef		_ITHREAD_HH_
# define	_ITHREAD_HH_

#include	<iostream>

namespace	Thread {

  class		IThread {
    
  public:
    virtual ~IThread() = default;

    virtual void	create(void* (*start_routine)(void*), void* arg) = 0;
    virtual void	join() = 0;
    virtual void	cancel() = 0;
  };
}

#endif		/* _ITHREAD_HH_ */
