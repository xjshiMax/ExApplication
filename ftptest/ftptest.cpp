// ftptest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../../libseabase/ExAppOnbase/include/ExftpClient.h"
//static int inta=1;
using namespace SEABASE;
static const string f()
{
    string temp="ko";
    return "Test_"+temp;
}
class base
{
public:
    virtual void chang(){printf("this is class base change\n");};
};
class baseb
{
public:
    virtual void temp(){};
};
class A:public baseb,public base
{
public:
    virtual void chang()
    {
        printf("this is class A change\n");
    }
};
class B
{
public:
    virtual void chang()
    {
        printf("this is class B change\n");
    }
};
class C:public A,public B
{
public:
    void change();
};
int main(int argc, char* argv[])
{
#if 0
    ExftpClient ftpclient;
    ftpclient.FTP_InitParam("xjshi","863807076","ftp://172.28.71.53");
    FtpFile structfile;
    structfile.filename="test.jpg";
    //ftpclient.FTP_DownLoadFile((void*)&structfile,"newfile/src.jpg");
    ftpclient.FTP_UpLoadFile("newfile/updata.jpg","test.jpg",3000);
#endif
//     string s1="zhangshan "+f()+" lisi";
//     printf("inta=%d\n",inta);
//     printf("%s\n",s1);
    baseb *p =new A;
    base *pp =dynamic_cast<base*>(p);
    pp->chang();

	return 0;
}

