#pragma comment(lib, "ws2_32.lib")
#include <Winsock2.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const int DEFAULT_PORT = 2333;	//����Ķ˿� 
const int DATA_BUFFER = 1024;

int main(){
	int iPort = DEFAULT_PORT;
	WSADATA wsaData;
	SOCKET sListen;
	int iLen;	//�ͻ�����ַ���� 
	int iSend; 	//�������ݳ���
	string sendbuf = "This is server.";	//���͸��ͻ�����Ϣ 
	struct sockaddr_in ser, cli;	//�������Ϳͻ��ĵ�ַ
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
		cout << "Failed to load Winsock." << endl;	//Windows��ʼ������ 
		return -1;
	}
	sListen = socket(AF_INET, SOCK_DGRAM, 0);	//�������������׽��� 
	if(sListen == INVALID_SOCKET){
		cout << "socket() Failed:" << WSAGetLastError() << endl;
		return -1;	
	}
	//��ʼ���������˵�ַ
	ser.sin_family = AF_INET;	//ʹ��IP��ַ��
	ser.sin_port = htons(iPort);	//������˿ں�תΪ�����ֽ���˿ں�
	ser.sin_addr.s_addr = htons(INADDR_ANY);	//������IP��ַת��Ϊ�����ֽ���������ַ
												//ʹ��ϵͳָ��IP��ַINADDR_ANY
	if(bind(sListen, (LPSOCKADDR)&ser, sizeof(ser)) == SOCKET_ERROR){
		//�׽������ַ�� 
		cout << "bind() Failed:" << WSAGetLastError() << endl;
		return -1;	
	}
	iLen = sizeof(cli);	//��ʼ���ͻ��˵�ַ����;
	char recvbuf[DATA_BUFFER];
	while(true){	//����ѭ���ȴ��ͻ����������� 
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
			cout << "send() byte:" << iSend << endl;	//������ͳɹ��ֽ��� 
		}
	}
	closesocket(sListen);	//�ر�socket 
	WSACleanup();	//��ֹWindows DLL��ʹ�� 
	return 0;	
}
