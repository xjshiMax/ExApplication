// filetest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
#include "../../libseabase/base/include/xEFile.h"
using namespace SEABASE;
using namespace std;
class A
{
public:
    virtual void print(){printf("this is class A print\n");};
};
class B
{
public:
    virtual void print(){printf("this is class B print\n");}
};
class C:public A,public B
{
public:
    void see(){};
};
int main(int argc, char* argv[])
{
    C*cinst = new C;
    B*binst = cinst;
    binst->print();
    A*ainst = cinst;
    ainst->print();
   // vector<string> v_files;
  //  xEFile::search("E:/aaa-shi/afile*",v_files);
	return 0;
}

