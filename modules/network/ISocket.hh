//
// ISocket.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Thu Nov 19 22:01:20 2015 SOIDIKI Djamil
// Last update Tue Dec 22 13:11:04 2015 SOIDIKI Djamil
//

#ifndef		_ISOCKET_HH_
# define	_ISOCKET_HH_

namespace	Network {
  
  namespace	Socket {

    class		ISocket
    {
      
    public:
      /*
       * Virtual destructor for interface class
       *
       * @param	void
       * @return	void
     */
      virtual	~ISocket() = default;
      
    private:
      /*
       * Virtual function to socket depending on parameter
       *
       * @param	int	type (Type of socket udp or tcp)
       * @param	int	protocol (Protocol to use udp or tcp)
       * @return	void
       */
      virtual void	create_(int type, int protocol) = 0;
      
      /*
       * Virtual function to bind a socket
       * 
       * @param	void
       * @return	void
       */
      virtual void	bind_() = 0;
      
      /*
       * Virtual function to listen on a socket
       *
       * @param	void
       * @return	void
       */
      virtual void	listen_() = 0;
      
      /*
       * Virtual function to accept new connection from socket
       *
       * @param	void
       * @return	void
       */
      virtual int	accept_() = 0;
      
      /*
       * Virtual function to close a socket
       *
       * @param	void
       * @return	void
       */
      virtual void	close_() = 0;
    };  
  }
}
  
#endif		/* _ISOCKET_HH_*/
