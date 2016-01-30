#pragma once

#include 	<iostream>
#include 	<string>

class 			Protocole
{
public:
	Protocole();
	~Protocole();

	int 		send(int, const char *);

	/*
	*			CLient -> Server
	*/

	int 		connect(int sock);
	int 		sendLogin(int sock, std::string login);
	int 		createRoom(int sock, std::string createRoom);
	int 		listRooms(int sock);
	int 		joinRoom(int sock, std::string joinRoom);
	int 		destroyRoom(int sock, std::string destroyRoom);
	int 		setSenario(int sock, std::string setSenario);
	int 		lauchGame(int sock, int &lauchGame);
	int 		sendPlayerInformations();

	/*
	*			Server -> Client
	*/

	int 		getMonsters();
};