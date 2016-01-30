//
// Debug.cpp for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/debug
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Thu Nov 19 17:18:22 2015 SOIDIKI Djamil
// Last update Fri Dec 11 18:52:35 2015 SOIDIKI Djamil
//

#include	"Debug.hh"

using namespace	Debugger;

bool            Debug::_enabled = false;

void		Debug::enable()
{
  _enabled = true;
  Debug::title("THE DEBUG TOOLS IS ENABLE", KYEL);
}

void		Debug::disable()
{
  Debug::title("THE DEBUG TOOLS IS DISABLE", KYEL);
  _enabled = false;
}

void		Debug::ffinfo(const std::string& file, const std::string& func)
{
  if (isEnable())
    {
      Debug::title("INFORMATIONS", KCYN);

      std::cout << getCurrentTime() << KCYN
		<< "@FILE : " << file << std::endl;
      std::cout << getCurrentTime() << KCYN
		<< "@FUNCTION : " << func << "()" << std::endl;
      std::cout << KNRM;
    }
}

void		Debug::msg(const std::string& msg)
{
  if (isEnable())
    std::cout << getCurrentTime()
	      << KMAG << "@MSG : " << msg 
	      << std::endl << KNRM;
}

void		Debug::title(const std::string& title,
			     const std::string& color)
{
  if (isEnable())
    {
      int	len_title	= strlen(title.c_str());
      int	diff		= 54 - len_title;
      int	marge		= diff / 2;
      int	i		= -1;

      std::cout << std::endl << color;
      while (++i < marge)
	std::cout << "-";
      std::cout << " " << title;
      
      i = -1;
      std::cout << " ";
      while (++i < marge)
	std::cout << "-";

      if (len_title % 2 != 0)
      	std::cout << "-" << std::endl;
      else
      	std::cout << " " << std::endl;
      std::cout << KNRM << std::endl;
    }
}

bool		Debug::isEnable()
{
  return (_enabled);
}

std::string	Debug::getCurrentTime()
{
  time_t		now = time(0);
  struct tm		tstruct;
  char			buff[80];
  std::ostringstream	format;

  format << KMAG << "[" 
	 << KGRN << "%Y-%m-%d %X"
	 << KMAG "] ";

  tstruct = *localtime(&now);
  strftime(buff, sizeof(buff), format.str().c_str(), &tstruct);
  
  return (std::string(buff));
}
