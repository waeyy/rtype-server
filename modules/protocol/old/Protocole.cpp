#include "../includes/Protocole.hh"
#ifdef _WIN32
#include "../includes/SocketTCPWin.hh"
#else
#include "../includes/SocketTCPUnix.hh"
#endif

Protocole::Protocole()
{
}

Protocole::~Protocole()
{
}

int 		Protocole::send(int sock, const char *string)
{
	#ifdef _WIN32
		SocketTCPWin::sendTo(sock, string);
	#else // UNIX
		SocketTCPUnix::sendTo(sock, string);
	#endif
	return 0;
}

int 		Protocole::connect(int sock)
{
	std::string 	sendConnect;

	sendConnect = "01;\n";
	send(sock, sendConnect.c_str());
	return 0;
}

int 				Protocole::sendLogin(int sock, std::string login)
{
	std::string 	sendLogin;

	sendLogin = "02;" + login + ";\n";
	send(sock, sendLogin.c_str());
	return 0;
}

int 		Protocole::createRoom(int sock, std::string createRoom)
{
	std::string 	sendcreateRoom;

	sendcreateRoom = "03;" + createRoom + ";\n";
	send(sock, sendcreateRoom.c_str());
	return 0;
}

int 		Protocole::listRooms(int sock)
{
	std::string 	sendListRooms;

	sendListRooms = "04;\n";
	send(sock, sendListRooms.c_str());
	return 0;
}

int 		Protocole::joinRoom(int sock, std::string joinRoom)
{
	std::string 	sendjoinRoom;

	sendjoinRoom = "05;" + joinRoom + ";\n";
	send(sock, sendjoinRoom.c_str());
	return 0;
}

int 		Protocole::destroyRoom(int sock, std::string destroyRoom)
{
	std::string 	sendDestroyRoom;

	sendDestroyRoom = "06;" + destroyRoom + ";\n";
	send(sock, sendDestroyRoom.c_str());
	return 0;
}

int 		Protocole::setSenario(int sock, std::string setSenario)
{
	std::string 	sendSetSenario;

	sendSetSenario = "07;" + setSenario + ";\n";
	send(sock, sendSetSenario.c_str());
	return 0;
}

int 		Protocole::lauchGame(int sock, int &lauchGame)
{
	std::string 	sendLauchGame;

	lauchGame = 1;
	sendLauchGame = "08;\n";
	send(sock, sendLauchGame.c_str());
	return 0;
}

int 		Protocole::sendPlayerInformations()
{
	return 0;
}