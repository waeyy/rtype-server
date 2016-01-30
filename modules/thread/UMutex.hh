//
// UMutex.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/thread
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sun Dec  6 17:41:36 2015 SOIDIKI Djamil
// Last update Sun Dec  6 22:51:09 2015 SOIDIKI Djamil
//

#ifndef		_UMUTEX_HH_
# define	_UMUTEX_HH_

#include	<iostream>
#include	<pthread.h>
#include	"IMutex.hh"
#include	"../exception/Exception.hh"

namespace	Thread {

  namespace	Mutex {
    
    class		UMutex : public Thread::Mutex::IMutex {
      
    private:
      pthread_mutex_t	_mutex;
      
    public:
      UMutex();
      virtual ~UMutex();

      void		init();
      void		lock();
      void		unlock();

      pthread_mutex_t*	getMutex();
    };
  }
}

#endif		/* _UMUTEX_HH_ */
