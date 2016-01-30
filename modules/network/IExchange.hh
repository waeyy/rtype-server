//
// IExchange.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Tue Nov 24 17:55:43 2015 SOIDIKI Djamil
// Last update Mon Dec 21 15:30:14 2015 SOIDIKI Djamil
//

#ifndef		_IEXCHANGE_HH_
#define		_IEXCHANGE_HH_

#include	"../debug/Debug.hh"
#include	"Packet.hh"

namespace	Network {

  namespace	Exchange {

    class		IExchange
    {
      
    public:
      virtual	~IExchange() = default;
      
      virtual Packet	recv_(int socket) = 0;
      virtual int	send_(int socket, const Packet& packet) = 0;
      virtual Packet	recvfrom_(int socket) = 0;
      virtual int	sendto_(int socket, const Packet& packet) = 0;
      
    };
  }
}

#endif		/* _IEXCHANGE_HH_ */
