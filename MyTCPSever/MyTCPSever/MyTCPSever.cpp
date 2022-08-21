#include "server.h"
#include<regex>
#include <sys/stat.h>
#pragma comment(lib,"ws2_32.lib")
//#pragma comment(lib,"ibwsock32.a")
#pragma warning(disable:4996)
#include <sys\types.h> 
#include <sys\stat.h> 
#include<fstream>
#include <algorithm>

int main(int argc, char* argv[])
{
	string destiAdress = "127.0.0.1";
	Server server(destiAdress);
	server.isConnect();
	return 0;
}