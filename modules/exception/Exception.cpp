//
// Exception.cpp for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/exception
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Fri Nov 20 01:20:17 2015 SOIDIKI Djamil
// Last update Sun Dec  6 13:25:55 2015 SOIDIKI Djamil
//

#include	"Exception.hh"

using namespace	Exception_;

Exception::Exception(int _errno, int line, 
		     const std::string& file, const std::string& msg)
{
  std::ostringstream    oss;
  
  oss << KRED;
  if (_errno)
    {
      oss << "[ERROR] (" << file << ":" << line << ")" << std::endl
          << msg << ": " << strerror(_errno);
    }
  else if (_errno == NO_ERRNO)
    {
      oss << "[ERROR] (" << file << ":" << line << ")" << std::endl
          << msg;
    }
  else
    oss << msg;
  oss << KNRM;
  this->_message = oss.str();
  std::cout << KNRM << std::endl;
}

Exception::~Exception() throw()
{
}

const char*     Exception::what() const throw()
{
  return (this->_message.c_str());
}

