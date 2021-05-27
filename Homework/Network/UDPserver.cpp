#pragma comment(lib, "ws2_32.lib")
#include <Winsock2.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const int DEFAULT_PORT = 2333;	//服务的端口 
const int DATA_BUFFER = 1024;

int main(){
	int iPort = DEFAULT_PORT;
	WSADATA wsaData;
	SOCKET sListen;
	int iLen;	//客户机地址长度 
	int iSend; 	//发送数据长度
	string sendbuf = "This is server.";	//发送给客户的信息 
	struct sockaddr_in ser, cli;	//服务器和客户的地址
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
		cout << "Failed to load Winsock." << endl;	//Windows初始化错误 
		return -1;
	}
	sListen = socket(AF_INET, SOCK_DGRAM, 0);	//创建服务器端套接字 
	if(sListen == INVALID_SOCKET){
		cout << "socket() Failed:" << WSAGetLastError() << endl;
		return -1;	
	}
	//初始化服务器端地址
	ser.sin_family = AF_INET;	//使用IP地址簇
	ser.sin_port = htons(iPort);	//主机序端口号转为网络字节序端口号
	ser.sin_addr.s_addr = htons(INADDR_ANY);	//主机序IP地址转换为网络字节序主机地址
												//使用系统指定IP地址INADDR_ANY
	if(bind(sListen, (LPSOCKADDR)&ser, sizeof(ser)) == SOCKET_ERROR){
		//套接字与地址绑定 
		cout << "bind() Failed:" << WSAGetLastError() << endl;
		return -1;	
	}
	iLen = sizeof(cli);	//初始化客户端地址长度;
	char recvbuf[DATA_BUFFER];
	while(true){	//进入循环等待客户的连接请求 
		recvfrom(sListen, recvbuf, DATA_BUFFER, 0, (struct sockaddr*)&cli, &iLen);
		if(iLen == 0){
			break;
		}else if(iLen == SOCKET_ERROR){
			cout << "recvfrom() Failed:" << WSAGetLastError() << endl;
			break;	
		}else{
			cout << "recvfrom() data from client:" << string(recvbuf) << endl;
		}
		
		iSend = sendto(sListen, sendbuf.c_str(), sendbuf.length(), 0, (struct sockaddr*)&cli, iLen);
		if(iSend == SOCKET_ERROR){
			cout << "send() Failed:" << WSAGetLastError() << endl;
			break;
		}else if(iSend == 0){
			break;	
		}else{
			cout << "send() byte:" << iSend << endl;	//输出发送成功字节数 
		}
	}
	closesocket(sListen);	//关闭socket 
	WSACleanup();	//终止Windows DLL的使用 
	return 0;	
}
