#pragma once

#include 	<iostream>
#include 	<string>
#include 	"Protocole.hh"

#ifdef _WIN32
#include <process.h>
#include "SocketTCPWin.hh"
#include "SocketUDPWin.hh"
#else // UNIX
#include "SocketTCPUnix.hh"
#include "SocketUDPUnix.hh"
#endif

class 			NetworkController
{
public:
	NetworkController();
	~NetworkController();

	int 		run();

	bool		getLauchGame() const;

private:
	bool 				_lauchGame;
	Protocole 			*_protocole;

#ifdef _WIN32
	SocketTCPWin	*_clientTCP;
	SocketUDPWin	*_clientUDP;
#else  //UNIX
	SocketTCPUnix	*_clientTCP;
	SocketUDPUnix	*_clientUDP;
#endif

};