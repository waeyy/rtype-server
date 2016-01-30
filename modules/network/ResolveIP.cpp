//
// ResolveIP.cpp for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Thu Nov 26 18:18:01 2015 SOIDIKI Djamil
// Last update Fri Dec 11 18:39:30 2015 SOIDIKI Djamil
//

#include	"ResolveIP.hh"

using namespace	Network;

ResolveIP::ResolveIP()
{
}

ResolveIP::ResolveIP(const sockaddr_in& address_src) :
  _addressNumeric(ntohl(address_src.sin_addr.s_addr)), 
  _portNumeric(ntohs(address_src.sin_port))
{  
  std::ostringstream	res;
  
  res << this->_portNumeric;
  this->_port = res.str();
  this->resolve();
}

ResolveIP::~ResolveIP()
{
}

unsigned long	ResolveIP::getAddressNumeric() const
{
  return (this->_addressNumeric);
}

unsigned short	ResolveIP::getPortNumeric() const
{
  return (this->_portNumeric);
}

std::string	ResolveIP::getIp() const
{
  return (this->_ip);
}

std::string	ResolveIP::getPort() const
{
  return (this->_port);
}

void		ResolveIP::resolve()
{
  std::ostringstream	address;
  
  unsigned char a = (unsigned char) (this->_addressNumeric >> 24);
  unsigned char b = (unsigned char) (this->_addressNumeric >> 16);
  unsigned char c = (unsigned char) (this->_addressNumeric >> 8);
  unsigned char d = (unsigned char) (this->_addressNumeric);

  address << (int) a << "." << (int) b << "." << (int) c << ".\
" << (int) d;

  this->_ip = address.str();
}

std::string	ResolveIP::getAddressMachine()
{
  std::ostringstream	address;
  
  address << this->_ip << ":" << this->_port;
  return (address.str());
}
