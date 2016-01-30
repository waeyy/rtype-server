//
// Debug.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/debug
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Thu Nov 19 17:14:37 2015 SOIDIKI Djamil
// Last update Fri Dec 11 18:22:05 2015 SOIDIKI Djamil
//

#ifndef		_DEBUG_HH_
# define	_DEBUG_HH_

#include	<iostream>
#include	<sstream>
#include	<cstring>

namespace	Debugger {

#define		DEBUG_ENABLE()		Debugger::Debug::enable()
#define		DEBUG_DISABLE()		Debugger::Debug::disable()
#define		DEBUG_FILE_FUNC_INFO()	Debugger::Debug::ffinfo(__FILE__, __FUNCTION__)
#define		DEBUG_MSG(x)		Debugger::Debug::msg(x)

#define		KNRM	"\x1B[0m"
#define		KRED	"\x1B[31m"
#define		KGRN	"\x1B[32m"
#define		KYEL	"\x1B[33m"
#define		KBLU	"\x1B[34m"
#define		KMAG	"\x1B[35m"
#define		KCYN	"\x1B[36m"
#define		KWHT	"\x1B[37m"

  /*
   * Debug static class that provide a debug tools using macro
   *
   * To use it just include this file.
   *
   * - LIST OF MACROS AVAILABLE -
   * DEBUG_ENABLE() - Activate the debug tools
   * DEBUG_DISABLE() - Desactive the debug tools
   * DEBUG_FILE_FUNC_INFO() - Provide some informations about the current location of the function. Should be use a the start of each function
   * DEBUG_MSG(std::string) - Print a personal debug message 
   * 
   * @class Debug
   */
  class		Debug
  {
    
  private:
    static bool	_enabled;
  
  public:
    /*
     * Enable the debug tools
     *
     * @param	void
     * @return	void
     */
    static void	enable();
    
    /*
     * Disable the debug tools
     *
     * @param	void
     * @return	void
     */
    static void	disable();
    
    /* 
     * Display info bout the current file and current function
     *
     * @param	const std::string& current file
     * @param	const std::string& current function
     * @return	void
     */
    static void	ffinfo(const std::string& file, const std::string& func);
    
    /* 
     * Display debug message provided as parameter
     *
     * @param	const std::string& msg
     * @return	void
     */
    static void	msg(const std::string& msg);
    
    /*
     * Verify if the debug tools is enable
     * 
     * @param	void
     * @return	bool
     */
    static bool	isEnable();
    
  private:
    /* 
     * Display title debug message provided as parameter in personalised color
     * Length title can't be over 54 characters. 
     *
     * @param	const std::string& title
     * @param	const std::string& color
     * @return	void
     */
    static void	title(const std::string& title, const std::string& color);

    static std::string	getCurrentTime();
  };
}

#endif		/* _DEBUG_HH_ */
  
