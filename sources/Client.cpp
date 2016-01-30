//
// Client.cpp for  in /home/soidik_d/Semestre_05/cpp/rtype/sources
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Tue Dec 22 12:14:27 2015 SOIDIKI Djamil
// Last update Thu Dec 24 01:13:47 2015 SOIDIKI Djamil
//

#include	"../includes/Client.hh"

Client::Client() : _id(-1), _address("0.0.0.0"), _port(0), _fd(-1)
{
}

Client::Client(int id, std::string address, int port, int fd) :
  _id(id), _address(address), _port(port), _fd(fd)
{
}

Client::~Client()
{
}

int		Client::getId() const
{
  return (this->_id);
}

std::string	Client::getAddress() const
{
  return (this->_address);
}

int		Client::getPort() const
{
  return (this->_port);
}

int		Client::getFd() const
{
  return (this->_fd);
}
