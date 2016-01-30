//
// NetworkHandler.cpp for  in /home/soidik_d/Semestre_05/cpp/rtype/sources
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Mon Dec 21 14:38:35 2015 SOIDIKI Djamil
// Last update Sat Jan  2 17:27:24 2016 SOIDIKI Djamil
//

#include	"../includes/NetworkHandler.hh"
#include	"../includes/Server.hh"
#include	"../includes/Client.hh"
#include	"../modules/network/ResolveIP.hh"
#include	"../modules/network/Packet.hh"
#include	"../modules/protocol/Protocol.hh"

using namespace	Network;
using namespace GNProtocol;

void*		routineConnection(void* arg)
{  
  Exchange::UExchange	talk;
  Server*		server = 
    reinterpret_cast<Server*>(arg);
  
  while (true)
    {
      int fd = server->getNetwork().getSocketConnection()->accept_();
      Packet packet = talk.recv_(fd);

      if (Protocol::tryConnection(server->getClients(),
      				  packet.getData()) == true)
	{
	  ResolveIP infosClient(server->getNetwork().getSocketConnection()
				->getAddressFrom());
	  
	  Client*	client = new Client(server->getClients().size() + 1, 
					    infosClient.getIp(), 
					    infosClient.getPortNumeric(),
					    fd);
	  server->getClients().push_back(client);
	  
	  packet.setData("JARVIS: Bravo ! Tu es connecté, amuse toi bien\n");
	  talk.send_(fd, packet);
	}
      else
	{
	  packet.setData("JARVIS: Authentification refusé\n");
	  talk.send_(fd, packet);
	  close(fd);
	}
    }
  return (NULL);  
}

void*		routineData(void* arg)
{
  Exchange::UExchange	talk;
  Server*		server = 
    reinterpret_cast<Server*>(arg);

  Network::Packet	packet;

  while (true)
    {
      packet = talk.recvfrom_(server->getNetwork().getSocketData()
			      ->getSocket());
      if (Protocol::isConnected(server->getClients(),
				packet.getResolverAddress().getIp()) == true)
	{
	  server->getPool()->enqueue(packet);
	  if (strcmp(packet.getData().c_str(), "disconnect\n") == 0)
	    {
	      Protocol::disconnect(server->getClients(),
				   packet.getResolverAddress().getIp());
	    }
	  packet.setData("JARVIS: Message traité avec succès\n");
	  talk.sendto_(server->getNetwork().getSocketData()
		       ->getSocket(), packet);
	}
      else
	{
	  packet.setData("JARVIS: Vous n'êtes pas connecté\n");
	  talk.sendto_(server->getNetwork().getSocketData()
		      ->getSocket(), packet);
	}
    }
  return (NULL);
}

void*		routineTimer(void* arg)
{
  Server*		server = 
    reinterpret_cast<Server*>(arg);

  (void) server;
  while (true)
    {
      if (std::chrono::system_clock::now() > server->getNetwork().getTimer())
	{
	  
	}
    }
  return (NULL);
}

NetworkHandler::NetworkHandler() :
  _socketConnection(new Socket::USocket(IP_ADDR, 
					PORT_CONNECTION, SOCK_STREAM, 0)),
  _socketData(new Socket::USocket(IP_ADDR, PORT_DATA, SOCK_DGRAM, 0)),
  _timer(std::chrono::system_clock::now() + std::chrono::seconds(10))
{
}

NetworkHandler::~NetworkHandler()
{
  this->_threadConnection.join();
  this->_threadData.join();
  this->_threadTimer.join();
}

void		NetworkHandler::run(Server* server)
{
  this->_threadData.create(&routineData, 
			   static_cast<void*>(server));
  this->_threadConnection.create(&routineConnection, 
				 static_cast<void*>(server));
  this->_threadTimer.create(&routineTimer,
			    static_cast<void*>(server));
}

Socket::USocket*	NetworkHandler::getSocketConnection()
{
  return (this->_socketConnection);
}

Socket::USocket*	NetworkHandler::getSocketData()
{
  return (this->_socketData);
}

time_point_t		NetworkHandler::getTimer() const
{
  return (this->_timer);
}
