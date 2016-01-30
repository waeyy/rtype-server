//
// Packet.cpp for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Thu Nov 26 20:04:41 2015 SOIDIKI Djamil
// Last update Wed Dec 23 17:30:35 2015 SOIDIKI Djamil
//

#include	"Packet.hh"

using namespace	Network;

Packet::Packet()
{
  DEBUG_FILE_FUNC_INFO();
}

Packet::Packet(const sockaddr_in& address_src, 
	       const char* data, const int bytes) :
  _resolverAddress(address_src), _data(data), _bytes(bytes)
{
  DEBUG_FILE_FUNC_INFO();
  
  this->_data = data;
  this->_data = this->_data.substr(0, bytes - 1);
  this->_data = this->_data + "\n";
}

Packet::~Packet()
{
  DEBUG_FILE_FUNC_INFO();
}

void		Packet::setData(const std::string& data)
{
  this->_data = data;
}

ResolveIP	Packet::getResolverAddress() const
{
  //  DEBUG_FILE_FUNC_INFO();
  return (this->_resolverAddress);
}

std::string	Packet::getData() const
{
  DEBUG_FILE_FUNC_INFO();
  return (this->_data);
}

int		Packet::getBytes() const
{
  DEBUG_FILE_FUNC_INFO();
  return (this->_bytes);
}

Packet&		Packet::operator=(const Packet& packet)
{
  DEBUG_FILE_FUNC_INFO();
  this->_resolverAddress = packet.getResolverAddress();
  this->_data = packet._data;
  this->_bytes = packet._bytes;
  return (*this);
}
