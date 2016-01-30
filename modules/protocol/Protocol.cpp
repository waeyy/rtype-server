//
// Protocol.cpp for  in /home/soidik_d/Semestre_05/cpp/rtype/modules/protocol
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Wed Dec 23 17:48:46 2015 SOIDIKI Djamil
// Last update Sat Jan  2 16:57:53 2016 SOIDIKI Djamil
//

#include	"Protocol.hh"
#include	<cstring>

using namespace	GNProtocol;

bool		Protocol::tryConnection(std::vector<Client*>& clients,
					std::string command)
{
  std::vector<Client*>::iterator	it = clients.begin();

  (void) it;
  (void) clients;
  if (strcmp(command.c_str(), "connect\n") == 0)
    return (true);
  return (false);
}

bool		Protocol::isConnected(std::vector<Client*>& clients,
				      std::string address)
{
  for (std::vector<Client*>::iterator it = clients.begin();
       it != clients.end(); it++)
    {
      if (strcmp((*it)->getAddress().c_str(), address.c_str()) == 0)
	return (true);
    }
  return (false);
}

bool		Protocol::disconnect(std::vector<Client*>& clients,
				     std::string address)
{
  for (std::vector<Client*>::iterator it = clients.begin();
       it != clients.end(); it++)
    {
      if (strcmp((*it)->getAddress().c_str(), address.c_str()) == 0)
	{
	  close((*it)->getFd());
	  clients.erase(it);
	  return (true);
	}  
    }
  return (false);
}
