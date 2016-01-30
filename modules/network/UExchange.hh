//
// UExchange.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Thu Nov 26 19:28:56 2015 SOIDIKI Djamil
// Last update Mon Dec 21 16:12:24 2015 SOIDIKI Djamil
//

#ifndef		_UEXCHANGE_HH_
# define	_UEXCHANGE_HH_

#include	<iostream>
#include	"IExchange.hh"
#include	"../exception/Exception.hh"

namespace	Network {

  namespace	Exchange {

    class	UExchange : public Network::Exchange::IExchange
    {
      
    public:
      UExchange();
      virtual ~UExchange();
      
      Packet	recv_(int socket);
      int	send_(int socket, const Packet& packet);
      Packet	recvfrom_(int socket);
      int	sendto_(int socket, const Packet& packet);
    };
  }
}

#endif		/* _UEXCHANGE_HH_ */
