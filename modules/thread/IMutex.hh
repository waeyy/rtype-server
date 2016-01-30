//
// IMutex.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/thread
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sun Dec  6 17:37:04 2015 SOIDIKI Djamil
// Last update Sun Dec  6 19:51:22 2015 SOIDIKI Djamil
//

#ifndef		_IMUTEX_HH_
# define	_IMUTEX_HH_

#include	<iostream>

namespace	Thread {
  
  namespace	Mutex {
  
    class	IMutex {

    public:
      virtual ~IMutex() = default;
      
      virtual void	init() = 0;
      virtual void	lock() = 0;
      virtual void	unlock() = 0;
    };
  }
}

#endif		/* _IMUTEX_HH_ */
