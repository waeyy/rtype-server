//
// Controller.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Mon Dec  7 00:53:50 2015 SOIDIKI Djamil
// Last update Mon Dec  7 01:40:45 2015 SOIDIKI Djamil
//

#ifndef         _CONTROLLER_HH_
# define        _CONTROLLER_HH_

#include        "../thread/IThread.hh"
#include        "ISocket.hh"

namespace	Network {

  class		Controller {
    
  private:
    Socket::USocket*	_socket;
    Thread::UThread*	_thread;
   
  public:
    Controller(int port, int type, int protocol);
    ~Controller();
        
    Socket::USocket*	getSocket() const;
    Thread::UThread*	getThread() const;
    
    void		combine();
  };
}

#endif          /* _CONTROLLER_HH_ */
