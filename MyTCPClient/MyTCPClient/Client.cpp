#include "Client.h"
# pragma warning(disable:26495)

Client::Client() {
}

Client::Client(string detiAdress)
{
	//WSAStartup Fun

	int iWsaStartup = WSAStartup(MAKEWORD(2, 2), &Winsockdata);
	if (iWsaStartup != 0)
	{
		cout << "WSAStartup Failed" << endl;
	}
	cout << "WSAStartup Success" << endl;

	// Socket Creation

	TCPClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (TCPClientSocket == INVALID_SOCKET)
	{
		cout << "TCP Client Socket Creation failed" << WSAGetLastError() << endl;
	}
	cout << "TCP client socket creation success"<<endl;
	// Fill the structure

	TCPServerAdd.sin_family = AF_INET;
	TCPServerAdd.sin_addr.s_addr = inet_addr(detiAdress.c_str());
	TCPServerAdd.sin_port = htons(PORT);
}

void Client::isConnect()
{
	// STEP-4 Connect fun

	int iConnect = connect(TCPClientSocket, (SOCKADDR*)&TCPServerAdd, sizeof(TCPServerAdd));
	if (iConnect == SOCKET_ERROR)
	{
		cout << "Connection failed & Error No ->" << WSAGetLastError() << endl;
	}
	cout << "Connection success" << endl;
}

char* Client::receiveData()
{
	// STEP -5 Recv Data from Server

	int iRecv = recv(TCPClientSocket, RecvBuffer, iBufferSize, 0);
	if (iRecv == SOCKET_ERROR)
	{
		cout << "Receiving Failed & Error No->" << WSAGetLastError() << endl;
	}
	cout << "Receive fun success" << endl;
	return RecvBuffer;
}

void Client::sendData(char* data)
{
	// STEP-6 Send Data to the server

	int iSend = send(TCPClientSocket, data, iBufferSize, 0);
	if (iSend == SOCKET_ERROR)
	{
		cout << "Sending Failed & Error No->" << WSAGetLastError() << endl;
	}
	cout << "Data sending success" << endl;
}

Client::~Client()
{
	int iCloseSocket = closesocket(TCPClientSocket);
	if (iCloseSocket == SOCKET_ERROR)
	{
		cout << "Closing Failed & Error No->" << WSAGetLastError() << endl;
	}
	cout << "Closing Socket success" << endl;
}

void Client::setBufferSize(int newBufferSize) {
	iBufferSize = newBufferSize;
}

int Client::getBufferSize() {
	return iBufferSize;
}