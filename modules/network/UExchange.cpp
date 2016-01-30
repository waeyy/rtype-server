//
// UExchange.cpp for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Thu Nov 26 19:42:41 2015 SOIDIKI Djamil
// Last update Thu Dec 24 01:30:26 2015 SOIDIKI Djamil
//

#include	"UExchange.hh"

using namespace	Network;
using namespace	Network::Exchange;

UExchange::UExchange()
{
  DEBUG_FILE_FUNC_INFO();
}

UExchange::~UExchange()
{
  DEBUG_FILE_FUNC_INFO();
}

Packet		UExchange::recv_(int socket)
{
  DEBUG_FILE_FUNC_INFO();
  DEBUG_DISABLE();

  Packet	_packet;
  int		bytes;
  char		data[256];
  sockaddr_in	address_src;
  socklen_t	size_address_src = sizeof(address_src);
  
  (void) address_src;
  (void) size_address_src;

  memset(data, 0, sizeof(data));
  bytes = recv(socket, (char*) data, sizeof(data), 0);
  
  std::cout << "bytes lu: " << bytes << std::endl;
  if (bytes > 0)
    {
      DEBUG_ENABLE();

      std::ostringstream        oss;
      std::string   res;

      oss << data;
      _packet = Packet(address_src, oss.str().c_str(), oss.str().size());
      
      oss.str("");
      
      res = _packet.getData();
      res = res.substr(0, bytes - 1);

      oss << "nb bytes: " << _packet.getBytes();
      DEBUG_MSG(oss.str().c_str()); oss.str("");
      oss << "data: " << res;
      DEBUG_MSG(oss.str()); oss.str("");
      oss << "complete address: " 
	  << _packet.getResolverAddress().getAddressMachine();
      DEBUG_MSG(oss.str().c_str()); oss.str("");
      //      this->send_(socket, _packet);
    }
  return (_packet);
}

int		UExchange::send_(int socket, const Packet& packet)
{
  DEBUG_FILE_FUNC_INFO();

  int		sent_bytes;
    
  sent_bytes = send(socket, 
		    (const char*) packet.getData().c_str(), 
		    packet.getData().size(), 0);

  std::ostringstream        oss;
  std::string   res;
  
  res = packet.getData();
  res = res.substr(0, packet.getBytes() - 1);

  oss << "nb bytes: " << packet.getBytes();
  DEBUG_MSG(oss.str().c_str()); oss.str("");
  oss << "data: " << res;
  DEBUG_MSG(oss.str()); oss.str("");
  oss << "complete address: " 
      << packet.getResolverAddress().getAddressMachine();
  DEBUG_MSG(oss.str().c_str()); oss.str("");
  
  return (sent_bytes);
}

Packet		UExchange::recvfrom_(int socket)
{
  DEBUG_FILE_FUNC_INFO();
  DEBUG_DISABLE();

  Packet	_packet;
  int		bytes;
  char		data[256];
  sockaddr_in	address_src;
  socklen_t	size_address_src = sizeof(address_src);
  
  memset(data, 0, sizeof(data));
  bytes = recvfrom(socket, (char*) data,
		   sizeof(data), 0, 
		   (sockaddr*)&address_src, &size_address_src);
  
  if (bytes > 0)
    {
      DEBUG_ENABLE();

      std::ostringstream        oss;
      std::string   res;

      oss << data;
      _packet = Packet(address_src, oss.str().c_str(), oss.str().size());
      
      oss.str("");
      
      res = _packet.getData();
      res = res.substr(0, bytes - 1);

      oss << "nb bytes: " << _packet.getBytes();
      DEBUG_MSG(oss.str().c_str()); oss.str("");
      oss << "data: " << res;
      DEBUG_MSG(oss.str()); oss.str("");
      oss << "complete address: " 
	  << _packet.getResolverAddress().getAddressMachine();
      DEBUG_MSG(oss.str().c_str()); oss.str("");
      // _packet.setData("JARVIS: Message traité avec succès !\n");
      // this->sendto_(socket, _packet);
    }
  return (_packet);
}

int		UExchange::sendto_(int socket, const Packet& packet)
{
  DEBUG_FILE_FUNC_INFO();

  sockaddr_in	addr;
  int		sent_bytes;

  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(packet.
			       getResolverAddress().
			       getAddressNumeric());
  addr.sin_port = htons(packet.getResolverAddress().getPortNumeric());
    
  sent_bytes = sendto(socket, 
		      (const char*) packet.getData().c_str(), 
		      packet.getData().size(), 0,
		      (sockaddr*)&addr, sizeof(addr));

  std::ostringstream        oss;
  std::string   res;
  
  res = packet.getData();
  res = res.substr(0, packet.getBytes() - 1);

  oss << "nb bytes: " << packet.getBytes();
  DEBUG_MSG(oss.str().c_str()); oss.str("");
  oss << "data: " << res;
  DEBUG_MSG(oss.str()); oss.str("");
  oss << "complete address: " 
      << packet.getResolverAddress().getAddressMachine();
  DEBUG_MSG(oss.str().c_str()); oss.str("");
  
  return (sent_bytes);
}
