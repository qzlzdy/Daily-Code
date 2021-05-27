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
	char recvbuf[DATA_BUFFER];	//接受缓冲区 
	string sendbuf = "This is Client.";
	struct sockaddr_in ser;	//服务器端地址 
	if(args < 2){	//判断参数输入是否正确 
		cout << "Usage: client [server IP address]" << endl;	//命令行提示 
		return -1;
	}
	memset(recvbuf, 0, sizeof(recvbuf));	//初始化接收缓冲区 
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
		cout << "Failed to load Winsock." << endl;	//Winsocl初始化错误 
		return -1;
	}
	ser.sin_family = AF_INET;	//初始化服务器地址信息 
	ser.sin_port = htons(iPort);	//端口转换为网络字节序 
	ser.sin_addr.s_addr = inet_addr(argc[1]);	//IP地址转换为网络字节序
	sClient = socket(AF_INET, SOCK_DGRAM, 0);	//创建客户端数据报式套接字
	if(sClient == INVALID_SOCKET){
		cout << "socket() Failed:" << WSAGetLastError() << endl;
		return -1;
	}
	iLen = sizeof(ser);
	int iSend = sendto(sClient, sendbuf.c_str(), sendbuf.length(), 0, (struct sockaddr*)&ser, iLen);
	if(iSend == SOCKET_ERROR){
		cout << "sendto() Failed:" << WSAGetLastError() << endl;
		return -1;
	}else if(iSend == 0){
		return -1;	
	}else{
		cout << "sendto() byte:" << iSend << endl;	//输出发送成功字节数 
	}
	recvfrom(sClient, recvbuf, sizeof(recvbuf), 0, (struct sockaddr*)&ser, &iLen);	//从服务器端接受数据 
	if(iLen == 0){
		return -1;
	}else if(iLen == SOCKET_ERROR){
		cout << "recvfrom() Failed:" << WSAGetLastError() << endl;
		return -1;	
	}else{
		cout << "recvfrom() data from server:" << string(recvbuf) << endl;
	}
	closesocket(sClient);
	WSACleanup();
	return 0;	
}
