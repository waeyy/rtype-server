//
// Packet.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Thu Nov 26 19:56:16 2015 SOIDIKI Djamil
// Last update Wed Dec 23 17:29:59 2015 SOIDIKI Djamil
//

#ifndef		_PACKET_HH_
# define	_PACKET_HH_

#include	<netdb.h>
#include	"../debug/Debug.hh"
#include	"ResolveIP.hh"

namespace	Network {

  class		Packet
  {
    
  private:
    ResolveIP		_resolverAddress;
    std::string		_data;
    int			_bytes;
    
  public:
    Packet();
    Packet(const sockaddr_in& address_src, const char* data, const int bytes);
    ~Packet();

    void		setData(const std::string& data);
    
    ResolveIP		getResolverAddress() const;
    std::string		getData() const;
    int			getBytes() const;
    
    Packet&	operator=(const Packet& packet);
  };
}

#endif		/* _PACKET_HH_ */
