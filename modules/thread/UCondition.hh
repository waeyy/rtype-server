//
// UCondition.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/thread
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sun Dec  6 19:53:38 2015 SOIDIKI Djamil
// Last update Sun Dec  6 20:39:17 2015 SOIDIKI Djamil
//

#ifndef		_UCONDITION_HH_
# define	_UCONDITION_HH_

#include	<iostream>
#include	<pthread.h>
#include	"ICondition.hh"
#include	"../exception/Exception.hh"

namespace	Thread {

  namespace	Condition {

    class	UCondition : public Thread::Condition::ICondition {
      
    private:
      pthread_cond_t	_cond;

    public:
      UCondition();
      virtual ~UCondition();

      void	init();
      void	wait(pthread_mutex_t* mutex);
      void	signal();
      void	broadcast();
    };
  }
}

#endif		/* _UCONDITION_HH_ */
