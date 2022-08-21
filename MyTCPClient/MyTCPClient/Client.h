//Reference source: www.youtube.com/watch?v=TP5Q0cs6uNo
#include<WinSock2.h>
#include<iostream>
//#pragma comment(lib,"ws2_32.lib")
# pragma warning(disable:4996)
using namespace std;
#define BUFFER_SIZE 256
#define PORT 8080

class Client
{
private:
	WSADATA Winsockdata;
	SOCKET TCPClientSocket;
	struct sockaddr_in TCPServerAdd;
	char RecvBuffer[BUFFER_SIZE];
	int iBufferSize = BUFFER_SIZE;

public:
	Client();
	Client(string destiAdress);
	void isConnect();
	char* receiveData();
	void sendData(char* data);
	int getBufferSize();
	void setBufferSize(int newBufferSize);
	~Client();
};