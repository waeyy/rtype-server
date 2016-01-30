//
// NetworkHandler.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/includes
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Mon Dec 21 14:34:25 2015 SOIDIKI Djamil
// Last update Fri Dec 25 15:31:24 2015 SOIDIKI Djamil
//

#ifndef		_NETWORKHANDLER_HH_
# define	_NETWORKHANDLER_HH_

#define		IP_ADDR		"127.0.0.1"
#define		PORT_CONNECTION	1338
#define		PORT_DATA	1337

#include	<numeric>
#include	<chrono>
#include	"../modules/thread/UThread.hh"
#include	"../modules/network/USocket.hh"
#include	"../modules/network/UExchange.hh"

class		Server;

using namespace	Network;

typedef	std::chrono::_V2::system_clock::time_point time_point_t;

class		NetworkHandler {
  
private:
  Socket::USocket*	_socketConnection;
  Socket::USocket*	_socketData;
  Thread::UThread	_threadConnection;
  Thread::UThread	_threadData;
  time_point_t		_timer;
  Thread::UThread	_threadTimer;

public:
  NetworkHandler();
  ~NetworkHandler();

  void		run(Server* server);

  Socket::USocket*	getSocketConnection();
  Socket::USocket*	getSocketData();
  time_point_t		getTimer() const;
};

#endif		/* _NETWORKHANDLER_HH_ */
