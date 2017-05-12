#include "stdafx.h"
//#pragma once

#include <Windows.h>
#include <io.h>
#include "com_port.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

#define BUFSIZE 28
unsigned char bufrd[BUFSIZE];	//������� �����
HANDLE COMport;					//���������� �����
OVERLAPPED overlapped;			//���  ������ 
OVERLAPPED overlappedwr;		//���  ������
unsigned long counter;			//������� �������� ������, ���������� ��� ������ �������� �����
bool Connected = true; 
/*
ERROR
1  - ok
-1 - ������ �������� COMport'a
-2 - o����� ���������� ��������

*/
int COMOpen()
{
 DCB dcb;               //��������� ��� ����� ������������� ����� DCB
 
 COMport = CreateFile(L"\\\\.\\\COM3",
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
		//FILE_FLAG_OVERLAPPED,
        FILE_ATTRIBUTE_NORMAL,
        0);
 if (COMport == INVALID_HANDLE_VALUE) 
	{	
		//MessageBox(0,TEXT("Cannot open the port"),TEXT("Error"),MB_ICONEXCLAMATION);
		Connected = FALSE;
		return -1;
	}
 else
 { 
		dcb.BaudRate = CBR_115200;
		dcb.fBinary = true;     /* Binary Mode (skip EOF check)    */
		dcb.fParity = false;     /* Enable parity checking          */
		dcb.fOutxCtsFlow = false; /* CTS handshaking on output       */
		dcb.fOutxDsrFlow = false; /* DSR handshaking on output       */
		dcb.fDtrControl = DTR_CONTROL_ENABLE;  /* DTR Flow control    */
		dcb.fDsrSensitivity = false; /* DSR Sensitivity              */
		dcb.fTXContinueOnXoff = true; /* Continue TX when Xoff sent */
		dcb.fOutX = false;       /* Enable output X-ON/X-OFF        */
		dcb.fInX = false;        /* Enable input X-ON/X-OFF         */
		dcb.fErrorChar = 0;  /* Enable Err Replacement          */
		dcb.fNull = false;       /* Enable Null stripping           */
		dcb.fRtsControl = RTS_CONTROL_DISABLE;  /* Rts Flow control       */
		dcb.fAbortOnError = true; // false; /* Abort all reads and writes on Error */
		dcb.ByteSize = 8;        /* Number of bits/byte, 4-8        */
		dcb.Parity = NOPARITY;          /* 0-4=None,Odd,Even,Mark,Space    */
		dcb.StopBits = ONESTOPBIT;        /* 0,1,2 = 1, 1.5, 2               */

		COMMTIMEOUTS ComTimeouts;
		Connected =(bool) GetCommTimeouts (COMport, &ComTimeouts);
		if (!Connected)
			{
			// dwError = GetLastError();
			//MessageBox(0,TEXT("Cannot get timeouts"),TEXT("Error"),MB_ICONEXCLAMATION);
			}
        ComTimeouts.ReadIntervalTimeout = 0;
        ComTimeouts.ReadTotalTimeoutConstant = 100;
        ComTimeouts.ReadTotalTimeoutMultiplier = 1;
        ComTimeouts.WriteTotalTimeoutConstant = 100;
        ComTimeouts.WriteTotalTimeoutMultiplier = 1;

            if(!SetCommTimeouts(COMport, &ComTimeouts))
            {
                //cout << "Cann't SetCommTimeouts!\n";
                return 0;
            }
           // cout << "SetCommTimeouts\n";

 }
		if (SetCommState(COMport, &dcb))
		{
		return 1;		
		}
		else
			return -2;
}

void COMClose()
{  
 CloseHandle(COMport);          //������� ����
 COMport=0;						//�������� ���������� ��� ����������� �����
}

//������� ��������� ���� ������ �� COM-�����
 unsigned char* ReadThread()
{
 COMSTAT comstat;		//��������� �������� ��������� �����, � ������ ��������� ������������ ��� ����������� ���������� �������� � ���� ������
 DWORD btr, temp,mask, signal;	//���������� temp ������������ � �������� ��������
 overlapped.hEvent = CreateEvent(NULL, true, true, NULL);	//������� ���������� ������-������� ��� ����������� ��������
  SetCommMask(COMport, EV_RXCHAR);                   	        //���������� ����� �� ������������ �� ������� ����� ����� � ����
 while(1)						//���� ����� �� ����� �������, ��������� ����
  {
   //cout<<"COM0 "<<endl;
   WaitCommEvent(COMport, &mask, &overlapped);               	//������� ������� ����� ����� (��� � ���� ������������� ��������)
   //cout<<"COM1 "<<endl;
   signal = WaitForSingleObject(overlapped.hEvent, INFINITE);	//������������� ����� �� ������� �����
    //cout<<"COM2 "<<endl;
   if(signal == WAIT_OBJECT_0)				        //���� ������� ������� ����� ���������
    {
     if(GetOverlappedResult(COMport, &overlapped, &temp, true)) //���������, ������� �� ����������� ������������� �������� WaitCommEvent
      if((mask & EV_RXCHAR)!=0)					//���� ��������� ������ ������� ������� �����
       {
        ClearCommError(COMport, &temp, &comstat);		//����� ��������� ��������� COMSTAT
        btr = comstat.cbInQue;                          	//� �������� �� �� ���������� �������� ������
        if(btr)                         			//���� ������������� ���� ����� ��� ������
        {
         ReadFile(COMport, bufrd, btr, &temp, &overlapped);     //��������� ����� �� ����� � ����� ���������
         counter+=btr;  //����������� ������� ������	
         return bufrd; 		//�������� ������� ��� ������ ������ �� ����� � � ����
        }
       }
    }
  }
 CloseHandle(overlapped.hEvent);		//����� ������� �� ������ ������� ������-�������
}

void WriteThread()
{
 DWORD temp;
 BYTE b=0;
 b='0';
 overlappedwr.hEvent = CreateEvent(NULL, true, true, NULL);   	 
 WriteFile(COMport, &b, 1, &temp,&overlappedwr); // �������� 0 � ����
 //cout<<"WriteFile "<<temp<<endl;
 CloseHandle(overlappedwr.hEvent);
}
//-----------------------------------------------------------------------
int Read(char* buf,DWORD len)
{
 if(!Connected)
        return 0;

 DWORD read=1;
 BYTE a=0;
 BYTE b=0;

 memset(buf,0,sizeof(BYTE)*len);
 b='0';
 WriteFile(COMport,&b,1,&read,0);

 b=0;
 memset(buf,0,sizeof(BYTE)*len);
 while(read>0)
 {
	b=0;
	ReadFile(COMport,&b,1,&read,0);
	if(b!=0xFF)
		continue;
	buf[0]=b;

	b=0;
	ReadFile(COMport,&b,1,&read,0);
	if(b!=0xFF)
		continue;
	buf[1]=b;

	b=0;
	ReadFile(COMport,&b,1,&read,0);
	if(b!=0xFF)
		continue;
	buf[2]=b;

	b=0;
	ReadFile(COMport,&b,1,&read,0);
	if(b!=0xFF)
		continue;
	buf[3]=b;

	b=0;
	break;
	}

    if(read==0)
	 return 0;

    for(DWORD i=4;i<len;i++)
	{
	 ReadFile(COMport,&b,1,&read,0);

	 if(read==0)
	 {
		read=i;
		break;
	 }
	 else
	 {
		read=i+1;
		buf[i]=b;
	 }
	}
 return read;
}
//-----------------------------------------------------------------------