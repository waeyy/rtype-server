//
// Client.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/includes
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Tue Dec 22 12:05:36 2015 SOIDIKI Djamil
// Last update Thu Dec 24 01:11:57 2015 SOIDIKI Djamil
//

#ifndef		_CLIENT_HH_
# define	_CLIENT_HH_

#include	<iostream>

class		Client {

private:
  int		_id;
  std::string	_address;
  int		_port;
  int		_fd;
  
public:
  Client();
  Client(int id, std::string address, int port, int fd);
  ~Client();

  int		getId() const;
  std::string	getAddress() const;
  int		getPort() const;
  int		getFd() const;
};

#endif		/* _CLIENT_HH_ */
