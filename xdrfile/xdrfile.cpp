// xdrfile.cpp : 定义控制台应用程序的入口点。
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

     xdrstdio_create(&xdr,pFile,XDR_DECODE);  //解码
     SLEDataFile_t originfile;
     memset(&originfile,0,sizeof(SLEDataFile_t));
       xdr_SLEDataFile_t(&xdr,&originfile);
     SLEDataFile_t Header;
     Header.DeviceID=0x12;
     Header.FileCreationTime=122222;
     Header.FileHeaderTag=2;   //表示一卡通交易
     Header.FileTag=1;
     Header.MD5Value.MD5Tag[0]=0x12345678;
     //内容部分
     Header.SLEMessages.TransactionTag=1; //单程票
#define MAXLEN 100

     Header.SLEMessages.SLEMessage_t_u.YPTUD.YPTUD_len=MAXLEN;  //数据条数，也是数组长度
     Header.SLEMessages.SLEMessage_t_u.YPTUD.YPTUD_val=new struct SLEUDMSG_t[MAXLEN];
     struct SLEUDMSG_t*pudmsg=Header.SLEMessages.SLEMessage_t_u.YPTUD.YPTUD_val;
     //公共信息
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
     //交易信息
     pudmsg[0].UDData.TransactionType=1;  //单程票/出站票发售
         //单程票发售信息
     pudmsg[0].UDData.SLEUD_t_u.SJTSale.SJTSale.PaymentModeCode=0x01; // 支付方式
     pudmsg[0].UDData.SLEUD_t_u.SJTSale.SJTSale.OriginalTransactionValue=4; // 预收金额
     pudmsg[0].UDData.SLEUD_t_u.SJTSale.SJTSale.InsertValue=4;//插入金额
     pudmsg[0].UDData.SLEUD_t_u.SJTSale.SJTSale.TransactionValue=4;//本次交易金额
     pudmsg[0].UDData.SLEUD_t_u.SJTSale.SJTSale.TVMChangeAmount=0;//实际找零金额
     pudmsg[0].UDData.SLEUD_t_u.SJTSale.SJTSale.LanguageBit=0x01;//界面语言选择
     pudmsg[0].UDData.SLEUD_t_u.SJTSale.SJTSale.ContainerID=1;  //票箱ID

     pudmsg[0].UDData.SLEUD_t_u.SJTSale.TicketComm.TicketStatus=1;//票卡状态
     pudmsg[0].UDData.SLEUD_t_u.SJTSale.TicketComm.TicketPhyID.TicketPhyID[0]=0x01;//物理ID
     pudmsg[0].UDData.SLEUD_t_u.SJTSale.TicketComm.TicketType=30;  //票卡类型 单程票
    //  pudmsg[0].UDData.SLEUD_t_u.SJTSale.TicketComm.MediaType

      pudmsg[0].UDData.SLEUD_t_u.SJTSale.TicketInitComm.BatchInitCode=0x01; //批次号类型
      pudmsg[0].UDData.SLEUD_t_u.SJTSale.TicketInitComm.FirstInitDate= 111111;  //日期，距离2000年一月一日的天数
      pudmsg[0].UDData.SLEUD_t_u.SJTSale.TicketInitComm.InitServiceProvider=1;  //服务商编码类型
     xdr_SLEDataFile_t(&xdr,&Header);
     xdr_destroy(&xdr);
     fclose(pFile);
     delete[]pudmsg;
	return 0;
}

