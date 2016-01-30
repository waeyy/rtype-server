//
// Pool.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/thread
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sun Dec  6 18:58:27 2015 SOIDIKI Djamil
// Last update Sat Jan  2 17:56:02 2016 SOIDIKI Djamil
//

#ifndef		_POOL_HH_
# define	_POOL_HH_

#include	<iostream>
#include	<queue>
#include	<vector>
#include	"UThread.hh"
#include	"UMutex.hh"
#include	"UCondition.hh"
#include	"../network/Packet.hh"

class		Server;

using namespace Network;

namespace	Thread {

  namespace	Pattern {

    enum	EPool {
      RUNNING = 0,
      STOP = 1,
    };
    
    typedef Thread::Mutex::UMutex		Mutex;
    typedef Thread::Condition::UCondition	Condition;
    
    class	Pool {
      
    private:
      int					_state;
      std::vector<Thread::UThread>		_workers;
      std::queue<Packet>			_tasks;
      Mutex					_mutex;
      Condition					_condition;
      Server*					_server;

    public:
      Pool(int threads, Server* server);
      ~Pool();
      
      void	enqueue(Packet task);
      void*	routine(void* arg);
    };
  }
}

#endif		/* _POOL_HH_ */
