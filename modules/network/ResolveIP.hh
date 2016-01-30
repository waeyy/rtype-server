//
// ResolveIP.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Thu Nov 26 18:05:13 2015 SOIDIKI Djamil
// Last update Sun Dec  6 13:53:56 2015 SOIDIKI Djamil
//

#ifndef		_RESOLVEIP_HH_
# define	_RESOLVEIP_HH_

#include	<iostream>
#include	<sstream>
#include	<netdb.h>
#include	"../debug/Debug.hh"

namespace	Network {

  class		ResolveIP
  {
  private:
    unsigned long	_addressNumeric;
    unsigned short	_portNumeric;
    
    std::string		_ip;
    std::string		_port;
    
  public:
    ResolveIP();
    
    /*
     * Constructor that initialize ResolveIP object
     *
     * @param		void
     * @return		unsigned long
     */
    ResolveIP(const sockaddr_in& address_src);
    
    /*
     * Destructor that destroy ResolveIP object
     *
     * @param		void
     * @return		unsigned long
     */
    ~ResolveIP();
    
    /*
     * Return numeric address
     *
     * @param		void
     * @return		unsigned long
     */
    unsigned long	getAddressNumeric() const;
    
    /*
     * Return numeric port
     *
     * @param		void
     * @return		unsigned short
     */
    unsigned short	getPortNumeric() const;
    
    /*
     * Return strinf format ip
     *
     * @param		void
     * @return		std::string
     */
    std::string		getIp() const;
    
    /*
     * Return string format port
     *
     * @param		void
     * @return		std::string
     */
    std::string		getPort() const;
    
    /*
     * Resolve ip address from numeric address
     *
     * @param		void
     * @return		void
     */
    void		resolve();
    
    /*
     * Return complete address of a machine (ip:port)
     *
     * @param		void
     * @return		std::string
     */
    std::string		getAddressMachine();
  };
}

#endif		/* _RESOLVEIP_HH_ */
  
