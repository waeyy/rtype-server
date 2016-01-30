//
// Controller.cpp for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Mon Dec  7 01:06:41 2015 SOIDIKI Djamil
// Last update Mon Dec  7 01:36:50 2015 SOIDIKI Djamil
//

#include	"Controller.hh"

Controller::Controller(int port, int type, int protocol)
{
  this->_serv = new Network::Socket::USocket("127.0.0.1", 
					     port,
					     type,
					     protocol);
  this->_thread = new Thread::UThread();
  this->_thread->create(&routine, static_cast<void*>(this->_serv));
}

Controller::~Controller()
{
  this->_thread.join();
}

Socket::USocket*	Controller::getSocket() const
{
  return (this->_socket);
}

Thread::UThread*	Controller::getThread() const
{
  return (this->_thread);
}
