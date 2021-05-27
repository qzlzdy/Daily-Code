#pragma comment(lib, "ws2_32.lib")
#include <Winsock2.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

const int DATA_BUFFER = 1024;

using namespace std;

int main(int args, char **argc){
	WSADATA wsaData;
	SOCKET sClient;
	int iPort = 2333;
	int iLen;	//从服务器端接收的数据长度 
	char buf[DATA_BUFFER];	//接受缓冲区 
	struct sockaddr_in ser;	//服务器端地址 
	if(args < 2){	//判断参数输入是否正确 
		cout << "Usage: client [server IP address]" << endl;	//命令行提示 
		return -1;
	}
	memset(buf, 0, sizeof(buf));	//初始化接收缓冲区 
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
		cout << "Failed to load Winsock." << endl;	//Winsocl初始化错误 
		return -1;
	}
	ser.sin_family = AF_INET;	//初始化服务器地址信息 
	ser.sin_port = htons(iPort);	//端口转换为网络字节序 
	ser.sin_addr.s_addr = inet_addr(argc[1]);	//IP地址转换为网络字节序
	sClient = socket(AF_INET, SOCK_STREAM, 0);	//创建客户端流式套接字
	if(sClient == INVALID_SOCKET){
		cout << "socket() Failed:" << WSAGetLastError() << endl;
		return -1;
	}
	//请求与服务器端建立TCP连接 
	if(connect(sClient, (struct sockaddr*)&ser, sizeof(ser)) == INVALID_SOCKET){
		cout << "connect() Failed:" << WSAGetLastError() << endl;
		return -1;
	}else{
		iLen = recv(sClient, buf, sizeof(buf), 0);	//从服务器端接受数据 
		if(iLen == 0){
			return -1;
		}else if(iLen == SOCKET_ERROR){
			cout << "recv() Failed:" << WSAGetLastError() << endl;
			return -1;	
		}else{
			cout << "recv() data from server:" << string(buf) << endl;
		}
	}
	closesocket(sClient);
	WSACleanup();
	return 0;	
}
