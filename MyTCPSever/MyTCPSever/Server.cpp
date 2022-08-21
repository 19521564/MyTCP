#include "Server.h"
# pragma warning(disable:26495)
Server::Server() {
}

Server::Server(string destiAdress)
{
	//WSAStartup Fun

	int iWsaStartup = WSAStartup(MAKEWORD(2, 2), &Winsockdata);
	if (iWsaStartup != 0)
	{
		cout << "WSAStartup Failed" << endl;
		exit(0);
	}
	cout << "WSAStartup Success" << endl;
	// Fill the structure

	TCPServerAdd.sin_family = AF_INET;
	TCPServerAdd.sin_addr.s_addr = inet_addr(destiAdress.c_str());
	TCPServerAdd.sin_port = htons(PORT);
}

void Server::isConnect()
{
	// Socket Creation-------

	TCPServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (TCPServerSocket == INVALID_SOCKET)
	{
		cout << "TCP Server Socket Creation failed" << WSAGetLastError() << endl;
		exit(0);
	}
	int iBind = bind(TCPServerSocket, (SOCKADDR*)&TCPServerAdd, sizeof(TCPServerAdd));
	if (iBind == SOCKET_ERROR)
	{
		cout << "Binding Failed &Error No->" << WSAGetLastError() << endl;

	}
	cout << "Binding success" << endl;

	// Listen fun------

	int iListen = listen(TCPServerSocket, 2);
	if (iListen == SOCKET_ERROR)
	{
		cout << "Listen fun failed &error No->" << WSAGetLastError();
	}
	cout << "Listen fun success" << endl;

	// Accept--

	sAcceptSocket = accept(TCPServerSocket, (SOCKADDR*)&TCPClientAdd, &iTCPClientAdd);
	if (sAcceptSocket == INVALID_SOCKET)
	{
		cout << "Accept failed & Error No ->" << WSAGetLastError() << endl;
	}
	cout << "Accept fun success" << endl;

}

void Server::setBufferSize(int newBufferSize)
{
	iBufferSize = newBufferSize;
}

int Server::getBufferSize()
{
	return iBufferSize;
}

void Server::sendData(char* data)
{
	//Send Data to the client
	int iSend = send(sAcceptSocket, data, iBufferSize, 0);
	if (iSend == SOCKET_ERROR)
	{
		cout << "Sending Failed & Error No->" << WSAGetLastError() << endl;
	}
	cout << "Send fun success" << endl;

}

char* Server::receiveData()
{
	//Recv Data from Client
	int iRecv = recv(sAcceptSocket, RecvBuffer, iBufferSize, 0);
	if (iRecv == SOCKET_ERROR)
	{
		cout << "Receiving Failed & Error No->" << WSAGetLastError() << endl;
	}
	cout << "Receive fun success" << endl;

	return RecvBuffer;
}

Server::~Server()
{
	// Close Socket

	int iCloseSocket = closesocket(TCPServerSocket);

	if (iCloseSocket == SOCKET_ERROR)
	{
		cout << "Closing Failed & Error No->" << WSAGetLastError() << endl;
	}
	cout << "Cleanup fun success" << endl;
	system("PAUSE");
}
