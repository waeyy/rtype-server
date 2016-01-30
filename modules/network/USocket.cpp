//
// USocket.cpp for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Tue Nov 24 17:16:50 2015 SOIDIKI Djamil
// Last update Tue Dec 22 13:10:31 2015 SOIDIKI Djamil
//

#include	"USocket.hh"

using namespace Network::Socket;

USocket::USocket(const std::string& address, int port, 
		 int type, int protocol) : 
  _address(address), _port(port)
{
  DEBUG_FILE_FUNC_INFO();
  this->create_(type, protocol);
  this->bind_();
  
  if (type == SOCK_STREAM)
    this->listen_();
}

USocket::~USocket()
{
  DEBUG_FILE_FUNC_INFO();
}

void		USocket::create_(int type, int protocol)
{
  this->_socket = socket(AF_INET, type, protocol);
  
  if (this->_socket <= 0)
    throw ExceptionTrigger(errno, "socket()");
}

void		USocket::bind_()
{
  int		error;

  this->_address_in.sin_family = AF_INET;
  this->_address_in.sin_addr.s_addr = INADDR_ANY;
  this->_address_in.sin_port = htons((unsigned short) this->_port);

  error = bind(this->_socket,
               (const sockaddr*) &this->_address_in, sizeof(sockaddr_in));
  if (error < 0)
    throw ExceptionTrigger(errno, "bind()");
}

void		USocket::listen_()
{
  int		error;
  
  error = listen(this->_socket, 5);
  if (error < 0)
    throw ExceptionTrigger(errno, "listen()");
}

int		USocket::accept_()
{
  int		ret;
  int		size;

  ret = accept(this->_socket, 
		 ((struct sockaddr*) &(this->_address_from)),
		 (socklen_t*) &size);

  if (ret == -1)
    throw ExceptionTrigger(errno, "accept()");
  std::cout << "New connection" << std::endl;

  return (ret);
}

void		USocket::close_()
{
  close(this->_socket);
}

// void		USocket::init()
// {
//   DEBUG_FILE_FUNC_INFO();
//   int		error;

//   DEBUG_MSG("Creating socket..");
//   //  this->_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
//   this->_socket = socket(AF_INET, SOCK_STREAM, 0);
  
//   if (this->_socket <= 0)
//     throw Exception(NO_ERRNO, __LINE__, __FILE__, "socket()");
//   DEBUG_MSG("Socket created successfully.");
  
//   this->_address_in.sin_family = AF_INET;
//   this->_address_in.sin_addr.s_addr = INADDR_ANY;
//   this->_address_in.sin_port = htons((unsigned short) this->_port);

//   DEBUG_MSG("Binding socket to address..");
//   error = bind(this->_socket, 
// 	       (const sockaddr*) &this->_address_in, sizeof(sockaddr_in)); 
//   if (error < 0)
//     throw Exception(NO_ERRNO, __LINE__, __FILE__, "bind()");
//   DEBUG_MSG("Socket binded successfully.");
//   //  this->setNonBlockingMode();
//   DEBUG_MSG("Socket ready to send and receive data.");
// }

// void		USocket::setNonBlockingMode()
// {
//   DEBUG_FILE_FUNC_INFO();

//   int		non_blocking = 1;
//   int		error;
  
//   DEBUG_MSG("Setting non-blocking mode to the socket..");
//   error = fcntl(this->_socket, F_SETFL, O_NONBLOCK, non_blocking);
//   if (error == -1)
//     throw Exception(NO_ERRNO, __LINE__, __FILE__, 
// 		    "failed to set non-blocking mode");
//   DEBUG_MSG("Non-blocking mode setted.");
// }

// void		USocket::run()
// {
//   DEBUG_FILE_FUNC_INFO(); 
// }

void		USocket::closeSocket()
{
  DEBUG_FILE_FUNC_INFO();
  close(this->_socket);
}

int		USocket::getSocket() const
{
  DEBUG_FILE_FUNC_INFO();
  return (this->_socket);
}

std::string	USocket::getAddress() const
{
  DEBUG_FILE_FUNC_INFO();
  return (this->_address);
}

int		USocket::getPort() const
{
  DEBUG_FILE_FUNC_INFO();
  return (this->_port);
}

sockaddr_in	USocket::getAddressIn() const
{
  return (this->_address_in);
}

sockaddr_in	USocket::getAddressFrom() const
{
  return (this->_address_from);
}
