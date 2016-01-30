//
// ICondition.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/thread
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sun Dec  6 19:48:49 2015 SOIDIKI Djamil
// Last update Sun Dec  6 20:39:22 2015 SOIDIKI Djamil
//

#ifndef		_ICONDITION_HH_
# define	_ICONDITION_HH_

#include	<iostream>
#include	<pthread.h>

namespace	Thread {

  namespace	Condition {

    class	ICondition {
      
    public:
      virtual ~ICondition() = default;

      virtual void	init() = 0;
      virtual void	wait(pthread_mutex_t* mutex) = 0;
      virtual void	signal() = 0;
      virtual void	broadcast() = 0;
    };
  }
}

#endif		/* _ICONDITION_HH_ */
