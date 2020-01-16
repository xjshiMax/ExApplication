// xdrfile.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <rpc/rpc.h>
#include "XDR_V1.0.9/xdrSLE.h"

int main(int argc, char* argv[])
{

     FILE* pFile = fopen("in11.txt","ab+");
     XDR xdr;
     //xdrstdio_create(&xdr,pFile,XDR_ENCODE);

     xdrstdio_create(&xdr,pFile,XDR_DECODE);  //����
     SLEDataFile_t originfile;
     memset(&originfile,0,sizeof(SLEDataFile_t));
       xdr_SLEDataFile_t(&xdr,&originfile);
     SLEDataFile_t Header;
     Header.DeviceID=0x12;
     Header.FileCreationTime=122222;
     Header.FileHeaderTag=2;   //��ʾһ��ͨ����
     Header.FileTag=1;
     Header.MD5Value.MD5Tag[0]=0x12345678;
     //���ݲ���
     Header.SLEMessages.TransactionTag=1; //����Ʊ
#define MAXLEN 100

     Header.SLEMessages.SLEMessage_t_u.YPTUD.YPTUD_len=MAXLEN;  //����������Ҳ�����鳤��
     Header.SLEMessages.SLEMessage_t_u.YPTUD.YPTUD_val=new struct SLEUDMSG_t[MAXLEN];
     struct SLEUDMSG_t*pudmsg=Header.SLEMessages.SLEMessage_t_u.YPTUD.YPTUD_val;
     //������Ϣ
     pudmsg[0].UDComm.BusinessDay=0x01;
     pudmsg[0].UDComm.DeviceID=0x01;
     pudmsg[0].UDComm.LineID=0x01;
     pudmsg[0].UDComm.ModeCode=0x01;
     pudmsg[0].UDComm.SAMInfo.SAMID[0]=0x01;
     pudmsg[0].UDComm.SpecialDateType=0x01;
     pudmsg[0].UDComm.StationID=0x01;
     pudmsg[0].UDComm.TransactionDateTime=0x01;
     pudmsg[0].UDComm.TransactionServiceProvider=0x01;
     pudmsg[0].UDComm.UDSN=0x01;
     //������Ϣ
     pudmsg[0].UDData.TransactionType=1;  //����Ʊ/��վƱ����
         //����Ʊ������Ϣ
     pudmsg[0].UDData.SLEUD_t_u.SJTSale.SJTSale.PaymentModeCode=0x01; // ֧����ʽ
     pudmsg[0].UDData.SLEUD_t_u.SJTSale.SJTSale.OriginalTransactionValue=4; // Ԥ�ս��
     pudmsg[0].UDData.SLEUD_t_u.SJTSale.SJTSale.InsertValue=4;//������
     pudmsg[0].UDData.SLEUD_t_u.SJTSale.SJTSale.TransactionValue=4;//���ν��׽��
     pudmsg[0].UDData.SLEUD_t_u.SJTSale.SJTSale.TVMChangeAmount=0;//ʵ��������
     pudmsg[0].UDData.SLEUD_t_u.SJTSale.SJTSale.LanguageBit=0x01;//��������ѡ��
     pudmsg[0].UDData.SLEUD_t_u.SJTSale.SJTSale.ContainerID=1;  //Ʊ��ID

     pudmsg[0].UDData.SLEUD_t_u.SJTSale.TicketComm.TicketStatus=1;//Ʊ��״̬
     pudmsg[0].UDData.SLEUD_t_u.SJTSale.TicketComm.TicketPhyID.TicketPhyID[0]=0x01;//����ID
     pudmsg[0].UDData.SLEUD_t_u.SJTSale.TicketComm.TicketType=30;  //Ʊ������ ����Ʊ
    //  pudmsg[0].UDData.SLEUD_t_u.SJTSale.TicketComm.MediaType

      pudmsg[0].UDData.SLEUD_t_u.SJTSale.TicketInitComm.BatchInitCode=0x01; //���κ�����
      pudmsg[0].UDData.SLEUD_t_u.SJTSale.TicketInitComm.FirstInitDate= 111111;  //���ڣ�����2000��һ��һ�յ�����
      pudmsg[0].UDData.SLEUD_t_u.SJTSale.TicketInitComm.InitServiceProvider=1;  //�����̱�������
     xdr_SLEDataFile_t(&xdr,&Header);
     xdr_destroy(&xdr);
     fclose(pFile);
     delete[]pudmsg;
	return 0;
}

