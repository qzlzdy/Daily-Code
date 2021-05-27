#pragma comment(lib, "ws2_32.lib")
#include <Winsock2.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const int DEFAULT_PORT = 2333;	//����Ķ˿� 

int main(){
	int iPort = DEFAULT_PORT;
	WSADATA wsaData;
	SOCKET sListen, sAccept;
	int iLen;	//�ͻ�����ַ���� 
	int iSend; 	//�������ݳ���
	string buf = "This is server.";	//���͸��ͻ�����Ϣ 
	struct sockaddr_in ser, cli;	//�������Ϳͻ��ĵ�ַ
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
		cout << "Failed to load Winsock." << endl;	//Windows��ʼ������ 
		return -1;
	}
	sListen = socket(AF_INET, SOCK_STREAM, 0);	//�������������׽��� 
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
	if(listen(sListen, 5) == SOCKET_ERROR){	//�������״̬ 
		cout << "listen() Failed:" << WSAGetLastError() << endl;
		return -1;	
	}
	iLen = sizeof(cli);	//��ʼ���ͻ��˵�ַ����;
	while(true){	//����ѭ���ȴ��ͻ����������� 
		sAccept = accept(sListen, (struct sockaddr *)&cli, &iLen);
		if(sAccept == INVALID_SOCKET){
			cout << "accept() Failed:" << WSAGetLastError() << endl;
			return -1;	
		}
		cout << "Acceptd client IP:[" << inet_ntoa(cli.sin_addr);
		cout << "],port:[" << ntohs(cli.sin_port) << "]" << endl;	//����ͻ���IP��ַ�Ͷ˿ں� 
		iSend = send(sAccept, buf.c_str(), buf.length(), 0);	//���ͻ��˷�����Ϣ
		if(iSend == SOCKET_ERROR){
			cout << "send() Failed:" << WSAGetLastError() << endl;
			break;
		}else if(iSend == 0){
			break;	
		}else{
			cout << "send() byte:" << iSend << endl;	//������ͳɹ��ֽ��� 
		}
		closesocket(sAccept);
	}
	closesocket(sListen);	//�ر�socket 
	WSACleanup();	//��ֹWindows DLL��ʹ�� 
	return 0;	
}
