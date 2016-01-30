//
// Exception.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/exception
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Fri Nov 20 01:03:24 2015 SOIDIKI Djamil
// Last update Sun Dec  6 13:34:09 2015 SOIDIKI Djamil
//

#ifndef         _EXCEPTION_HH_
# define        _EXCEPTION_HH_

#include        <iostream>
#include        <sstream>
#include        <exception>
#include        <cerrno>
#include        <cstring>

#define		ExceptionTrigger(a, b)	Exception_::Exception(a, __LINE__, __FILE__, b)

#define         USAGE_ERROR     0
#define         CLASSIC_ERROR   1
#define         NO_ERRNO        -42

#define		KNRM	"\x1B[0m"
#define		KRED	"\x1B[31m"

namespace	Exception_ {

  /*
   * Exception class which inherits of std::exception.
   * Provide a personnal handler exception
   * 
   * To use it just include this file.
   *
   * Example to throw an exception:
   * throw ExceptionTrigger(errno, "custom msg");
   *
   * @class Exception
   */
  class           Exception : public std::exception 
  {
    
  protected:
    std::string	_message;
    
  public:
    /*
     * Constructor of the Exception class
     * 
     * @param	int errno 
     * @param	int line of the caught exception
     * @param	const std::string& filename  
     * @param	const std::string& a custom message actually name function
     * @return	void
     */
    Exception(int _errno, int line, 
	      const std::string& file, const std::string& msg);

    /*
     * Virtual destructor of the Exception class
     * 
     * @param	void
     * @return	void
     */
    virtual ~Exception() throw();
    
    /*
     * Provide information about the current caught exception
     * 
     * @param	void
     * @return	const char* information
     */
    virtual const char * what() const throw();
  };
}

#endif          /* _EXCEPTION_HH_ */
