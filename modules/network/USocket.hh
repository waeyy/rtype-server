//
// USocket.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Thu Nov 19 22:18:27 2015 SOIDIKI Djamil
// Last update Tue Dec 22 13:10:49 2015 SOIDIKI Djamil
//

#ifndef		_USOCKET_HH_
# define	_USOCKET_HH_

#include	<iostream>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netdb.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	"ISocket.hh"
#include	"IExchange.hh"
#include	"../debug/Debug.hh"
#include	"../exception/Exception.hh"
#include	"ResolveIP.hh"

namespace	Network {

  namespace	Socket {

    class		USocket : public Network::Socket::ISocket
    {
      
    private:
      int			_socket;
      std::string		_address;
      int			_port;
      sockaddr_in		_address_in;
      sockaddr_in		_address_from;

    public:
      /*
       * Constructor that initialize USocket object 
       * 
       * @param		const std::string&	address
       * @param		int			port
       * @return		void
       */
      USocket(const std::string& address, int port, int type, int protocol);
      
      /*
       * Destructor that destroy USocket object 
       * 
       * @param		void
       * @return		void
       */
      virtual ~USocket();
      
    private:
      /*
       * Initialize and create udp socket and bind the socket to a port number
       * 
       * @param		void
       * @return		void
       */
      void			create_(int type, int protocol);
      void			bind_();
      
    public:
      void			listen_();
      int			accept_();
      void			close_();
      /*
       * Virtual setter to set the socket as non-blocking mode
       *
       * @param     void
       * @return    void
       */
      //    void			setNonBlockingMode();
      
    public:
      /*
       * Close the socket
       * 
       * @param		void
       * @return		void
       */
      void			closeSocket();
      
      /* ----------- GETTERS ----------- */
      
      /*
       * Return socket of the object
       *
       * @param		void
       * @return		int
       */
      int			getSocket() const;
      
      /*
       * Return the server's port
       *
       * @param		void
       * @return		int
       */
      int			getPort() const;
    
      /*
       * Return the server's address
       *
       * @param		void
       * @return		std::string
       */
      std::string		getAddress() const;

      sockaddr_in		getAddressIn() const;
      sockaddr_in		getAddressFrom() const;

    private:
      USocket(const USocket& sock);
      USocket& operator=(const USocket& sock);
    };
  }
}

#endif		/* _USOCKET_HH_ */
  
