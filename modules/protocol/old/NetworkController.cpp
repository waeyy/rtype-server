#include "../includes/NetworkController.hh"

NetworkController::NetworkController()
{
#ifdef _WIN32
	_clientTCP = new SocketTCPWin();
	_clientUDP = new SocketUDPWin();
	std::cout << "\n** Running in Windows env **\n" << std::endl;
#else  //UNIX
	_clientTCP = new SocketTCPUnix();
	_clientUDP = new SocketUDPUnix();
	std::cout << "\n** Running in UNIX env **\n" << std::endl;
#endif
	_lauchGame = 0;
}

NetworkController::~NetworkController()
{
}

int 		NetworkController::run()
{
	std::cout << "run here." << std::endl;

	_clientTCP->initClient();
	_protocole->connect(_clientTCP->getSock());
	_protocole->sendLogin(_clientTCP->getSock(), "ZULU");
	_clientTCP->exchangeClient();

	return 0;
}

bool 		NetworkController::getLauchGame() const
{
	return (this->_lauchGame);
}
