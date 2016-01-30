//
// Server.cpp for  in /home/soidik_d/Semestre_05/cpp/rtype/sources
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Mon Dec 21 16:22:10 2015 SOIDIKI Djamil
// Last update Sun Jan  3 13:13:45 2016 SOIDIKI Djamil
//

#include	"../includes/Server.hh"

Server::Server() : _pool(new Thread::Pattern::Pool(MAX_WORKERS, this))
{
}

Server::~Server()
{
}

void			Server::run()
{
  this->_network.run(this);
}

std::vector<Client*>&	Server::getClients()
{
  return (this->_clients);
}

NetworkHandler&		Server::getNetwork()
{
  return (this->_network);
}

Thread::Pattern::Pool*	Server::getPool()
{
  return (this->_pool);
}
