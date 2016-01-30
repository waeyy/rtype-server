//
// Main.cpp for  in /home/soidik_d/Semestre_05/cpp/rtype/sources
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Thu Nov 19 17:07:02 2015 SOIDIKI Djamil
// Last update Sun Jan  3 14:24:09 2016 SOIDIKI Djamil
//

#include	<iostream>
#include	"../modules/debug/Debug.hh"
#include	"../modules/exception/Exception.hh"
#include	"../modules/network/USocket.hh"
#include	"../modules/network/UExchange.hh"
#include	"../modules/network/Packet.hh"
#include	"../modules/thread/UThread.hh"
#include	"../modules/thread/UMutex.hh"
#include	"../modules/thread/Pool.hh"
#include	"../includes/Server.hh"

int		main()
{
  try
    {
      //      DEBUG_ENABLE();
      DEBUG_FILE_FUNC_INFO();
      
      DEBUG_MSG("rtype running...");

      Server	_server;
      
      _server.run();
    }
  catch (const Exception_::Exception& e)
    {
      std::cout << e.what() << std::endl;
    }
  return (0);
}
