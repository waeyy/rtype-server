//
// Server.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/includes
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Mon Dec  7 00:34:56 2015 SOIDIKI Djamil
// Last update Sun Jan  3 13:24:40 2016 SOIDIKI Djamil
//

#ifndef		_SERVER_HH_
# define	_SERVER_HH_

#include	<iostream>
#include	<vector>
#include	"NetworkHandler.hh"
#include	"Client.hh"
#include	"../modules/thread/Pool.hh"

#define		MAX_WORKERS		16

class		Server {

private:
  std::vector<Client*>		_clients;
  NetworkHandler		_network;
  Thread::Pattern::Pool*	_pool;

public:
  Server();
  ~Server();

  void				run();

  std::vector<Client*>&		getClients();
  NetworkHandler&		getNetwork();
  Thread::Pattern::Pool*	getPool();
};

#endif		/* _SERVER_HH_ */
