//
// Protocol.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/modules/protocol
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Wed Dec 23 17:40:31 2015 SOIDIKI Djamil
// Last update Sat Jan  2 16:58:23 2016 SOIDIKI Djamil
//

#ifndef		_PROTOCOL_HH_
# define	_PROTOCOL_HH_

#include	<iostream>
#include	<vector>
#include	<unistd.h>
#include	"../../includes/Client.hh"

namespace	GNProtocol {

  class		Protocol {

  public:
    static bool	tryConnection(std::vector<Client*>& clients, 
			      std::string command);
    
    static bool	isConnected(std::vector<Client*>& clients,
			    std::string address);
    static bool	disconnect(std::vector<Client*>& clients,
			   std::string command);
  };
}

#endif		/* _PROTOCOL_HH_ */
