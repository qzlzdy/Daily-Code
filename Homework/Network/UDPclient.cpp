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
	int iLen;	//�ӷ������˽��յ����ݳ��� 
	char recvbuf[DATA_BUFFER];	//���ܻ����� 
	string sendbuf = "This is Client.";
	struct sockaddr_in ser;	//�������˵�ַ 
	if(args < 2){	//�жϲ��������Ƿ���ȷ 
		cout << "Usage: client [server IP address]" << endl;	//��������ʾ 
		return -1;
	}
	memset(recvbuf, 0, sizeof(recvbuf));	//��ʼ�����ջ����� 
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
		cout << "Failed to load Winsock." << endl;	//Winsocl��ʼ������ 
		return -1;
	}
	ser.sin_family = AF_INET;	//��ʼ����������ַ��Ϣ 
	ser.sin_port = htons(iPort);	//�˿�ת��Ϊ�����ֽ��� 
	ser.sin_addr.s_addr = inet_addr(argc[1]);	//IP��ַת��Ϊ�����ֽ���
	sClient = socket(AF_INET, SOCK_DGRAM, 0);	//�����ͻ������ݱ�ʽ�׽���
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
		cout << "sendto() byte:" << iSend << endl;	//������ͳɹ��ֽ��� 
	}
	recvfrom(sClient, recvbuf, sizeof(recvbuf), 0, (struct sockaddr*)&ser, &iLen);	//�ӷ������˽������� 
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
