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
	char buf[DATA_BUFFER];	//���ܻ����� 
	struct sockaddr_in ser;	//�������˵�ַ 
	if(args < 2){	//�жϲ��������Ƿ���ȷ 
		cout << "Usage: client [server IP address]" << endl;	//��������ʾ 
		return -1;
	}
	memset(buf, 0, sizeof(buf));	//��ʼ�����ջ����� 
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
		cout << "Failed to load Winsock." << endl;	//Winsocl��ʼ������ 
		return -1;
	}
	ser.sin_family = AF_INET;	//��ʼ����������ַ��Ϣ 
	ser.sin_port = htons(iPort);	//�˿�ת��Ϊ�����ֽ��� 
	ser.sin_addr.s_addr = inet_addr(argc[1]);	//IP��ַת��Ϊ�����ֽ���
	sClient = socket(AF_INET, SOCK_STREAM, 0);	//�����ͻ�����ʽ�׽���
	if(sClient == INVALID_SOCKET){
		cout << "socket() Failed:" << WSAGetLastError() << endl;
		return -1;
	}
	//������������˽���TCP���� 
	if(connect(sClient, (struct sockaddr*)&ser, sizeof(ser)) == INVALID_SOCKET){
		cout << "connect() Failed:" << WSAGetLastError() << endl;
		return -1;
	}else{
		iLen = recv(sClient, buf, sizeof(buf), 0);	//�ӷ������˽������� 
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
